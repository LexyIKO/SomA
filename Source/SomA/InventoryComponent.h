// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

// Blueprint will bind fo this to update the UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOMA_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Adding item in the inventory
	bool AddItem(class UItem* Item);
	// Removing item from the inventory
	bool RemoveItem(class UItem* Item);

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		int Capacity;

	// To update the UI
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;

	// Contains items which player have in start of the game
	UPROPERTY(EditDefaultsOnly, Instanced);
	TArray<class UItem*> DefaultItems;

	// The array of items which is going to be showed in player inventory
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items");
		TArray<class UItem*> Items;
};
