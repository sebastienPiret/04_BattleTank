// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declaration
class UTankBarrel; 
class UTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category="Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsonly, Category = "Setup")
	// UClass* ProjectileBlueprint; // Alternative: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/
	TSubclassOf<AProjectile>ProjectileBlueprint;

	UPROPERTY(EditDefaultsonly, Category = "firing")
	float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsonly, Category = "firing")
	float ReloadTimeSeconds = 3;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO Remove
	
	double LastFireTime = 0;
};
