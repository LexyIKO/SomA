// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class SOMA_API AliveCPP
{


public:

	AliveCPP();
	
	//Здоровье
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;

	//Ф-ия получения урона
	void getDamage(float value);
};
