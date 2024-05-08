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
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category="Settings | Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category="Settings | Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category="Settings | Components")
	class UEPContionsComponent* ConditionComponent;
	

public:
	
	

	

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

	void JumpingStart ();
	void JumpingEnd ();
	


	
	

};
