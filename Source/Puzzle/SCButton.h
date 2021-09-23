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
	//show the block's colors briefly
	UFUNCTION()
		void StartPeek();
	//hide the block's colors
	UFUNCTION()
		void Hide();
	UPROPERTY
	(VisibleAnywhere)
		UStaticMeshComponent *SCMesh;
	UPROPERTY()
		APuzzleGameModeBase *currentGM;
	//the block that currently being active in the loop
	UPROPERTY()
		ABlock *BlockRef;
	//can only find object through the constructor it seems
	//so these temp vars are here to make those meshes vars accessible from other meths
	UStaticMesh *TempSMesh, *TempCMesh;
	bool MeshSwitch = true;
	bool cancel = false;
	FTimerHandle TimerHandle;
	//array of current block's mats (umaterial)
	UPROPERTY()
		TArray<UMaterial *> matHolder;
	//array of the mat that got assigned to each block with rand
	UPROPERTY()
		TArray<UMaterial *> randMatHolder;
	bool secondRun = false;

private:
	//click event on the mesh!
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
};
