// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCatlikeCoding/Public/V2_2_Basic/0_Shared/UCCGraph.h"
#include "UnrealCatlikeCoding/Public/V2_2_Basic/0_Shared/UCCPoint.h"
#include "V2_2_Basic/0_Shared/UCCFunctionLibrary.h"


// Sets default values
AUCCGraph::AUCCGraph()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUCCGraph::BeginPlay()
{
	Super::BeginPlay();

	for (int x = 0; x < Resolution; x++)
	{
		for (int y = 0; y < Resolution; y++)
		{
			const auto Comp = AddComponentByClass(PointClass, false, { GetActorRotation(), FVector::Zero() }, false);
			if (const auto ThePoint = Cast<UUCCPoint>(Comp))
			{
				ThePoint->SetRelativeScale3D((Size / Resolution) / 100.0f * FVector::One());
				UE_LOG(LogTemp, Warning, TEXT("  Name: %s"), *ThePoint->GetName());
			}
		}
	}
}

void AUCCGraph::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto TotalTime = GetWorld()->GetTime().GetWorldTimeSeconds();

	TArray<TObjectPtr<UUCCPoint>> Points;
	GetComponents<UUCCPoint>(Points);

	const auto HalfSize = Size / 2.0f;
	const auto Step = GetStep();
	

	for (int x = 0; x < Resolution; x++)
	{
		for (int y = 0; y < Resolution; y++)
		{
			const auto Child = Points[x * Resolution + y];
			const auto u = 2.0f * x / Resolution - 1.0f;
			const auto v = 2.0f * y / Resolution - 1.0f;
			const auto Result = UUCCFunctionLibrary::Wave(TotalTime, u, v);
			Child->SetRelativeLocation({ HalfSize * Result.X, HalfSize * Result.Y, Result.Z });
		}
	}
}

float AUCCGraph::GetStep() const
{
	return Size / Resolution;
}
