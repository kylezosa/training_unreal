// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"

#include "UObject/Interface.h"

#include "LooterComponent.generated.h"

// DROPPABLE INTERFACE
UINTERFACE(MinimalAPI)
class UDroppableInterface : public UInterface
{
	GENERATED_BODY()
};

class TRAINING_MULTIPLAYER_API IDroppableInterface
{
	GENERATED_BODY()
public:
};

// LOOTABLE INTERFACE
UINTERFACE(MinimalAPI, Blueprintable)
class ULootableInterface : public UInterface
{
	GENERATED_BODY()
};

class TRAINING_MULTIPLAYER_API ILootableInterface
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Lootable")
	bool IsLootable();
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINING_MULTIPLAYER_API ULooterComponent : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULooterComponent();


};
