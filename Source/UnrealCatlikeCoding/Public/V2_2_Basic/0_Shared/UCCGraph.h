// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UCCGraph.generated.h"

UCLASS(Abstract)
class UNREALCATLIKECODING_API AUCCGraph : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<USceneComponent> PointClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Resolution = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Size = 100.0f;
	
public:
	// Sets default values for this actor's properties
	AUCCGraph();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float GetStep() const;
};
