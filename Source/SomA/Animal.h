// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AliveCPP.h"
#include "InteractInteface.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Animal.generated.h"

UCLASS()
class SOMA_API AAnimal : public APawn, public AliveCPP, public IInteractInteface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimal();

	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Body;

	UPROPERTY(EditAnywhere, Category = Input)
		class UFloatingPawnMovement* Movement;

	UFUNCTION(BlueprintCallable, Category = "MyMovement")
		void RandomMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
