// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWayPointC.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PetrolRouteComponent.h"
#include "AIController.h"



EBTNodeResult::Type UChooseNextWayPointC::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto AIContoller = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIContoller->GetPawn();
	auto PetrolRoute = ControlledPawn->FindComponentByClass<UPetrolRouteComponent>();
	if (!ensure(PetrolRoute)) 
	{ 
		return EBTNodeResult::Failed; 
		UE_LOG(LogTemp, Warning, TEXT("No Petrol Points Are Set For A Guard"));
	}

	//Get Patrol Points
	auto PatrolPoints = PetrolRoute->GetPetrolPoints();
    if (PatrolPoints.Num() == 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("No Petrol Points Are Set For A Guard"));
		return EBTNodeResult::Succeeded;
	}

	// Set The Patrol Points
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(NextWayPoint.SelectedKeyName, PatrolPoints[Index]);

	//Cycle The Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}