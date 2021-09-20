// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PuzzlePlayerController.generated.h"

/**
 *
 */
class Block;
UCLASS()
class PUZZLE_API APuzzlePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	APuzzlePlayerController();
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;

	UFUNCTION()
		void OnClick();
	FHitResult hit;
	virtual void SetupInputComponent() override;
	TArray<UStaticMeshComponent *> meshComp;
	FName cubeTag = TEXT("cube");
	UMaterial *ABM;
	UMaterialInterface *TheMat;
	TArray<TEnumAsByte<EObjectTypeQuery>> oTypes;

	bool mouseShow = true;

	UPROPERTY()
		class UInputComponent *IComponent;
	UFUNCTION()
		void DisableCursor();
	UPROPERTY(EditAnywhere, Category = "arrayExample ")
		TArray<AActor *> TestArray;

	//template <typename T>
	//void FindAllActorX(UWorld *world, TArray<T *> Holder)
	//{
	//	for (TActorIterator<T> It(world); It; ++It)
	//	{
	//		Holder.Add(*It);
	//	}
	//}

	//UPROPERTY(EditAnywhere)
	//	bool mouseShow = true;

	//UPROPERTY(VisibleAnywhere, Category = "Materials")
	//	UMaterialInterface* Mat1;
	//UPROPERTY(VisibleAnywhere, Category = "Materials")
	//	UMaterialInterface* Mat2;
};
