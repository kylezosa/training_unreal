// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemStructs.h"

#include "UObject/Interface.h"

#include "ItemObject.generated.h"


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


// ITEM
UCLASS(BlueprintType)
class TRAINING_MULTIPLAYER_API AItemObject : public AActor, public ILootableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemObject();

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Item|Object")
	FItemDataInstance ItemDataInstance;
};