// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "../InventoryComponent.h"
#include "../AvatarCPP.h"

void UFoodItem::Use(class AAvatarCPP* Character) {
	if (Character) {
		Character->AvatarHealth += HealthToHeal;

		if(OwningInventory) {
			OwningInventory->RemoveItem(this);
		}

	}


}