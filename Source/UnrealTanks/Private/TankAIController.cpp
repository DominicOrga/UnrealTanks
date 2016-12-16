// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "Tank.h"
#include "TankAIController.h"

DEFINE_LOG_CATEGORY(TankAIController)

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(TankAIController, Error, TEXT("Controlled Tank not found."));
	}
	else
	{
		UE_LOG(TankAIController, Log, TEXT("AI Controlled Tank: %s"), *ControlledTank->GetName());
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(TankAIController, Error, TEXT("Player Tank not found."));
	}
	else
	{
		UE_LOG(TankAIController, Log, TEXT("Player Controlled Tank: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimTowardsPlayerTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::AimTowardsPlayerTank()
{
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!ControlledTank || !PlayerTank) { return; }

	ControlledTank->AimAt(PlayerTank->GetActorLocation());
}
