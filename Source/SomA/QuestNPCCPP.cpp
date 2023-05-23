// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNPCCPP.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Controller.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "Engine/EngineTypes.h"




// Sets default values
AQuestNPCCPP::AQuestNPCCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Mesh and collision
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Capsule);
	// end

	//Index of NPC for dialoge and other
	IndexNPC = 0;
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


/* ÈÍÒÅÐÔÅÉÑ
void AQuestNPCCPP::Interact_Implementation()
{
	FString Message = TEXT("HI");
	FColor Color = FColor::Green;
	float DisplayTime = 2.0f;
	GEngine->AddOnScreenDebugMessage(-1, DisplayTime, Color, Message);
}
*/

