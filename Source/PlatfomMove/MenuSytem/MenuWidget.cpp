// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"



void UMenuWidget::SetMenuInterface(IMenuInterface* menuInterface)
{
	this->MenuInterface = menuInterface;
}


void UMenuWidget::Setup()
{
	UE_LOG(LogTemp, Warning, TEXT("Menu Setup.."));


	this->AddToViewport();
	UWorld* world = GetWorld();
	if (world != nullptr)
	{


		APlayerController* PC = world->GetFirstPlayerController(); //Uworld method
		//GetFirstLocalPlayerController(); GI method
		if (PC != nullptr)
		{


			FInputModeUIOnly InputModeData;

			InputModeData.SetWidgetToFocus(this->TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PC->SetInputMode(InputModeData);

			PC->bShowMouseCursor = true; //Remember Back to false when remove Menu


			UE_LOG(LogTemp, Warning, TEXT("Menu Created"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed When Setup Game"));
		UE_LOG(LogTemp, Error, TEXT("Because world is nullptr or not created"));
	}


}


void UMenuWidget::TearDown()
{
	UE_LOG(LogTemp, Warning, TEXT("Remove Menu.."));

	this->RemoveFromViewport(); //this->RemoveFromParent() work out too
	UWorld* world = GetWorld();
	if (world != nullptr)
	{


		APlayerController* PC = world->GetFirstPlayerController(); //Uworld method
		//GetFirstLocalPlayerController(); GI method
		if (PC != nullptr)
		{

			FInputModeGameOnly InputModeData;
			//	InputModeData.SetConsumeCaptureMouseDown(false);			
			PC->SetInputMode(InputModeData);

			PC->bShowMouseCursor = false; //Remember Back to false when remove Menu


			UE_LOG(LogTemp, Warning, TEXT("Pause Menu or Main Menu Remove"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed When Removing Pause Menu or Main Menu"));
			UE_LOG(LogTemp, Error, TEXT("Because Playercontroller is nullptr or none"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed When Removing Game"));
		UE_LOG(LogTemp, Error, TEXT("Because world is nullptr or not created"));
	}

}


