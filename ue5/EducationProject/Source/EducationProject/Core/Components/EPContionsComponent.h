// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EPContionsComponent.generated.h"


class UEPCharacterMovementComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EDUCATIONPROJECT_API UEPContionsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UEPContionsComponent();

	void SetSprintingCondition (bool IsSprinting);
	bool GetSprintingCondition () const {return  bIsSprinting;}

	void SetTiredCondition (bool IsTired);
	bool GetTiredCondition () const {return  bIsTired;}
	
	void ChangeSpeedModifier (float NewSpeedModifier);

protected:

private:

	TWeakObjectPtr<class AEPBaseCharacter> CharacterOwner;
	UEPCharacterMovementComponent* CharacterMovementComponent;
	

	bool bIsSprinting;
	bool bIsTired;

	float SpeedModifier = 0.1f;
	
	
		
};
