// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemStructs.h"
#include "InventoryComponent.generated.h"

// Foward Declarations
//class UItemDataInstance;
//class UItemObject;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdate);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TRAINING_MULTIPLAYER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	int32 Capacity{50};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FItemDataInstance> Items;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdate OnInventoryUpdate;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool IsFull();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(FItemDataInstance ItemToAdd);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(FItemDataInstance ItemToRemove);

	//UFUNCTION(BlueprintCallable, Category = "Inventory")
	//void UseItem(class UItemDataInstance* ItemToUse, class ABasicCharacter* User);

	//UFUNCTION(BlueprintCallable, Category = "Inventory")
	//void DropItem(class UItemDataInstance* ItemToDrop, class ABasicCharacter* Dropper);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FItemDataInstance> AddItems(TArray<FItemDataInstance> ItemsToAdd);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FItemDataInstance> RemoveItems(TArray<FItemDataInstance> ItemsToRemove);
};
