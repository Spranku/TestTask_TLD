// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_CameraTrigger.generated.h"

class UBoxComponent;

UCLASS()
class TESTTASK_TLD_API ACameraTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraTrigger();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> TriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera settings")
	FName CameraTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera settings")
	float BlendTime = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
