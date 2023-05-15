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

	randomMove();

	
	
}

// Called to bind functionality to input
void AQuestNPCCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AQuestNPCCPP::randomMove()
{
	srand(time(0));
	int dir = rand() % 9;
	
	switch (dir) {
		case 1:
			if (health != 0) {
				const FRotator Rotation = GetActorRotation();
				const FRotator YawRotation(0, Rotation.Yaw, 0);
				const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
				AddMovementInput(Direction, 0.1);
			}
		case 2:
			if (health != 0) {
				const FRotator Rotation = GetActorRotation();
				const FRotator YawRotation(0, Rotation.Yaw, 0);
				const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
				AddMovementInput(Direction, -0.1);
			}
		case 3:
			if (health != 0) {
				const FRotator Rotation = GetActorRotation();
				const FRotator YawRotation(0, Rotation.Pitch, 0);
				const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
				AddMovementInput(Direction, 0.1);
			}
		case 4:
			if (health != 0) {
				const FRotator Rotation = GetActorRotation();
				const FRotator YawRotation(0, Rotation.Pitch, 0);
				const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
				AddMovementInput(Direction, -0.1);
			}
	}
		

}

void AQuestNPCCPP::Interact_Implementation()
{
	FString Message = TEXT("HI");
	FColor Color = FColor::Green;
	float DisplayTime = 2.0f;
	GEngine->AddOnScreenDebugMessage(-1, DisplayTime, Color, Message);
}
