// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PuzzleGameModeBase.generated.h"

class APuzzlePlayerController;
/**
 *
 */
UCLASS()
class PUZZLE_API APuzzleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APuzzleGameModeBase();
	APuzzlePlayerController *playerController;
	UPROPERTY()
		TArray<AActor *> AllBlocks;
	//array of the mat that got assigned to each block with rand
	UPROPERTY()
		TArray<UMaterial *> randMatHolder;
	//getting changed in SCButton, and read in Block
	bool GStart = false;
	//trackking the number of blocks that got clicked in a row
	UPROPERTY()
		TArray<AActor *> comboCheck;
};
