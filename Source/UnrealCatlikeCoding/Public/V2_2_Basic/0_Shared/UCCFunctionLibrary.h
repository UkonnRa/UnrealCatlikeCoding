// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UCCFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCATLIKECODING_API UUCCFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static FVector Wave(const float T, const float U, const float V);
};
