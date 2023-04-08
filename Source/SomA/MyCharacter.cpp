// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Инициализация переменной bDead - отвечает за то жив ли персонаж
	bDead = false;
	
	// Размер капсуль компонента
	GetCapsuleComponent()->InitCapsuleSize(20.0f, 85.0f);

	// Выключение зависимости камеры от поворота
	bUseControllerRotationYaw = false;

	// Создание и настройка компонента "SpringArm"
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 1000.0f;
	CameraBoom->bUsePawnControlRotation = true;

	//Создание и настройка камеры
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Настройка управления
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 750.0f, 0.0f);
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = 800.0f;
	GetCharacterMovement()->SetWalkableFloorAngle(40);

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Бинд прыжка и остановки прыжка
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);

	// Бинд ходьбы
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}


// Реализация управления
void AMyCharacter::MoveForward(float Axis) {
	if ((Controller != NULL) && (Axis != 0.0f) && (bDead != true)) {
		
		FVector ForceToAdd = FVector(1, 0, 0) * 800;
		AddMovementInput(ForceToAdd, Axis);
	}
}

void AMyCharacter::MoveRight(float Axis) {
	if ((Controller != NULL) && (Axis != 0.0f) && (bDead != true)) {

		FVector ForceToAdd = FVector(0, 1, 0) * 800;
		AddMovementInput(ForceToAdd, Axis);
	}
}

void AMyCharacter::Jump() {

}

void AMyCharacter::StopJumping() {

}