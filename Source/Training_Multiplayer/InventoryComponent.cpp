// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "ItemDataAsset.h"
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

bool UInventoryComponent::AddItem(FItemDataInstance ItemToAdd)
{
	if (!ItemToAdd.IsValid())
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
		UE_LOG(LogTemp, Log, TEXT("Inventory > Add Item > Item added."));
		Items.Add(ItemToAdd);
		OnInventoryUpdate.Broadcast();
		return true;
	}
}

bool UInventoryComponent::RemoveItem(FItemDataInstance ItemToRemove)
{
	if (!ItemToRemove.IsValid())
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

TArray<FItemDataInstance> UInventoryComponent::AddItems(TArray<FItemDataInstance> ItemsToAdd)
{
	TArray<FItemDataInstance> unaddedItems;
	for (int i = 0; i < ItemsToAdd.Num(); i++)
	{
		if (!ItemsToAdd[i].IsValid())
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

TArray<FItemDataInstance> UInventoryComponent::RemoveItems(TArray<FItemDataInstance> ItemsToRemove)
{
	TArray<FItemDataInstance> unmovedItems;

	for (int i = 0; i < ItemsToRemove.Num(); i++)
	{
		if (!ItemsToRemove[i].IsValid())
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