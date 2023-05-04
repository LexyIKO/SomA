// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PeopleCPP.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "AvatarCPP.generated.h"

UCLASS()
class SOMA_API AAvatarCPP : public APawn, public PeopleCPP
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAvatarCPP();

	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* Body;

	UPROPERTY(EditAnywhere, Category = Input)
		class UFloatingPawnMovement* Movement;

	// Селфи палка для камеры
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* SpringArm;

	// Камера персонажа
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* Camera;

	// Методы управление
	void MoveForward(float Axis);
	void MoveRight(float Axis);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
