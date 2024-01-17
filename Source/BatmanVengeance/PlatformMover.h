// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformMover.generated.h"

UCLASS()
class BATMANVENGEANCE_API APlatformMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovePlatform(float DeltaTime);

private:
	UPROPERTY(EditAnywhere)
	FVector MoveVelocity;

	UPROPERTY(EditAnywhere)
	float DistToMove;

	FVector BasePosition;

	bool MustTurn() const;
};
