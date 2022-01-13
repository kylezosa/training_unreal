// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataAsset.h"
#include "ItemDataInstance.h"
#include "Net/UnrealNetwork.h"

/**
* UItemEffects Implementations
**/

void UItemEffects::OnLoot_Implementation(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* Looter, class AItemObject* DroppedItem)
{
	// Trigger effects
}

void UItemEffects::OnDrop_Implementation(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* Dropper, class AItemObject* DroppedItem)
{
	// Trigger effects
}

void UItemEffects::OnUse_Implementation(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* User, class UInventoryComponent* InventoryComponent)
{
	// Trigger effects
}

//void UItemDataAsset::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
//{
//	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//	DOREPLIFETIME(UItemDataAsset, Name);
//	DOREPLIFETIME(UItemDataAsset, Thumbnail);
//}