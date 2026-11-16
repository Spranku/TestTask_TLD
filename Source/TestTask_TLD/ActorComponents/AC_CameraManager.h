// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_CameraManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASK_TLD_API UAC_CameraManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_CameraManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main settings")
	TMap<FName, ACameraActor*> CameraRegistry;

	UFUNCTION(BlueprintCallable)
	void SwitchToCamera(ACameraActor* NewTarget, float BlendTime, EViewTargetBlendFunction BlendFunc);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		

};
