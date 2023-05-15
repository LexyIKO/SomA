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

	// Инвентарь
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class UInventoryComponent* Inventory;
	
	// Коллизия для взаимодествия
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = InteractSphere)
		class USphereComponent* InteractSphere;


	UFUNCTION(BlueprintCallable, Category = "Items")
		void UseItem(class UItem* Item);

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void OnInteractionPressed();

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	AActor* InteractingActor;
	bool InCollision;


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
