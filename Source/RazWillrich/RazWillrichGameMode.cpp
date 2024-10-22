// Copyright Epic Games, Inc. All Rights Reserved.

#include "RazWillrichGameMode.h"
#include "RazWillrichHUD.h"

// Including additional Directives:
#include "Kismet/GameplayStatics.h"
#include "RazWillrichCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARazWillrichGameMode::ARazWillrichGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARazWillrichHUD::StaticClass();
}

// This function searches/finds Player 1:
void ARazWillrichGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<ARazWillrichCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ARazWillrichGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState ARazWillrichGameMode::GetCurrentState() const
{
	return CurrentState;
}

void ARazWillrichGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void ARazWillrichGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
	{
		// Do nothing.
	}
	break;

	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;

	default:
	case EGamePlayState::EUnkown:
	{
		// Do nothing.
	}
	break;
	}
}
