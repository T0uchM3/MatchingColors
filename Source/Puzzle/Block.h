// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleGameModeBase.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

class ABlock;
class APuzzleGameModeBase;
UCLASS()
class PUZZLE_API ABlock : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent *MyMesh;

	UPROPERTY(EditAnywhere)
		class UMaterial *MatZero;
	UPROPERTY(EditAnywhere)
		class UMaterial *MatOne;
	UPROPERTY(EditAnywhere)
		class UMaterial *MatTwo;
	UPROPERTY(EditAnywhere)
		class UMaterial *MatThree;
	UPROPERTY(EditAnywhere)
		class UMaterial *MatFour;
	UPROPERTY(EditAnywhere)
		class UMaterial *MatFive;
	UPROPERTY(EditAnywhere)
		class UMaterial *MatSix;

	UPROPERTY(EditAnywhere, Category = "Materials")
		bool MatSwitch = true;
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent *SecMesh;
	//reference to gamemode to access the array so Block(s) can add they  itself
	UPROPERTY()
		APuzzleGameModeBase *currentGM;
	TArray<UStaticMeshComponent *> meshComp;
	////trackking the number of blocks that got clicked in a row
	//UPROPERTY()
	//	TArray<AActor *> comboCheck;
	FTimerHandle TimerHandle;
	UMaterial *ActiveMat;
	bool disabled = false;
private:
	virtual void NotifyActorOnClicked(FKey PressedButton = EKeys::LeftMouseButton) override;
	UFUNCTION()
		void HideBlock();
};
