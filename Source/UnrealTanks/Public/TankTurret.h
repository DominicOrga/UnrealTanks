// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

class USceneComponent;

UCLASS(meta = (BlueprintSpawnableComponent), hidecategories="Collision")
class UNREALTANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, category = "Setup")
	float MaxDegreesPerSecond = 5;

	USceneComponent* AzimuthGimbal;

public:
	virtual void BeginPlay() override;

	void Rotate(float RelativeSpeed);
};
