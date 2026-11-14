// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BP_CameraTrigger.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "TestTask_TLDPlayerController.h"
#include "ActorComponents/AC_CameraManager.h"


// Sets default values
ACameraTrigger::ACameraTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACameraTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}







