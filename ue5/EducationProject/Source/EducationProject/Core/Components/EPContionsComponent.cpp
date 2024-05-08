// Fill out your copyright notice in the Description page of Project Settings.


#include "EPContionsComponent.h"

#include "EducationProject/Core/Characters/EPBaseCharacter.h"
#include "Movement/EPCharacterMovementComponent.h"


UEPContionsComponent::UEPContionsComponent()
{
	CharacterOwner = Cast<AEPBaseCharacter>(GetOwner());
	if (CharacterOwner.IsValid())
	{
		CharacterMovementComponent=Cast<UEPCharacterMovementComponent>( CharacterOwner->GetMovementComponent());
	}
}

void UEPContionsComponent::SetSprintingCondition(bool IsSprinting)
{
	bIsSprinting=IsSprinting;
	
}

void UEPContionsComponent::SetTiredCondition(bool IsTired)
{
	bIsTired=IsTired;
	if (bIsTired)
	{
		if (bIsSprinting)
		{
			CharacterOwner->SprintEnd();
		}
	}
}

void UEPContionsComponent::ChangeSpeedModifier(float NewSpeedModifier)
{
	SpeedModifier=NewSpeedModifier;
	CharacterMovementComponent->UpdateSpeedSettings(SpeedModifier);
}
