// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangeMaterial.generated.h"

UCLASS()
class RAZWILLRICH_API AChangeMaterial : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChangeMaterial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Creating the Mesh:
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	// Creating two Materials for the Mesh:
	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};

