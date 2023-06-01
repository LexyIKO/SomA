// Fill out your copyright notice in the Description page of Project Settings.


#include "AvatarCPP.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "InventoryComponent.h"
#include "Inventory/Item.h"
#include "InteractInteface.h"
#include <Runtime/Core/Public/Misc/OutputDeviceNull.h>


// Sets default values
AAvatarCPP::AAvatarCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Capsule);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Capsule);

	InteractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractSphere"));
	InteractSphere->SetupAttachment(Capsule);

	InteractingActor = nullptr;
	InCollision = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = true;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 10;

	MoneyCount = 0;

	AvatarHealth = health;
}

// Called when the game starts or when spawned
void AAvatarCPP::BeginPlay()
{
	Super::BeginPlay();
	
	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &AAvatarCPP::OnInteractionSphereBeginOverlap);
	InteractSphere->OnComponentEndOverlap.AddDynamic(this, &AAvatarCPP::OnInteractionSphereEndOverlap);
}

// Called every frame
void AAvatarCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//Постоянное падение
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Z);
	AddMovementInput(Direction, -1);
}

// Called to bind functionality to input
void AAvatarCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Бинд ходьбы
	PlayerInputComponent->BindAxis("MoveForward", this, &AAvatarCPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAvatarCPP::MoveRight);

	// Бинды для камеры
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// Кнопка взаимодействия
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AAvatarCPP::OnInteractionPressed);

	// Пересечение коллизий
	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &AAvatarCPP::OnInteractionSphereBeginOverlap);
	InteractSphere->OnComponentEndOverlap.AddDynamic(this, &AAvatarCPP::OnInteractionSphereEndOverlap);
}

//Реализация ходьбы
void AAvatarCPP::MoveForward(float Axis)
{
	if ((Controller != NULL) && (Axis != 0.0f) && (health != 0)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);
	}
}

void AAvatarCPP::MoveRight(float Axis)
{
	if ((Controller != NULL) && (Axis != 0.0f) && (health != 0)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}
//Конец реализации

void AAvatarCPP::UseItem(class UItem* Item) {
	if (Item) {
		Item->Use(this);
		Item->OnUse(this); // This is for blueprint
	}
}

void AAvatarCPP::OnInteractionPressed()
{
	if (InCollision && InteractingActor)
	{
		TArray<FString> EmptyArgs; 
		FOutputDeviceNull ar; 

		InteractingActor->CallFunctionByNameWithArguments(TEXT("Interact"), ar, nullptr, true);
	}
}

void AAvatarCPP::OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	InteractingActor = OtherActor;
	InCollision = true;
}

void AAvatarCPP::OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == InteractingActor)
	{
		InteractingActor = nullptr;
		InCollision = false;
	}
}