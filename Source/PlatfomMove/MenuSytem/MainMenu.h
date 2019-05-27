// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PLATFOMMOVE_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:

	

protected:
	
	virtual bool  Initialize() override;

private:


	//Buttons
	//Buttons Host-Join Main menu
	UPROPERTY(meta = (BindWidget))
	class UButton* HostBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* OpenJoinMenuBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* OpenQuitMenuBtn;



	//Butttons Join Back
	UPROPERTY(meta = (BindWidget))
	class UButton* BackBtn;


	UPROPERTY(meta = (BindWidget))
	class UButton* JoinBtn;



	//Butttons Quit Back 
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelQuitBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitGameBtn;



	//Switcher Wd	and 3 slots Uwidgets: Main menu, Pause menu and quit menu
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	//Slot  MainMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	//Slot  JoinMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;	

	//Slot  QuitMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* QuitMenu;

	//Texbox
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* TxtBoxIP;
	
	/*UPROPERTY(meta = (BindWidget))
	class FText* TxtIP;*/
	

	UFUNCTION()
	void HostServer();	
	
	UFUNCTION()
	void OpenJoinMenu();
	
	UFUNCTION()
	void OpenQuitMenu();


	UFUNCTION()
	void BackToMainMenu();

	UFUNCTION()
	void JoinToServer();

	UFUNCTION()
	void QuitGame();
	

};
