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
	MatOne = CreateDefaultSubobject<UMaterial>(TEXT("MatOne"));
	MatTwo = CreateDefaultSubobject<UMaterial>(TEXT("MatTwo"));
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
		currentGM->AllBlocks.Add(this);
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
	//printX("+++++++++++++++++++++++");
	//auto msg = TEXT("NAME::: ") + this->GetName();
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, msg);
	//}

	//printFF("name:: %s", *this->GetName());
	//MatSwitch = !MatSwitch;
	//MyMesh->SetMaterial(0, MatSwitch ? MatOne : MatTwo);

	//printX("array size:: %i", currentGM->AllBlocks.Num());
	//bb = Cast<ABlock>(currentGM->AllBlocks[0]);
	//bb->MyMesh->SetMaterial(0, MatSwitch ? MatOne : MatTwo);
	//printX("first block name: %s", *currentGM->AllBlocks[0]->GetName());
}