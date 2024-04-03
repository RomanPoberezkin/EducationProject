// Fill out your copyright notice in the Description page of Project Settings.


#include "EPBaseCharacter.h"
#include "EducationProject/Core/Components/Movement/EPCharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


AEPBaseCharacter::AEPBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super (ObjectInitializer.SetDefaultSubobjectClass<UEPCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f; 
	SpringArm->bUsePawnControlRotation = true;

	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
}


void AEPBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEPBaseCharacter::BeginPlay()
{
	Super::BeginPlay();	
	
}

void AEPBaseCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AEPBaseCharacter::Look(const FInputActionValue& Value)
{
	auto LookVector = Value.Get<FVector2D>();

	if (Controller!=nullptr)
	{
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}
}

void AEPBaseCharacter::SprintStart()
{
}

void AEPBaseCharacter::SprintEnd()
{
}

// Called every frame
void AEPBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



