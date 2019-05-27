// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSytem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"


/**
 * 
 */
class UGameInstance;
class IMenuInterface;

UCLASS()
class PLATFOMMOVE_API UPuzzlePlatformsGameInstance : public UGameInstance , public IMenuInterface
{
	GENERATED_BODY()

public:
	
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);
	

	virtual void Init() override;

	//UFUNCTION(Exec)
	/** Allows other classes to safely Load Menu*/
	UFUNCTION(BlueprintCallable, Category = "UIMenu")
	void LoadMenu();

	UFUNCTION(BlueprintCallable, Category = "UIMenu")
	void LoadPause();

	

	/*
	UFUNCTION(BlueprintCallable, Category = "UIMenu")
	virtual void Host() override;
	UFUNCTION(BlueprintCallable)
	virtual void Join(const FString& Address) override;

*/

	//Main Menu
	UFUNCTION(Exec)	
	void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& Address) override;

	UFUNCTION(Exec)
	void Quit() override;

	

	//UFUNCTION(Exec)
	virtual void ReturnLobby() override;

    //protected:
	// Called when the game starts or when spawned
	UFUNCTION(BlueprintCallable, Category = "UIMenu")
	void GoToLevel(const FString& Address);
	
	

private:
	 
	TSubclassOf<class UUserWidget> MenuClass;

	TSubclassOf<class UUserWidget> PauseClass;


	class UMainMenu* Menu;
	
	class UPauseMenu* Pause;

};
