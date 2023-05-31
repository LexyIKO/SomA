// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PeopleCPP.h"
#include "InteractInteface.h"
#include "DillerNPC_CPP.generated.h"

UCLASS()
class SOMA_API ADillerNPC_CPP : public APawn, public PeopleCPP, public IInteractInteface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADillerNPC_CPP();

	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* Body;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
