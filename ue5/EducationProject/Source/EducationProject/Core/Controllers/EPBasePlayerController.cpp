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
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
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

