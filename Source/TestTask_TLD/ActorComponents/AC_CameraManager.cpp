// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponents/AC_CameraManager.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAC_CameraManager::UAC_CameraManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAC_CameraManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAC_CameraManager::SwitchToCamera(ACameraActor* NewTarget, float BlendTime, EViewTargetBlendFunction BlendFunc)
{
	if (!NewTarget) return;

	auto* OwnerController = Cast<APlayerController>(GetOwner());
	if (!OwnerController) return;

	/* Change camera by target */
	OwnerController->SetViewTargetWithBlend(NewTarget, BlendTime, BlendFunc, true);
}




