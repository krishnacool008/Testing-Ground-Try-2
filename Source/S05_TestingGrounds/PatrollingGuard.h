// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrollingGuard.generated.h"

UCLASS()
class S05_TESTINGGROUNDS_API APatrollingGuard : public ACharacter
{
	GENERATED_BODY()

		

public:
	UPROPERTY(EditInstanceOnly, Category = "Petrol Route")// Make Getter Instead of public
		TArray<AActor*> PatrolPointsCPP;

	// Sets default values for this character's properties
	APatrollingGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
