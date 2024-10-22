// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayer_BTTask.h"

// Additional Directives for necessary files:
#include "Kismet/GameplayStatics.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"

// Defining Constructor for 'FindPlayer_BTTask' Class:
UFindPlayer_BTTask::UFindPlayer_BTTask()
{
	NodeName = "Find Player";
}

EBTNodeResult::Type UFindPlayer_BTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Assigning Player to PlayerKey:
	if (APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		auto Blackboard = OwnerComp.GetBlackboardComponent();
		Blackboard->SetValueAsObject(PlayerKey.SelectedKeyName, Player);

		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}