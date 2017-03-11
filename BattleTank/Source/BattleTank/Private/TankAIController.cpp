// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerController();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller doesn't see a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is the player tank possessed.... Haaaaaaaaaaa!!!!!!"), *(PlayerTank->GetName()));
	}
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerController())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerController()->GetActorLocation());

		// Fire if ready
	}
}

ATank* ATankAIController::GetPlayerController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


