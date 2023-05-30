// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "../InventoryComponent.h"
#include "../AvatarCPP.h"
#include "SeedItem.generated.h"

/**
 * 
 */
UCLASS()
class SOMA_API USeedItem : public UItem
{
	GENERATED_BODY()

protected:
	virtual void Use(class AAvatarCPP* Character) override;
};
