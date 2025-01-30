// Fill out your copyright notice in the Description page of Project Settings.


#include "V2_2_Basic/0_Shared/UCCFunctionLibrary.h"

FVector UUCCFunctionLibrary::Wave(const float T, const float U, const float V)
{
	return {U, V, 10.0f * cos(T + U + V)};
}
