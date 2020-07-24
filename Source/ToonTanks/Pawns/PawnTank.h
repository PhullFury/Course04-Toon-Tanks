// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;


	public:
		// Sets default values for this pawn's properties
		APawnTank();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	private:

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArmComp;
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraComp;

		FVector MoveDirection;
		FQuat RotationDirection;

		UPROPERTY(EditAnywhere, Category = "Speed")
		float MoveSpeed = 100.f;
		UPROPERTY(EditAnywhere, Category = "Speed")
		float RotateSpeed = 100.f;

		void CalculateMoveInput(float Value);
		void CalculateRotateInput(float Value);

		void Move();
		void Rotate();
};
