// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "ItemDataInstance.h"
#include "ItemDataAsset.h"
#include "ItemObject.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

//void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
//{
//	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//	DOREPLIFETIME_CONDITION(UInventoryComponent, Capacity, COND_OwnerOnly);
//	DOREPLIFETIME_CONDITION(UInventoryComponent, Items, COND_OwnerOnly);
//}

//bool UInventoryComponent::ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags) const
//{
//	bool replicate = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);
//
//	for (UItemDataInstance* Item : Items)
//	{
//		if (!Item)
//			continue;
//
//		replicate |= Channel->ReplicateSubobject(Item, *Bunch, *RepFlags);
//	}
//}

bool UInventoryComponent::IsFull()
{
	UE_LOG(LogTemp, Log, TEXT("Inventory > Is Full : %s"), Items.Num() >= Capacity ? "true" : "false");
	return Items.Num() >= Capacity;
}

bool UInventoryComponent::AddItem(class UItemDataInstance* ItemToAdd)
{
	if (!ItemToAdd)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inventory > Add Item > Item is Invalid"));
		return false;
	}
	else if (Items.Num() >= Capacity)
	{
		UE_LOG(LogTemp, Log, TEXT("Inventory > Add Item > Could not add item: At max cap (%d)"), Capacity);
		return false;
	}
	else
	{
		if (ItemToAdd->ItemDataAsset)
		{
			UE_LOG(LogTemp, Log, TEXT("Inventory > Add Item > Attempting to add %s"), *ItemToAdd->ItemDataAsset->Name.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Inventory > Add Item > Item Data Asset NOT FOUND."));
		}

		// Change Outer to owner of inventory.
		if (GetOwner())
		{
			ItemToAdd->Rename(nullptr, GetOwner()->GetOuter(), REN_None);
		}

		UE_LOG(LogTemp, Log, TEXT("Inventory > Add Item > Item added."));
		Items.Add(ItemToAdd);
		OnInventoryUpdate.Broadcast();
		return true;
	}
}

bool UInventoryComponent::RemoveItem(class UItemDataInstance* ItemToRemove)
{
	if (!ItemToRemove)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inventory > Remove Item > Item is Invalid"));
		return false;
	}
	else if (Items.Contains(ItemToRemove))
	{
		UE_LOG(LogTemp, Log, TEXT("Inventory > Item removed."));
		Items.Remove(ItemToRemove);
		OnInventoryUpdate.Broadcast();
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Inventory > No item was removed."));
		return false;
	}
}

//void UInventoryComponent::UseItem(class UItemDataInstance* ItemToUse, class ABasicCharacter* User)
//{
//	ItemToUse->ItemEffects->OnUse(ItemToUse, User, this);
//}
//
//void UInventoryComponent::DropItem(class UItemDataInstance* ItemToDrop, class ABasicCharacter* Dropper, FVector Location, FRotator Rotation)
//{
//	if (GetWorld())
//	{
//		GetWorld
//		ItemToDrop->ItemEffects->OnDrop(ItemToDrop, Dropper);
//	}
//}

TArray<class UItemDataInstance*> UInventoryComponent::AddItems(TArray<class UItemDataInstance*> ItemsToAdd)
{
	TArray<class UItemDataInstance*> unaddedItems;
	for (int i = 0; i < ItemsToAdd.Num(); i++)
	{
		if (!ItemsToAdd[i])
		{
			UE_LOG(LogTemp, Warning, TEXT("Inventory > Add Items > Item %d is Invalid"), i);
			continue;
		}
		else if (IsFull())
		{
			unaddedItems.Add(ItemsToAdd[i]);
		}
		else
		{
			// Change Outer to owner of inventory.
			if (GetOwner())
			{
				ItemsToAdd[i]->Rename(nullptr, GetOwner()->GetOuter(), REN_None);
			}

			Items.Add(ItemsToAdd[i]);
		}
	}

	if (unaddedItems.Num() < ItemsToAdd.Num() && ItemsToAdd.Num() > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Inventory > %d items added."), ItemsToAdd.Num() - unaddedItems.Num());
		OnInventoryUpdate.Broadcast();
	}

	UE_LOG(LogTemp, Log, TEXT("Inventory > %d items were not added."), unaddedItems.Num());
	return unaddedItems;
}

TArray<class UItemDataInstance*> UInventoryComponent::RemoveItems(TArray<class UItemDataInstance*> ItemsToRemove)
{
	TArray<class UItemDataInstance*> unmovedItems;

	for (int i = 0; i < ItemsToRemove.Num(); i++)
	{
		if (!ItemsToRemove[i])
		{
			continue;
			UE_LOG(LogTemp, Warning, TEXT("Inventory > Remove Items > Item %d is Invalid"), i);
		}
		else if (Items.Remove(ItemsToRemove[i]) < 0)
		{
			unmovedItems.Add(ItemsToRemove[i]);
		}
	}

	if (unmovedItems.Num() < ItemsToRemove.Num() && ItemsToRemove.Num() > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Inventory > %d items were removed."), ItemsToRemove.Num() - unmovedItems.Num());
		OnInventoryUpdate.Broadcast();
	}
	UE_LOG(LogTemp, Log, TEXT("Inventory > %d items were not removed."), unmovedItems.Num());

	return unmovedItems;
}