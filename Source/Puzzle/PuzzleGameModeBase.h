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
};
