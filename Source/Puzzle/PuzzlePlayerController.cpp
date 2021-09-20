// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlayerController.h"

#include "EngineUtils.h"
#include "Macros.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

APuzzlePlayerController::APuzzlePlayerController()
{
	this->bShowMouseCursor = true;
	this->bEnableClickEvents = mouseShow;
	PlayerCameraManagerClass = StaticClass();
	static ConstructorHelpers::FObjectFinder<UMaterial> AltBlockMat(TEXT("Material'/Game/AltBlockMat.AltBlockMat'"));
	if (AltBlockMat.Object != nullptr)
	{
		ABM = AltBlockMat.Object;
	}
	//TArray<AActor *> blocks;
	//FindAllActorX(GetWorld(), blocks);
}

void APuzzlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//check(InputComponent);
	InputComponent->BindAction("DisableCursor", IE_Pressed, this, &APuzzlePlayerController::DisableCursor);
}

void APuzzlePlayerController::BeginPlay()
{
	//removing CameraActor_0
	for (TActorIterator<ACameraActor> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		if (!(*actorItr)->GetName().Compare("CameraActor_0"))
		{
			actorItr->Destroy();
		}
	}
}

void APuzzlePlayerController::DisableCursor()
{
	printX("DISAAAABBBLLEE");
	//not doing shit
	//seems like can't change it in runtime
	this->bEnableClickEvents = false;
}

void APuzzlePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (this->IsInputKeyDown(EKeys::LeftMouseButton))
	{
		if (hit.GetActor()->ActorHasTag(cubeTag))
		{
			//printX("name:: " + hit.GetActor()->GetName());
			//hit.GetActor()->GetComponents<UStaticMeshComponent>(meshComp);
			//UStaticMeshComponent* StaticMeshCompo = meshComp[0];
			//UStaticMesh* StaticMesh = StaticMeshCompo->GetStaticMesh();
			//StaticMesh->SetMaterial(0, TheMat);
			//UE_LOG(LogTemp, Warning, TEXT("name: "));
		}
	}
	//TArray<TEnumAsByte<EObjectTypeQuery>>oTypes;
	oTypes.Add(ObjectTypeQuery1);
	if (GetHitResultUnderCursorForObjects(oTypes, false, hit))
	{
		//auto msg = TEXT("WE GOT ONE: ") + hit.GetActor()->GetName();

		//GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Cyan, msg);
	}
}

void APuzzlePlayerController::OnClick()
{
}