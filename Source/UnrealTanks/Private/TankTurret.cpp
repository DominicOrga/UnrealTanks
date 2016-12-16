// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankTurret.h"

void UTankTurret::BeginPlay()
{
	AzimuthGimbal = GetChildComponent(0);

	if (!AzimuthGimbal)
	{
		UE_LOG(LogTemp, Warning, TEXT("Azimuth gimbal not found."));
	}
}

void UTankTurret::Rotate(float RelativeSpeed)
{
	if (!AzimuthGimbal) { return; }

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + RotationChange;
	float NewGimbalRotation = AzimuthGimbal->RelativeRotation.Yaw - RotationChange;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
	AzimuthGimbal->SetRelativeRotation(FRotator(0, NewGimbalRotation, 0));
}
