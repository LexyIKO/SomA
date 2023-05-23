// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PeopleCPP.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "InteractInteface.h"
#include "QuestNPCCPP.generated.h"


UCLASS()
class SOMA_API AQuestNPCCPP : public APawn, public PeopleCPP, public IInteractInteface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AQuestNPCCPP();

	//Mesh and collision
	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* Body;
	//end

	//Index of NPC for dialoge and other
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 IndexNPC;


	/*
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Interact();
	virtual void Interact_Implementation() override;
	*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
