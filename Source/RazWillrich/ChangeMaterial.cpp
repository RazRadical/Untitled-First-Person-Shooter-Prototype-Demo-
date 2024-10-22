// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeMaterial.h"

// Additional Directives for necessary files:
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"

// Sets default values
AChangeMaterial::AChangeMaterial()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Declaring defaults for the Mesh:
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	RootComponent = MyMesh;

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX COMP"));
	MyBoxComponent->InitBoxExtent(FVector(100, 100, 100));
	MyBoxComponent->SetCollisionProfileName("Trigger");
	MyBoxComponent->SetupAttachment(RootComponent);

	// Creating the On/Off Materials for the Mesh:
	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("On Material"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("Off Material"));

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AChangeMaterial::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AChangeMaterial::BeginPlay()
{
	Super::BeginPlay();

	// Creating volume for the DebugHelper:
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::Yellow, true, -1, 0, 10);

	MyMesh->SetMaterial(0, OffMaterial);
}

// Called every frame
void AChangeMaterial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Declaring Function for the Overlap Event: 
void AChangeMaterial::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		MyMesh->SetMaterial(0, OnMaterial);
	}
}
