// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations.
class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class UNREALTANKS_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UTankAimingComponent* TankAimingComponent;

	UPROPERTY(EditAnywhere, Category="Firing")
	float LaunchSpeed = 10000; // TODO: Determine sensible launch speed value.

public:
	// Sets default values for this pawn's properties
	ATank();

	// Pass a barrel reference to the TankAimingComponent.
	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetBarrelReference(UTankBarrel* Barrel);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	void AimAt(FVector HitLocation);
};
