// Fill out your copyright notice in the Description page of Project Settings.

#include "SCButton.h"
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
	printX("test");
	MeshSwitch = !MeshSwitch;
	SCMesh->SetStaticMesh(MeshSwitch ? TempSMesh : TempCMesh);
	for (AActor *block : currentGM->AllBlocks)
	{
		//BlockRef = Cast<ABlock>(currentGM->AllBlocks[0]);
		BlockRef = Cast<ABlock>(block);
		BlockRef->MatSwitch = !BlockRef->MatSwitch;
		BlockRef->MyMesh->SetMaterial(0, BlockRef->MatSwitch ? BlockRef->MatOne : BlockRef->MatTwo);
	}
}