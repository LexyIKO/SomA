// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"

void UFoodItem::Use(class AAvatarCPP* Character) {
	if (Character) {
		Character->health += HealthToHeal;
	}
}