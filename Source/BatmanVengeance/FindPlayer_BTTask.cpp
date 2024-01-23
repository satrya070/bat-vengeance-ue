// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayer_BTTask.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "BehaviorTree/BehaviorTreeComponent.h"


UFindPlayer_BTTask::UFindPlayer_BTTask()
{
    NodeName = "Find Player";
}

EBTNodeResult::Type UFindPlayer_BTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if(APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
    {
        auto Blackboard = OwnerComp.GetBlackboardComponent();
        Blackboard->SetValueAsObject(PlayerKey.SelectedKeyName, Player);

        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
}