// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"

#include "Components/WidgetSwitcher.h"
#include "Components/Widget.h"


#include "Components/EditableTextBox.h"
#include "Internationalization/Text.h"



bool  UMainMenu::Initialize()
{	
   bool Succes = Super::Initialize();
   if (Succes != true) return false;

   //TODO: Setup

  //Buttons Host-Join Main menu
   if (HostBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Host Button Clickled"));
	   HostBtn->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Host Button  Not Binding"));
   }

  
   if (OpenJoinMenuBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Join Button Clickled"));
	   OpenJoinMenuBtn->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Join Button  Not Binding"));
   }


   if (OpenQuitMenuBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Quit Button Clickled"));
	   OpenQuitMenuBtn->OnClicked.AddDynamic(this, &UMainMenu::OpenQuitMenu);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Quit Button  Not Binding"));
   }





   //Butttons Join Menu
   if (BackBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Back Button Clickled"));
	   BackBtn->OnClicked.AddDynamic(this, &UMainMenu::BackToMainMenu);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Back Button  Not Binding"));
   }

   
   if (JoinBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Back Button Clickled"));
	   JoinBtn->OnClicked.AddDynamic(this, &UMainMenu::JoinToServer);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Back Button  Not Binding"));
   }

   


   if (CancelQuitBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Back Button Clickled"));
	   CancelQuitBtn->OnClicked.AddDynamic(this, &UMainMenu::BackToMainMenu);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Back Button  Not Binding"));
   }

   if (QuitGameBtn != nullptr)
   {
	   UE_LOG(LogTemp, Warning, TEXT("Back Button Clickled"));
	   QuitGameBtn->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
   }
   else
   {
	   UE_LOG(LogTemp, Error, TEXT("Back Button  Not Binding"));
   }


   return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I´m gonna host a server!"));
	if (MenuInterface != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Host Interface Correct Done "));
		MenuInterface->Host();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Host Interface Failed!!! "));

	}

}


void UMainMenu::OpenJoinMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("I´m gonna switch to Join Menu!"));
	
	//if( Address == Address.Empty) 
		//Address = FString(TEXT("192.168.0.156"));

	if (MenuInterface != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Menu Interface Correct Done "));
		//MenuInterface->Join(Address);

		if (JoinMenu != nullptr) 
		{
			MenuSwitcher->SetActiveWidget(JoinMenu);
			UE_LOG(LogTemp, Warning, TEXT("Join Menu Switched Correct Done "));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Join Menu Switcher Failed!!! "));
			UE_LOG(LogTemp, Error, TEXT("Because UWidget* Join Menu Not Loaded !!! "));
		}
		
		

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Join Menu Switcher Failed!!! "));
		UE_LOG(LogTemp, Error, TEXT("Because IMenuInterface* MenuInterface Not Loaded !!! "));
		//UE_LOG(LogTemp, Error, TEXT("Join Interface Failed!!! "));
	}
}


void UMainMenu::OpenQuitMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("I´m gonna switch to Join Menu!"));

	//if( Address == Address.Empty) 
		//Address = FString(TEXT("192.168.0.156"));

	if (MenuInterface != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Menu Interface Correct Done "));
		//MenuInterface->Join(Address);

		if (QuitMenu != nullptr)
		{
			MenuSwitcher->SetActiveWidget(QuitMenu);
			UE_LOG(LogTemp, Warning, TEXT("Join Menu Switched Correct Done "));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Join Menu Switcher Failed!!! "));
			UE_LOG(LogTemp, Error, TEXT("Because UWidget* Join Menu Not Loaded !!! "));
		}



	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Join Menu Switcher Failed!!! "));
		UE_LOG(LogTemp, Error, TEXT("Because IMenuInterface* MenuInterface Not Loaded !!! "));
		//UE_LOG(LogTemp, Error, TEXT("Join Interface Failed!!! "));
	}
}



void UMainMenu::BackToMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("I´m gonna switch to Main Menu!"));

	

	if (MenuInterface != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Menu Interface Correct Done "));
		//MenuInterface->Join(Address);

		if (MainMenu != nullptr)
		{
			MenuSwitcher->SetActiveWidget(MainMenu);
			UE_LOG(LogTemp, Warning, TEXT("Main Menu Switched Correct Done "));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Main Menu Switcher Failed!!! "));
			UE_LOG(LogTemp, Error, TEXT("Because UWidget* Main Menu Not Loaded !!! "));
		}



	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Main Menu Switcher Failed!!! "));
		UE_LOG(LogTemp, Error, TEXT("Because IMenuInterface* MenuInterface Not Loaded !!! "));
		//UE_LOG(LogTemp, Error, TEXT("Join Interface Failed!!! "));
	}

}

void UMainMenu::JoinToServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I´m gonna Join a server!"));
	if (MenuInterface != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Join Interface Correct Done "));
		
		if (TxtBoxIP != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("TxtBoxIP Correct Done "));
			if (!TxtBoxIP->GetText().IsEmpty()) 
			{
				UE_LOG(LogTemp, Warning, TEXT("IP loaded it Correct"));

				MenuInterface->Join(TxtBoxIP->GetText().ToString());
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Please write a IP!!! "));
			}		
				
		
		}else
		{
			UE_LOG(LogTemp, Error, TEXT("Join To server Failed!!! "));
			UE_LOG(LogTemp, Error, TEXT("Because UEditableTextBox *TxtBoxIP* Not Loaded !!! "));
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Join Interface Failed!!! "));
		UE_LOG(LogTemp, Error, TEXT("Because IMenuInterface* MenuInterface Not Loaded !!! "));
	}
}

void UMainMenu::QuitGame()
{
	UWorld* world = GetWorld();


	if (world != nullptr)	{


		APlayerController* PC = world->GetFirstPlayerController(); //Uworld method
		//GetFirstLocalPlayerController(); GI method
		if (PC != nullptr)
		{
			MenuInterface->Quit();
			//PC->ConsoleCommand("quit"); En Course online
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
