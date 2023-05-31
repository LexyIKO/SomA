// Fill out your copyright notice in the Description page of Project Settings.


#include "Animal.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAnimal::AAnimal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Capsule);
}



float TimeSinceLastDirectionChange = 0.0f;
float DirectionChangeInterval = 2.0f;

void AAnimal::RandomMovement()
{

	FVector CurrentLocation = GetActorLocation();


	TimeSinceLastDirectionChange += 0.005f;

	// ≈сли прошло достаточно времени дл€ изменени€ направлени€
	if (TimeSinceLastDirectionChange >= DirectionChangeInterval)
	{
		// √енерируем новое случайное направление
		float RandomX = FMath::RandRange(-1.0f, 1.0f);
		float RandomY = FMath::RandRange(-1.0f, 1.0f);
		FVector RandomDirection(RandomX, RandomY, 0.0f);

		// Ќормализуем вектор направлени€
		RandomDirection.Normalize();

		// ”станавливаем новое направление
		FRotator MoveDirection = RandomDirection.Rotation();

		SetActorRotation(MoveDirection);

		// —брасываем врем€ с момента последнего изменени€ направлени€
		TimeSinceLastDirectionChange = 0.0f;
	}

	FVector MoveDirection = GetActorRotation().Vector();

	// ѕеремещаем Pawn в новую позицию с учетом коллизий
	AddMovementInput(MoveDirection, 0.6f, true);
}

// Called when the game starts or when spawned
void AAnimal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//ѕосто€нное падение
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Z);
	AddMovementInput(Direction, -10);

}

