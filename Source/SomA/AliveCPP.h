// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class SOMA_API AliveCPP
{


public:

	AliveCPP();
	
	//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;

	//�-�� ��������� �����
	void getDamage(float value);
};
