#pragma once

#include "CoreMinimal.h"

//#define print2F(x) if (GEngine){ GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values: x: %f"),x));}
//#define print2S(x) if (GEngine){ GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values: x: %s"),x));}
//
//#define printX(x) if (GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));}
//#define print(x,...) if (GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT(x),__VA_ARGS__));}
#define printX(format, ...)if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::White, FString::Printf(TEXT(format), ##__VA_ARGS__), false)
#define log(x) UE_LOG(LogTemp, Warning, TEXT(x));
#define logF(x) UE_LOG(LogTemp, Warning, TEXT("%f"),x);
