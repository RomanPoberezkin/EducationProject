// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EPLedgeDetectionComponent.generated.h"

USTRUCT(BlueprintType)
struct FLedgeInfo
{
	GENERATED_BODY()

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Ledge info")
	FVector Location;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Ledge info")
	FVector LedgeNormal;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Ledge info")
	FRotator Rotation;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Ledge info")
	UPrimitiveComponent* PrimitiveComponent;	
	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EDUCATIONPROJECT_API UEPLedgeDetectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	void DetectHookedLocation ();
	


};
