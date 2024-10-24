// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class RAZWILLRICH_API ACameraDirector : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// We want to be able to interact with these Actors inside of the Editor:
	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraTwo;

	float TimeToNextCameraChange;
};
