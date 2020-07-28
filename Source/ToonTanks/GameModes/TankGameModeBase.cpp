// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();

}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	UE_LOG(LogTemp, Error, TEXT("You ded son!"));
}

void ATankGameModeBase::HandleGameStart()
{

}

void ATankGameModeBase::HandleGameOver(bool GameOver)
{

}