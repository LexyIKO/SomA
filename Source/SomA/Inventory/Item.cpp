// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem::UItem() {
	ItemDisplayName = FText::FromString("Item");
	UseActionText = FText::FromString("Use");
	ID = 0;
}

void UItem::Use(AAvatarCPP* Character) {

}
