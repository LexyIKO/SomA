// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../AvatarCPP.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class SOMA_API UItem : public UObject
{
	GENERATED_BODY()

public:

	UItem();

	virtual class UWorld* GetWorld() const { 
		return World; 
	}

	UPROPERTY(Transient)
	class UWorld* World;
	
	// Text for using the item (Equip, Eat, etc)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText UseActionText;

	// The mesh which displays for this items pick up
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UStaticMesh* PickupMesh;

	// The thumbnail for this item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnail;

	// Display name of the item in the inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDisplayName;

	// Description of the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
		FText ItemDescription;

	// The inventory which own item
	UPROPERTY()
	class UInventoryComponent* OwningInventory;

	virtual void Use(class AAvatarCPP* Character);

	// Function to use in BP
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AAvatarCPP* Character);
};
