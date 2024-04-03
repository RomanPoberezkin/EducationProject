// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EPBaseCharacter.generated.h"

struct FInputActionValue;
class UInputAction;

UCLASS()
class EDUCATIONPROJECT_API AEPBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEPBaseCharacter(const FObjectInitializer& ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category="Settings | Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category="Settings | Camera")
	class UCameraComponent* CameraComponent;

public:
	
	//INPUT
	
	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | Input")
	UInputAction* Moving;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | Input")
	UInputAction* Looking;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | Input")
	UInputAction* Sprint;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | Input")
	UInputAction* Crouching;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category= "Settings | Input")
	UInputAction* Jumping;

	

public:	
	

private:

	class UEPCharacterMovementComponent* CharacterMovement;

	bool bIsSprinting;

protected:

public:
	
	void Move (const FInputActionValue& Value);
	void Look (const FInputActionValue& Value);
	void SprintStart ();
	void SprintEnd ();
	


	
	

};
