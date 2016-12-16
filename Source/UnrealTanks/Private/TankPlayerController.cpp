// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "Tank.h"
#include "TankPlayerController.h"

DEFINE_LOG_CATEGORY(TankPlayerController)

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(TankPlayerController, Error, TEXT("Controlled Tank not found."));
	}	
	else
	{
		UE_LOG(TankPlayerController, Log, TEXT("Player Controlled Tank: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		ControlledTank->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& out_HitLocation) const
{
	int32 ViewportXSize, ViewportYSize;
	GetViewportSize(OUT ViewportXSize, OUT ViewportYSize);

	// Find the 2D location of the crosshair in the screen.
	FVector2D ScreenLocation = FVector2D(ViewportXSize * CrosshairXLocation, ViewportYSize * CrosshairYLocation);

	// "De-project" the crosshair screen location and get its world direction.
	FVector WorldPosition, WorldDirection;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT WorldPosition, OUT WorldDirection);

	// Generate the Line Trace, starting from the camera pointing towards the crosshair.
	FHitResult HitResult;
	FVector StartTrace = PlayerCameraManager->GetCameraLocation();
	FVector EndTrace = StartTrace + WorldDirection * TraceDistance * 100000; // Multiply to 100,000 to convert cm to km.

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECollisionChannel::ECC_Visibility))
	{
		out_HitLocation = HitResult.Location;
		return true;
	}
	
	return false;
}
