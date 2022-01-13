// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemDataAsset.h"
#include "ItemDataInstance.h"
#include "Net/UnrealNetwork.h"


//UItemDataInstance::UItemDataInstance(const class FObjectInitializer& ObjectInitializer)
//{
//	Super(ObjectInitializer);
//}

void UItemDataInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UItemDataInstance, ItemDataAsset);
	DOREPLIFETIME(UItemDataInstance, ItemProperties);
	DOREPLIFETIME(UItemDataInstance, ItemEffects);
}

void UItemDataInstance::Initialize(class UItemDataAsset* ItemData)
{
	if (ItemData)
	{
		ItemDataAsset = ItemData;

		if (ItemData->ItemPropertiesClass) {
			ItemProperties = NewObject<UItemProperties>(this, ItemData->ItemPropertiesClass);
		}
		else {
			UE_LOG(LogTemp, Fatal, TEXT("Item Properties Class is Invalid"));
		}

		if (ItemData->ItemEffectsClass) {
			ItemEffects = NewObject<UItemEffects>(this, ItemData->ItemEffectsClass);
		}
		else {
			UE_LOG(LogTemp, Fatal, TEXT("Item Effects Class is Invalid"));
		}
	}
}