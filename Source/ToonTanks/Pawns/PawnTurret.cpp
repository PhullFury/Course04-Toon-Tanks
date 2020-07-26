// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"
#include "PawnTurret.h"

APawnTurret::APawnTurret()
{
	
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	//if Player == null then stop
	if (!PlayerPawn)
	{
		return;
	}

	//if player is in range then fire	
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.f;
	}

	float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
	return Distance;
}

void APawnTurret::HandleDestruction()
{
	//calls PawnBase to play death effects
	Super::HandleDestruction();
	//Destroy();
}

void APawnTurret::Fire()
{
	Super::Fire();
}

/*add a PowerUp.cpp
put power up on random places use srand
derive child classes on gives speed boost and the other decreases enemy fire rate
use dist() function to see if player touched the power up
make applicable variables public*/