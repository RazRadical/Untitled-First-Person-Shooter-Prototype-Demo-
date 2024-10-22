// Fill out your copyright notice in the Description page of Project Settings.


#include "FireComponent.h"

// Include additional libraries:
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values for this component's properties
UFireComponent::UFireComponent()
{
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Xomponent"));
	MyBoxComponent->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));

	Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("My Fire"));
	Fire->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Fire->SetupAttachment(MyBoxComponent);

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &UFireComponent::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &UFireComponent::OnOverlapEnd);

	bCanApplyDamage = false;
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFireComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Functions for applying damage when necessary:
void UFireComponent::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanApplyDamage = true;
		MyCharacter = Cast<AActor>(OtherActor);
		MyHit = SweepResult;
		GetWorldTimerManager().SetTimer(FireTimerHandle, this, &UFireComponent::ApplyFireDamage, 2.2f, true, 0.0f);
	}
}

void UFireComponent::ApplyFireDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, FireDamageType);
	}
}


// Called every frame
void UFireComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

