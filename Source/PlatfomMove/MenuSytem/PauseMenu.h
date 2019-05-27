// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class PLATFOMMOVE_API UPauseMenu : public UMenuWidget
{
	GENERATED_BODY()



protected:

	virtual bool  Initialize() override;

private:

	

	//BackBtn
	UPROPERTY(meta = (BindWidget))
	class UButton* BackToGameBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* ReturnToLobbyBtn;




	UFUNCTION()
	void BackToGame();

	UFUNCTION()
	void ReturnLobby(); //Aquí regresamos a main menu es decir regresamos al Lobby
	


};
