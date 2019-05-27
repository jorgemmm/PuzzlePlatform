// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "MovingPlatform.h"
#include "Components/BoxComponent.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);

	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlatformTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Activated"));

	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Activated Platform"));
		
		if (PlatformsToTriggers.Num() > 0)
		{
			for (size_t i = 0; i < PlatformsToTriggers.Num(); i++)
			{
				PlatformsToTriggers[i]->AddActiveTriggers();
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Try to activated but Platform not Loaded!!!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NOT Activated platform!!!"));
	}

}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Deactivated"));
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Deactivated platform"));
		if (PlatformsToTriggers.Num() > 0)
			{
				for (size_t i = 0; i < PlatformsToTriggers.Num(); i++)
				{
					PlatformsToTriggers[i]->RemoveActiveTriggers();
				}
			}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Try to Deactivated but Platform not Loaded!!!"));
		}
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("NOT Deactivated platform!!!"));
	}

}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

