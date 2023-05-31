// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNPCCPP.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Controller.h"


// Sets default values
AQuestNPCCPP::AQuestNPCCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Capsule);
}



// Called when the game starts or when spawned
void AQuestNPCCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestNPCCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AQuestNPCCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

