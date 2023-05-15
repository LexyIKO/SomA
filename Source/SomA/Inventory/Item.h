// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../AvatarCPP.h"
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

	// Weight of the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float Weight;

	// The inventory which own item
	UPROPERTY()
	class UInventoryComponent* OwningInventory;

	virtual void Use(class AAvatarCPP* Character) PURE_VIRTUAL(UItem, )

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AAvatarCPP* Character);
};
