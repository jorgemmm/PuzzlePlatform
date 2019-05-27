// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);


}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//The sever is who has the authority to say
	//what replicate
	if (HasAuthority()) {
	SetReplicates(true);
	SetReplicateMovement(true);
	}


	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void AMovingPlatform::Tick(float Delta)
{

	Super::Tick(Delta);

	/*if (HasAuthority()) {
		FVector Location = GetActorLocation();
		Location += FVector(Speed*Delta, 0.0f, 0.0f);
		SetActorLocation(Location);
	}*/
	
	if (ActiveTriggers > 0) 
	{

		if (HasAuthority()) {
			FVector Location = GetActorLocation();

			float JourneyLenght = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLenght)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;


			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += Speed * Delta * Direction;
			SetActorLocation(Location);
		}

	}


}

void AMovingPlatform::AddActiveTriggers()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTriggers()
{
	if (ActiveTriggers>0)
	{
		ActiveTriggers--;
	}
	
}
