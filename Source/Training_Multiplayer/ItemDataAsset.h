// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemStructs.h"
#include "ItemDataAsset.generated.h"

//UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
//class TRAINING_MULTIPLAYER_API UItemProperties : public UObject
//{
//	GENERATED_BODY()
//public:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
//	bool IsDroppable{ true };
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
//	bool IsLootable{ true };
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
//	bool IsAutoLootable{ false };
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
//	bool IsUsable{ false };
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
//	bool IsStackable{ false };
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
//	int Quantity{ 1 };
//};
//
//UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
//class TRAINING_MULTIPLAYER_API UItemEffects : public UObject
//{
//	GENERATED_BODY()
//public:
//
//	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item|Effects")
//	void OnLoot(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* Looter, class AItemObject* DroppedItem);
//	virtual void OnLoot_Implementation(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* Looter, class AItemObject* DroppedItem);
//
//	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item|Effects")
//	void OnDrop(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* Dropper, class AItemObject* DroppedItem);
//	virtual void OnDrop_Implementation(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* Dropper, class AItemObject* DroppedItem);
//
//	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item|Effects")
//	void OnUse(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* User, class UInventoryComponent* InventoryComponent);
//	virtual void OnUse_Implementation(class UItemDataInstance* ItemDataInstance, class ABasicCharacter* User, class UInventoryComponent* InventoryComponent);
//};
//
//UCLASS(BlueprintType)
//class TRAINING_MULTIPLAYER_API UItemDataAsset : public UDataAsset
//{
//	GENERATED_BODY()
//
//public:
//	virtual bool IsSupportedForNetworking() const override { return true; }
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	FText Name;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	FText Description;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	FText Tooltip;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	FText Context;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	class UTexture2D* Thumbnail;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	TSubclassOf<class UItemProperties> ItemPropertiesClass;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	TSubclassOf<class UItemEffects> ItemEffectsClass;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	TSubclassOf<class AItemObject> ItemObjectClass;
//
//	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "Item|DataAsset")
//	UItemProperties* ItemProperties;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
//	UItemEffects* ItemEffects;
//};

// USING STRUCTURES

UCLASS(BlueprintType)
class TRAINING_MULTIPLAYER_API UItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual bool IsSupportedForNetworking() const override { return true; }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	FText Tooltip;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	FText Context;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	class UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	TSubclassOf<class AItemObject> ItemObjectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset")
	FItemProperties ItemProperties;
};

UENUM()
enum EEquipmentType
{
	Head UMETA(DisplayName="Head"),
	Body UMETA(DisplayName = "Body"),
	Weapon_L UMETA(DisplayName = "Left-hand Only Weapon"),
	Weapon_R UMETA(DisplayName = "Right-hand Only Weapon"),
	Weapon_D UMETA(DisplayName = "Two-handed Weapon"),
	Weapon_A UMETA(DisplayName = "Single-handed Weapon"),
};

UCLASS(BlueprintType)
class TRAINING_MULTIPLAYER_API UEquipmentDataAsset : public UItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|DataAsset|Equipment")
	TEnumAsByte<EEquipmentType> EquipmentType;
};