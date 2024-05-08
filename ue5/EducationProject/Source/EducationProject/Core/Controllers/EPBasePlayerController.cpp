// Fill out your copyright notice in the Description page of Project Settings.


#include "EPBasePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EducationProject/Core/Characters/EPBaseCharacter.h"

void AEPBasePlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedCharacter = Cast<AEPBaseCharacter>(InPawn);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(AdvancedActionMappingContext, 0);
	}
}

void AEPBasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (true)
	{
		UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEPBasePlayerController::Moving);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AEPBasePlayerController::Looking);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AEPBasePlayerController::SprintStart);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AEPBasePlayerController::SprintEnd);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AEPBasePlayerController::JumpStart);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AEPBasePlayerController::JumpEnd);


	}
	
}

void AEPBasePlayerController::Moving(const FInputActionValue& Value)
{
	CachedCharacter->Move(Value);
}

void AEPBasePlayerController::Looking(const FInputActionValue& Value)
{
	CachedCharacter->Look(Value);
}

void AEPBasePlayerController::SprintStart()
{
	CachedCharacter->SprintStart();
}

void AEPBasePlayerController::SprintEnd()
{
	CachedCharacter->SprintEnd();
}

void AEPBasePlayerController::JumpStart()
{
	CachedCharacter->JumpingStart();
}

void AEPBasePlayerController::JumpEnd()
{
	CachedCharacter->JumpingEnd();
}

