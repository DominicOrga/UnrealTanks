// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

#define OUT

DECLARE_LOG_CATEGORY_EXTERN(TankPlayerController, Log, All)

// Forward Declaration.
class ATank;

UCLASS()
class UNREALTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3;

	UPROPERTY(EditAnywhere)
	float TraceDistance = 10; // Trace distance is based on kilometers.
 
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

private:
	/** Increment the barrel's orientation towards the crosshair. */
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
