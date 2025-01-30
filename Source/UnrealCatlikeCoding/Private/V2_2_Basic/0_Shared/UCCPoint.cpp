// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCatlikeCoding/Public/V2_2_Basic/0_Shared/UCCPoint.h"


// Sets default values for this component's properties
UUCCPoint::UUCCPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	if (const auto Mat = GetMaterial(0))
	{
		GetStaticMesh()->SetMaterial(0, Mat);
	}
}


// Called when the game starts
void UUCCPoint::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UUCCPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
