// Fill out your copyright notice in the Description page of Project Settings.

#include "PauseMenu.h"
#include "Components/Button.h"

#include "Components/WidgetSwitcher.h"
#include "Components/Widget.h"
#include "Components/EditableTextBox.h"
#include "Internationalization/Text.h"

#include "Kismet/KismetSystemLibrary.h"

bool UPauseMenu::Initialize()
{

	bool Succes = Super::Initialize();
	if (Succes != true) return false;

	//TODO
	if (BackToGameBtn != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Back To Game Button Clickled"));
		BackToGameBtn->OnClicked.AddDynamic(this, &UPauseMenu::BackToGame);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Back To Game Button  Not Binding"));
	}


	if (ReturnToLobbyBtn != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Quit Button Clickled"));
		ReturnToLobbyBtn->OnClicked.AddDynamic(this, &UPauseMenu::ReturnLobby);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Quit Button  Not Binding"));
	}


	return true;
}




void UPauseMenu::ReturnLobby()
{

	UWorld* world = GetWorld();


	if (world != nullptr)
	{


		APlayerController* PC = world->GetFirstPlayerController(); //Uworld method
		//GetFirstLocalPlayerController(); GI method
		if (PC != nullptr)
		{
			TearDown(); //call from WB
			MenuInterface->ReturnLobby();
			//TEnumAsByte 
			//UKismetSystemLibrary::QuitGame(world, PC, EQuitPreference::Quit, false);
			UE_LOG(LogTemp, Warning, TEXT("QuitGame Done!"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed When Quiting Game"));
			UE_LOG(LogTemp, Error, TEXT("Because Playercontroller is null or none"));
		}


	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed When Quiting Game"));
		UE_LOG(LogTemp, Error, TEXT("Because world is nullptr or not created"));
	}
}


//TearDown Th menu
void UPauseMenu::BackToGame()
{
	//this->TearDown();
	UE_LOG(LogTemp, Warning, TEXT("I´m gonna Back The Game!"));
	if (MenuInterface != nullptr)
	{
		/*UE_LOG(LogTemp, Warning, TEXT("Back The Game Correctly"));*/
		//Con interfaz es un poco tonto
		//utilizar la interfaz para dirigirte a GI
		// y luego el GI se dirige de nuevo al Pause menu
		//MenuInterface->Cancel();
		
		
		//Sin interfaz utilizando directamente el binding
		TearDown(); 

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Back the game Not Posible"));
		UE_LOG(LogTemp, Error, TEXT("IMenuInterface* MenuInterface is none or nullptr"));
	}
}
