// Fill out your copyright notice in the Description page of Project Settings.


#include "CampFire.h"

// Include additional libraries:
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACampFire::ACampFire()
{
    MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Xomponent"));
    MyBoxComponent->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
    RootComponent = MyBoxComponent;

    Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("My Fire"));
    Fire->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    Fire->SetupAttachment(RootComponent);

    MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACampFire::OnOverlapBegin);
    MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ACampFire::OnOverlapEnd);

    bCanApplyDamage = false;
}


// Functions for applying damage when necessary:
void ACampFire::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
    {
        bCanApplyDamage = true;
        MyCharacter = Cast<AActor>(OtherActor);
        MyHit = SweepResult;
        GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ACampFire::ApplyFireDamage, 2.2f, true, 0.0f);
    }
}

void ACampFire::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    bCanApplyDamage = false;
    GetWorldTimerManager().ClearTimer(FireTimerHandle);
}

void ACampFire::ApplyFireDamage()
{
    if (bCanApplyDamage)
    {
        UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, FireDamageType);
    }
}