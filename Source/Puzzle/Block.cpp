// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"
#include "Macros.h"
//#include "PuzzleGameModeBase.h"
#include "PuzzlePlayerController.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ABlock::ABlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	//making MyMesh a root component, so creating another mesh will put it under MyMesh
	RootComponent = MyMesh;
	MatZero = CreateDefaultSubobject<UMaterial>(TEXT("MatZero"));
	MatOne = CreateDefaultSubobject<UMaterial>(TEXT("MatOne"));
	MatTwo = CreateDefaultSubobject<UMaterial>(TEXT("MatTwo"));
	MatThree = CreateDefaultSubobject<UMaterial>(TEXT("MatThree"));
	MatFour = CreateDefaultSubobject<UMaterial>(TEXT("MatFour"));
	MatFive = CreateDefaultSubobject<UMaterial>(TEXT("MatFive"));
	MatSix = CreateDefaultSubobject<UMaterial>(TEXT("MatSix"));
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	//getallactorsofclass didn't work for me, so now every instance of this class will add itself to
	//an array in the gamemode class
	currentGM = Cast<APuzzleGameModeBase>(GetWorld()->GetAuthGameMode());
	if (currentGM != nullptr)
	{
		//adding blocks to the list in random order
		currentGM->AllBlocks.Insert(this, FMath::RandRange(0, currentGM->AllBlocks.Num()));
	}
	//MyMesh->SetMaterial(0, MatOne);
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlock::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (currentGM->GStart)
	{
		for (int i = 0; i < currentGM->AllBlocks.Num(); i++)
		{
			if (currentGM->AllBlocks[i] == this)
			{
				if (disabled)
				{
					return;
				}
				//prevent clicking the same block twice
				if (currentGM->comboCheck.Contains(this))
				{
					printX("already there return");
					return;
				}
				if (currentGM->comboCheck.Num() > 3)
				{
					printX("empty");
					currentGM->comboCheck.Empty();
				}

				if (currentGM->comboCheck.Num() == 0)
				{
					MyMesh->SetMaterial(0, currentGM->randMatHolder[i]);
					currentGM->comboCheck.Add(this);
					GetWorldTimerManager().SetTimer(TimerHandle, this, &ABlock::HideBlock, 1, false);
					ActiveMat = currentGM->randMatHolder[i];
					return;
				}
				if (currentGM->comboCheck.Num() == 1)
				{
					MyMesh->SetMaterial(0, currentGM->randMatHolder[i]);
					ActiveMat = currentGM->randMatHolder[i];
					currentGM->comboCheck.Add(this);

					//reference to the first block that got clicked
					ABlock *b1 = Cast<ABlock>(currentGM->comboCheck[0]);

					//first block's mat == 2nd block's mat in combo list
					if (b1->ActiveMat == this->ActiveMat)
					{
						currentGM->comboCheck.Empty();
						//b1.activemat or this instance's activemat same thing
						b1->MyMesh->SetMaterial(0, ActiveMat);
						b1->GetWorldTimerManager().ClearTimer(b1->TimerHandle);
						b1->disabled = true;
						this->disabled = true;
					}
					else
					{
					}
				}
			}
		}
	}
	else
	{
		return;
	}
}

void ABlock::HideBlock()
{
	for (int i = 0; i < currentGM->AllBlocks.Num(); i++)
	{
		if (currentGM->AllBlocks[i] == this)
		{
			MyMesh->SetMaterial(0, MatZero);
			//check if we're in the first block in the combo list
			if (currentGM->comboCheck[0] == this && currentGM->comboCheck.Num() == 2)
			{
				//when the first block timer end, we hide the 2nd block with it too
				ABlock *b2 = Cast<ABlock>(currentGM->comboCheck[1]);
				b2->HideBlock();
			}
			//only clear the combo list at 2nd block
			if (currentGM->comboCheck.Num() == 2)
			{
				currentGM->comboCheck.Empty();
			}
		}
	}
}