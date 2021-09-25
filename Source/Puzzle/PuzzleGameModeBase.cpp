// Copyright Epic Games, Inc. All Rights Reserved.

#include "PuzzleGameModeBase.h"
#include "PuzzlePlayerController.h"

APuzzleGameModeBase::APuzzleGameModeBase()
{
	DefaultPawnClass = StaticClass();
	PlayerControllerClass = APuzzlePlayerController::StaticClass();
}