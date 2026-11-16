// Copyright Epic Games, Inc. All Rights Reserved.


#include "TestTask_TLDPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "TestTask_TLD.h"
#include "ActorComponents/AC_CameraManager.h"
#include "Widgets/Input/SVirtualJoystick.h"

ATestTask_TLDPlayerController::ATestTask_TLDPlayerController()
{
	CameraManager = CreateDefaultSubobject<UAC_CameraManager>(TEXT("CameraManager"));
}

void ATestTask_TLDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (IsLocalPlayerController() && ShouldUseTouchControls())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogTestTask_TLD, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void ATestTask_TLDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
				CurrentMappingContext = DefaultMappingContext;  
			}
		}
	}
}

bool ATestTask_TLDPlayerController::ShouldUseTouchControls() const
{
	// are we on a mobile platform? Should we force touch?
	return SVirtualJoystick::ShouldDisplayTouchInterface() || bForceTouchControls;
}

void ATestTask_TLDPlayerController::SwitchInputContext(EInputMode Mode)
{
	auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!Subsystem) return;

	/* Remove current */
	if (CurrentMappingContext)
	{
		Subsystem->RemoveMappingContext(CurrentMappingContext);
		CurrentMappingContext = nullptr;
	}

	/* Choice new input by mode */
	TObjectPtr<UInputMappingContext> NewContext = nullptr;
	switch (Mode)
	{
		case EInputMode::Default:  
			NewContext = DefaultMappingContext;  break;
		case EInputMode::Sifu:     
			NewContext = SifuMappingContext;     break;
		case EInputMode::TopDown:  
			NewContext = TopDownMappingContext;  break;
	}

	if (NewContext)
	{
		Subsystem->AddMappingContext(NewContext, 0);
		CurrentMappingContext = NewContext;
	}
}
