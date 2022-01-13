// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LooterComponent.h"
#include "ItemObject.generated.h"

// ITEM
UCLASS(BlueprintType)
class TRAINING_MULTIPLAYER_API AItemObject : public AActor, public ILootableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemObject();

	virtual bool ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags) override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Instanced, Category = "Item|Object")
	class UItemDataInstance* ItemDataInstance;
};