// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class SOMA_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Переменная смерти
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDead;

	// Селфи палка для камеры
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	// Камера персонажа
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FollowCamera;

	// Методы управление
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void Jump();
	void StopJumping();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
