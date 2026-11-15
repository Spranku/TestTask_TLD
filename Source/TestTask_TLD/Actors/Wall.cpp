// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Wall.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WallStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallStaticMesh"));
	WallStaticMesh->SetupAttachment(RootComponent);
	/* Ignore nav mesh */
	WallStaticMesh->SetCanEverAffectNavigation(false);

	if(WallMaterial) WallStaticMesh->SetMaterial(0, WallMaterial);

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}


