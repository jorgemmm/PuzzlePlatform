// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#include "Misc/Guid.h"


#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

//to FClassFinder Platform fro debug
#include "PlatformTrigger.h"

#include "MenuSytem/MenuInterface.h"
#include "MenuSytem/MainMenu.h"
#include "MenuSytem/PauseMenu.h"

#include "Kismet/KismetSystemLibrary.h"


UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Gameinstance Constructor"));

	static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/UI/WB_MainMenu"));
	

	if (MenuBPClass.Class != NULL)
	{
		MenuClass = MenuBPClass.Class;
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Gameinstance Constructor:  Menuclass not founded it"));
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> PauseBPClass(TEXT("/Game/UI/WB_PauseMenu"));

	if (PauseBPClass.Class != NULL)
	{
		PauseClass = PauseBPClass.Class;

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Gameinstance Constructor:  PauseClass not founded it"));
	}
	//To find Platformtrigger class for debug
	/*
	static ConstructorHelpers::FClassFinder<APlatformTrigger> PlatformTriggerBPClass(TEXT("/Game/Blueprints/BP_PlatformTrigger"));

	if (PlatformTriggerBPClass.Class != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *PlatformTriggerBPClass.Class->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlatformTriggerBPClass Not Founded"));
	}
	*/
}


void UPuzzlePlatformsGameInstance::Init()
{
	Super::Init();

	

	UE_LOG(LogTemp, Warning, TEXT("Gameinstance Init"));

	if (MenuClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
		
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MenuClass class is none or null"));
	}
	
}



void UPuzzlePlatformsGameInstance::LoadMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Gameinstance LoadMenu"));

	if (MenuClass)
	{
		//UUserWidget* Menu =	CreateWidget<UUserWidget>(this, MenuClass);
		Menu = CreateWidget<UMainMenu>(this, MenuClass);
		if (Menu != nullptr)
		{
			
			Menu->Setup();

			Menu->SetMenuInterface(this);
		}
		else 
		{
			UE_LOG(LogTemp, Error, TEXT("LobbyMenu (Main Menu) NOT Created!!!"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MenuClass class is none or null"));
	}
	
}

void UPuzzlePlatformsGameInstance::LoadPause()
{
	UE_LOG(LogTemp, Warning, TEXT("Gameinstance Load Pause"));

	if (PauseClass)
	{
		//UUserWidget* Menu =	CreateWidget<UUserWidget>(this, MenuClass);
		//Pause = CreateWidget<UPauseMenu>(this, PauseClass);
		Pause = CreateWidget<UPauseMenu>(this, PauseClass);
		if (Pause != nullptr)		{

			Pause->Setup();

			Pause->SetMenuInterface(this);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Pause Menu  NOT Created!!!"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pause class is none or null"));
	}

}


void UPuzzlePlatformsGameInstance::Host()
{
	
	UE_LOG(LogTemp, Warning, TEXT("puzle platfrom Game instance:: Host.."));
	if (Menu != nullptr) 
	{
		Menu->TearDown();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MainMenu not loaded at Gameinstance::Host"));
		UE_LOG(LogTemp, Error, TEXT("MainMenu not remove at Gameinstance::Host"));
	}
	
	UEngine* Engine = GetEngine();

	//if(Engine)
	if (Engine != nullptr)
	{
		Engine->AddOnScreenDebugMessage(0, 2.0f, FColor::Green, TEXT("Hosting"));

		UWorld* world = GetWorld();

		if (world != nullptr)
		{
			world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");

		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Map content (World) not Loaded"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Engine not Loaded"));
		UE_LOG(LogTemp, Warning, TEXT("Hosting at log"));
	}
	

	
	
	
		// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
		/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("This is an on screen message!"));*/	
}



void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{

	UE_LOG(LogTemp, Warning, TEXT("puzle platfrom Game instance:: Join.."));
	if (Menu != nullptr)
	{
		Menu->TearDown();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MainMenu not loaded at Gameinstance::Join"));
		UE_LOG(LogTemp, Error, TEXT("MainMenu not remove at Gameinstance::Join"));
	}

	UEngine* Engine = GetEngine();
	
	if (Engine != nullptr)
	{
		Engine->AddOnScreenDebugMessage(0, 2.0f, FColor::Green, FString::Printf(TEXT("Joining  %s"), *Address )); 
		
	}

	APlayerController* PC = GetFirstLocalPlayerController();

	if(PC)	
	{
		
		PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Playercontroller not Loaded at Joining"));
		
		Engine->AddOnScreenDebugMessage(0, 2.0f, FColor::Green, TEXT("Playercontroller not Loaded at Joining"));

	}


}

void UPuzzlePlatformsGameInstance::Quit()
{
	  UE_LOG(LogTemp, Warning, TEXT("Game instance:: Quit Game.."))

		
			APlayerController* PC = GetFirstLocalPlayerController();
			if(PC!=nullptr)
			{
				//PC->ConsoleCommand("quit");
				UWorld* world = GetWorld();
				if (world)
				{
					UKismetSystemLibrary::QuitGame(world, PC, EQuitPreference::Quit, false);
					
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT(" Quit Game not posible At GI"));
					UE_LOG(LogTemp, Error, TEXT("Because UWorld* is nullptr or none at Gameinstance"));
				}			
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT(" Quit Game not posible At GI"));
				UE_LOG(LogTemp, Error, TEXT("Because APlayerController is nullptr or none at Gameinstance"));
			}
			
			
		
}

void UPuzzlePlatformsGameInstance::ReturnLobby()
{
	UE_LOG(LogTemp, Warning, TEXT("puzle platform Game instance:: Quit Pause.."));

	UEngine* Engine = GetEngine();
	UWorld* world = GetWorld();

	//if (world)
	//{
	//	
	//	ReturnToMainMenu();	//Retorna al mapa establecido como default en maps & Modes	
	//	LoadMenu();
	//}
	
	APlayerController* PC = GetFirstLocalPlayerController();

	if (PC)
	{
		PC->ClientTravel("/Game/Maps/MainMenu", ETravelType::TRAVEL_Absolute);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Playercontroller not Loaded at Joining"));

		Engine->AddOnScreenDebugMessage(0, 2.0f, FColor::Green, TEXT("Playercontroller not Loaded at Joining"));

	}

	
}

void UPuzzlePlatformsGameInstance::GoToLevel(const FString& Address)
{
	//Exmaple Address: "/Game/Maps/Lobby" or "/Game/Maps/Lobby?listen"
	UE_LOG(LogTemp, Warning, TEXT("Gameinstance BeginPlay"));

	UWorld* world = GetWorld();

	if (world!=nullptr)
	{
		if(world->ServerTravel(*Address))
		{
			//Nor implemented yet
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ServerTravel Not Travelled to EmptyMap"));
 		}

	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Map content (World) not Loaded at BeginPlay"));
	}

	
}



