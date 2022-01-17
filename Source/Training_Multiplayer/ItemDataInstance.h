// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
//#include "UObject/UObjectGlobals.h"
//#include "ItemStructs.h"
//#include "Misc/Guid.h"
//#include "ItemDataInstance.generated.h"

/**
 * 
 */
//UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
//class TRAINING_MULTIPLAYER_API UItemDataInstance : public UObject
//{
//	GENERATED_BODY()
//public:
//	// UPROPERTY(Replicated)
//	// uint32 bReplicatedFlag : 1;
//
//	virtual bool IsSupportedForNetworking() const override { return true; }
//
//	UFUNCTION(BlueprintCallable, Category = "Item|DataInstance")
//	void Initialize(class UItemDataAsset* ItemData);
//
//	UFUNCTION(BlueprintCallable, Category = "Item|DataInstance")
//	static UItemDataInstance* CreateItemDataInstance(class UItemDataAsset* ItemData, class UObject* Outer)
//	{
//		UItemDataInstance* newItemDataInstance = NewObject<UItemDataInstance>(Outer, UItemDataInstance::StaticClass());
//		newItemDataInstance->Initialize(ItemData);
//
//		return newItemDataInstance;
//	}
//
//	UPROPERTY(Replicated, EditAnywhere, Instanced, BlueprintReadWrite, Category = "Item|DataInstance")
//	class UItemDataAsset* ItemDataAsset;
//
//	UPROPERTY(Replicated, EditAnywhere, Instanced, BlueprintReadWrite, Category = "Item|DataInstance")
//	class UItemProperties* ItemProperties;
//
//	UPROPERTY(Replicated, EditAnywhere, Instanced, BlueprintReadWrite, Category = "Item|DataInstance")
//	class UItemEffects* ItemEffects;
//
//	UFUNCTION(BlueprintCallable, Category = "Item|DataInstance")
//	static UItemDataInstance* CopyItem(class UItemDataInstance* ItemData, class UObject* Outer)
//	{
//		if (ItemData)
//		{
//			UItemDataInstance* newItemDataInstance = DuplicateObject<UItemDataInstance>(ItemData, Outer);
//
//			return newItemDataInstance;
//		}
//		else
//		{
//			return nullptr;
//		}
//	}
//};