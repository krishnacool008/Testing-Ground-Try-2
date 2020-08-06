// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWayPointC.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"



EBTNodeResult::Type UChooseNextWayPointC::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//TODO Protect against empty patrol routes


	
	// Get the patrol Points
	
	auto AIContoller = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIContoller->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	// Set The Patrol Points
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(NextWayPoint.SelectedKeyName, PatrolPoints[Index]);

	//Cycle The Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index);

	

	return EBTNodeResult::Succeeded;
}