// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(TankAIController, Log, All)

// Forward Declaration.
class ATank;

UCLASS()
class UNREALTANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

private: 
	void AimTowardsPlayerTank();
};
