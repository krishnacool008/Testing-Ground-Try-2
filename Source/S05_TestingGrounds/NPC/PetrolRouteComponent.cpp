// Fill out your copyright notice in the Description page of Project Settings.


#include "PetrolRouteComponent.h"

// Sets default values for this component's properties
UPetrolRouteComponent::UPetrolRouteComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPetrolRouteComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPetrolRouteComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<AActor*> UPetrolRouteComponent::GetPetrolPoints() const
{
	return PetrolPoints;
}