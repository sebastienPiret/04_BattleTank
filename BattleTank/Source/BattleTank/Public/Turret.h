// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downard speed, and + 1 is max up movement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotationDegrees = 180; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinRotationDegrees = -180; // sensible default
	
	
};
