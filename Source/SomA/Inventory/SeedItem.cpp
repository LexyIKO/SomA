// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedItem.h"

void USeedItem::Use(AAvatarCPP* Character)
{
	if (Character->InCollision)
	{
		if(OwningInventory)
		{
			OwningInventory->RemoveItem(this);
		}

	}

}
