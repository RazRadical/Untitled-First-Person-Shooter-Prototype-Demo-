// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

// Including additional library for finding the Player and getting their Health:
#include "RazWillrichCharacter.h"
#include "RazWillrichGameMode.generated.h"

// Creating game logic:
UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnkown
};

UCLASS(minimalapi)
class ARazWillrichGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARazWillrichGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ARazWillrichCharacter* MyCharacter;

	UFUNCTION(BlueprintPure, Category = "Health")
		EGamePlayState GetCurrentState() const;

	void SetCurrentState(EGamePlayState NewState);

private:

	EGamePlayState CurrentState;

	void HandleNewState(EGamePlayState NewState);
};

