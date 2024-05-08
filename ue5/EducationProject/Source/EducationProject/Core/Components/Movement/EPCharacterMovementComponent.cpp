// Fill out your copyright notice in the Description page of Project Settings.


#include "EPCharacterMovementComponent.h"

UEPCharacterMovementComponent::UEPCharacterMovementComponent()
{
	
	DefaultWalkingSpeed=BaseWalkingSpeed;
	DefaultSprintingSpeed=BaseSprintingSpeed;
	SetCurrentWalkingSpeed(DefaultWalkingSpeed);
	SetCurrentSprintingSpeed(DefaultSprintingSpeed);
	
}

void UEPCharacterMovementComponent::SetCurrentWalkingSpeed(float NewWalkingSpeed)
{
	CurrentWalkingSpeed=FMath::Clamp(NewWalkingSpeed, 0, DefaultWalkingSpeed);
}

void UEPCharacterMovementComponent::SetCurrentSprintingSpeed(float NewSprintingSpeed)
{
	CurrentSprintingSpeed=FMath::Clamp(NewSprintingSpeed, 0, DefaultSprintingSpeed);
}

void UEPCharacterMovementComponent::SprintStart()
{
	MaxWalkSpeed=CurrentSprintingSpeed;	
}

void UEPCharacterMovementComponent::SprintEnd()
{
	MaxWalkSpeed=CurrentWalkingSpeed;
}

void UEPCharacterMovementComponent::UpdateSpeedSettings(float SpeedModifier)
{
	SetCurrentWalkingSpeed(DefaultWalkingSpeed*SpeedModifier);
	SetCurrentSprintingSpeed(DefaultSprintingSpeed*SpeedModifier);
}
