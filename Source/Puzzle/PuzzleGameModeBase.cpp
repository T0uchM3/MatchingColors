// Copyright Epic Games, Inc. All Rights Reserved.

#include "PuzzleGameModeBase.h"
#include "PuzzlePlayerController.h"

APuzzleGameModeBase::APuzzleGameModeBase()
{
	UE_LOG(LogTemp, Warning, TEXT("WAAAAAAA"));
	DefaultPawnClass = StaticClass();
	PlayerControllerClass = APuzzlePlayerController::StaticClass();
}