// Fill out your copyright notice in the Description page of Project Settings.


#include "AliveCPP.h"

AliveCPP::AliveCPP()
{
	health = 1;
}

void AliveCPP::getDamage(int value)
{
	health -= value;
}


