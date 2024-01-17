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
}

void APlatformMover::MovePlatform(float DeltaTime)
{
	if(MustTurn())
	{
		//FVector MoveDirection = MoveVelocity.GetSafeNormal();
		MoveVelocity = -MoveVelocity;
		SetActorLocation(GetActorLocation() + MoveVelocity * DeltaTime);
	}
	else
	{
		FVector CurrentPosition = GetActorLocation() + MoveVelocity * DeltaTime;
		SetActorLocation(CurrentPosition);
	}
}

bool APlatformMover::MustTurn() const
{
	if(FVector::Distance(GetActorLocation(), BasePosition) > DistToMove)
	{
		UE_LOG(LogTemp, Display, TEXT("Turn!!!"));
		return true;
	}

	return false;
}

