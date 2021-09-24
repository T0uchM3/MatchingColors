// Fill out your copyright notice in the Description page of Project Settings.

#include "SCButton.h"

#include <string>

#include "Block.h"
#include "Macros.h"
// Sets default values
ASCButton::ASCButton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SCMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SCMESH"));
	RootComponent = SCMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SMesh(TEXT("StaticMesh'/Game/START.START'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CMesh(TEXT("StaticMesh'/Game/CANCEL.CANCEL'"));

	if (SMesh.Object != nullptr)
	{
		TempSMesh = SMesh.Object;
	}
	if (CMesh.Object != nullptr)
	{
		TempCMesh = CMesh.Object;
	}
}

// Called when the game starts or when spawned
void ASCButton::BeginPlay()
{
	Super::BeginPlay();
	currentGM = Cast<APuzzleGameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void ASCButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASCButton::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	FVector newLocation = GetActorLocation();
	printX("test");
	MeshSwitch = !MeshSwitch;
	SCMesh->SetStaticMesh(MeshSwitch ? TempSMesh : TempCMesh);
	//for (AActor *block : currentGM->AllBlocks)
	//{
	if (cancel)
	{
		printX("CANCEL");
		newLocation.Y = newLocation.Y + 60.f;
		this->SetActorLocation(newLocation);
		currentGM->GStart = false;
		//for (int i = 0; i < currentGM->AllBlocks.Num(); i++)
		//{
		//	BlockRef = Cast<ABlock>(currentGM->AllBlocks[i]);
		//	BlockRef->MyMesh->SetMaterial(0, randMatHolder[i]);
		//}
	}
	else
	{
		printX("START");
		StartPeek();
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ASCButton::Hide, 2, false);
		newLocation.Y = newLocation.Y - 60.f;
		this->SetActorLocation(newLocation);
	}
	cancel = !cancel;
}

void ASCButton::StartPeek()
{
	currentGM->randMatHolder.Empty();
	secondRun = false;
	TArray<int> randInts;
	RandomizeBlocks();
	//currentGM->AllBlocks.Append();
	for (AActor *block : currentGM->AllBlocks)
	{
		BlockRef = Cast<ABlock>(block);
		matHolder.Add(BlockRef->MatOne);
		matHolder.Add(BlockRef->MatTwo);
		matHolder.Add(BlockRef->MatThree);
		matHolder.Add(BlockRef->MatFour);
		matHolder.Add(BlockRef->MatFive);
		matHolder.Add(BlockRef->MatSix);
		//or a while loop
	newRand:
		if (randInts.Num() == 6)
		{
			if (secondRun)
				break;
			randInts.Empty();
			//next time the break above will get triggered == we're done
			secondRun = true;
			goto newRand;
		}
		int rand = FMath::RandRange(0, 5);
		logI(rand);

		if (randInts.Contains(rand))
			goto newRand;
		else
		{
			log("GOTIT");
			randInts.Add(rand);
			BlockRef->MyMesh->SetMaterial(0, matHolder[rand]);
			currentGM->randMatHolder.Add(matHolder[rand]);
		}
	}
}

void ASCButton::Hide()
{
	for (AActor *block : currentGM->AllBlocks)
	{
		BlockRef = Cast<ABlock>(block);
		BlockRef->MyMesh->SetMaterial(0, BlockRef->MatZero);
		currentGM->GStart = true;
	}
}

void ASCButton::RandomizeBlocks()
{
	//guarantee true randomness
	TempBlockHolder.Empty();
	for (AActor *block : currentGM->AllBlocks)
	{
		TempBlockHolder.Add(block);
	}
	currentGM->AllBlocks.Empty();
	for (AActor *block : TempBlockHolder)
	{
		currentGM->AllBlocks.Insert(block, FMath::RandRange(0, currentGM->AllBlocks.Num()));
	}
}