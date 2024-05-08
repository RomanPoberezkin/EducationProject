// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EPBasePlayerController.generated.h"

struct FInputActionValue;
class AEPBaseCharacter;
class UInputAction;
/**
 * 
 */
UCLASS()
class EDUCATIONPROJECT_API AEPBasePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void SetPawn(APawn* InPawn) override;
	virtual void SetupInputComponent() override;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category = "Settings | Input")
	class UInputMappingContext* AdvancedActionMappingContext;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* MoveAction;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* LookAction;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* SprintAction;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* JumpAction;

private:

	TWeakObjectPtr<AEPBaseCharacter> CachedCharacter;
	

	void Moving( const FInputActionValue& Value);
	void Looking( const FInputActionValue& Value);
	void SprintStart();
	void SprintEnd ();
	void JumpStart ();
	void JumpEnd ();
	

	
};
