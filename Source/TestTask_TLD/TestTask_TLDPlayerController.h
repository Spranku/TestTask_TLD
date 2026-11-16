// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestTask_TLDPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;
class UAC_CameraManager;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UENUM(BlueprintType)
enum class EInputMode : uint8
{
	/** Default input mode */
	Default UMETA(DisplayName = "Default"),
	/** 2D input mode */
	Sifu UMETA(DisplayName = "2D"),
	/** TopDown input mode */
	TopDown UMETA(DisplayName = "TopDown")
};

UCLASS(abstract)
class ATestTask_TLDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	ATestTask_TLDPlayerController();

	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UAC_CameraManager> CameraManager;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/* 2D Input Mapping Context */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TObjectPtr<UInputMappingContext> SifuMappingContext;

	/* TopDown Input Mapping Context */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TObjectPtr<UInputMappingContext> TopDownMappingContext;

	UPROPERTY()
	TObjectPtr<UInputMappingContext> CurrentMappingContext;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** If true, the player will use UMG touch controls even if not playing on mobile platforms */
	UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")
	bool bForceTouchControls = false;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Returns true if the player should use UMG touch controls */
	bool ShouldUseTouchControls() const;

public: 

	TObjectPtr<UAC_CameraManager> GetCameraManager() const { return CameraManager; }

	UFUNCTION(BlueprintCallable)
	void SwitchInputContext(EInputMode Mode);
};
