// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCButton.generated.h"

class APuzzleGameModeBase;
class ABlock;
UCLASS()
//start/cancel button
class PUZZLE_API ASCButton : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASCButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent *SCMesh;
	UPROPERTY()
		APuzzleGameModeBase *currentGM;
	//can only find object through the constructor it seems
	//so these temp vars are here to make those meshes vars accessible from other meths
	UStaticMesh *TempSMesh, *TempCMesh;
	bool MeshSwitch = true;
	UPROPERTY()
		ABlock *BlockRef;
private:
	//click event on the mesh!
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
};
