// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformMover.h"

// Sets default values
APlatformMover::APlatformMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformMover::BeginPlay()
{
	Super::BeginPlay();

	BasePosition = GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("%s"), *BasePosition.ToString());	
}

// Called every frame
void APlatformMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	CheckTurn();
}

void APlatformMover::MovePlatform(float DeltaTime)
{
	FVector CurrentPosition = GetActorLocation() + MoveVelocity * DeltaTime;
	SetActorLocation(CurrentPosition);

	//UE_LOG(LogTemp, Display, TEXT("%s"), *BasePosition.ToString());

}

bool APlatformMover::CheckTurn()
{
	if(FVector::Distance(GetActorLocation(), BasePosition) > 100.f)
	{
		//UE_LOG(LogTemp, Display, TEXT("Turn!!!"));
		MoveVelocity = -MoveVelocity;
		return true;
	}

	return false;
}

