// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class UNREALTANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 means max downward speed and 1 means max upward speed.
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, category="Setup")
	float MaxDegreesPerSecond = 5; // Elevation speed

	UPROPERTY(EditAnywhere, category = "Setup")
	float MaxElevationDegrees = 40;

	UPROPERTY(EditAnywhere, category="Setup")	
	float MinElevationDegrees = 0;	
};
