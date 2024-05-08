// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "EPCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class EDUCATIONPROJECT_API UEPCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	
	UEPCharacterMovementComponent();

	void SetCurrentWalkingSpeed (float NewWalkingSpeed);
	void SetCurrentSprintingSpeed (float NewSprintingSpeed);
	
	float GetCurrentWalkingSpeed () const {return  CurrentWalkingSpeed;}
	float GetCurrentSprintingSpeed () const {return  CurrentSprintingSpeed;}

	void SprintStart ();
	void SprintEnd ();

	void UpdateSpeedSettings (float SpeedModifier);

protected:
	
	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | SpeedSettings")
	float BaseWalkingSpeed = 500.0f;
	
	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | SpeedSettings")
	float BaseSprintingSpeed = 1200.0f;


private:

	float DefaultWalkingSpeed;
	float CurrentWalkingSpeed;

	float DefaultSprintingSpeed;
	float CurrentSprintingSpeed;
	
};