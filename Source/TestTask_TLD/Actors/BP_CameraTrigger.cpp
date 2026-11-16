// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BP_CameraTrigger.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Character.h"
#include "Core/AIControllerNPC.h"
#include "TestTask_TLDPlayerController.h"
#include "ActorComponents/AC_CameraManager.h"


// Sets default values
ACameraTrigger::ACameraTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(TriggerBox);
}

void ACameraTrigger::OnTriggerSpawnNPC()
{
	if (SpawnedNPC || !GetWorld() || !NPCClass) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	/* Spawn NPC by NPSClass from BP */
	SpawnedNPC = GetWorld()->SpawnActor<ACharacter>(NPCClass, SpawnPoint->GetComponentLocation(), SpawnPoint->GetComponentRotation(), SpawnParams);
	if (!SpawnedNPC) { UE_LOG(LogTemp, Error, TEXT("ACameraTrigger::OnTriggerSpawnNPC - Failed to spawn NPC")); }
}

// Called when the game starts or when spawned
void ACameraTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}







