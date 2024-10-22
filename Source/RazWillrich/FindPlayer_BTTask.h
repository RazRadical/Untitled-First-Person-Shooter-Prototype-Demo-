// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindPlayer_BTTask.generated.h"

/**
 *
 */
UCLASS()
class RAZWILLRICH_API UFindPlayer_BTTask : public UBTTaskNode
{
	GENERATED_BODY()

// Initializing Constructor of 'FindPlayer_BTTask' class:
public:
	UFindPlayer_BTTask();

	// The PlayerKey will be exposed in the BehaviorTree:
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector PlayerKey;

	// Overriding the ExecuteTask method:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
