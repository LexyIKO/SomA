// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class SOMA_API AliveCPP
{


public:

	AliveCPP();
	
	//Здоровье
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float health;

	//Ф-ия получения урона
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void getDamage(int value);
};
