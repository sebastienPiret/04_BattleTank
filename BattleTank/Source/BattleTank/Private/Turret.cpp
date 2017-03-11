// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Turret.h"

void UTurret::Rotate(float RelativeSpeed)
{
	// Move the barrel the right amount of this frame
	// Given a max elevation ant the frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeSpeed*MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	auto RotationRange = FMath::Clamp<float>(RawNewRotation, MinRotationDegrees, MaxRotationDegrees);
	SetRelativeRotation(FRotator(0, RotationRange, 0));

}


