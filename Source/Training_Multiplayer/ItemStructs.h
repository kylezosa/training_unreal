// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/Guid.h"
#include "ItemStructs.generated.h"

USTRUCT(BlueprintType)
struct TRAINING_MULTIPLAYER_API FItemProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S_ItemProperties")
		bool IsDroppable{ true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S_ItemProperties")
		bool IsLootable{ true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S_ItemProperties")
		bool IsAutoLootable{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S_ItemProperties")
		bool IsUsable{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S_ItemProperties")
		bool IsStackable{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S_ItemProperties")
		int Quantity{ 1 };

	FItemProperties()
	{
		IsDroppable = true;
		IsAutoLootable = false;
		IsLootable = true;
		IsUsable = false;
		IsStackable = false;
		Quantity = 1;
	}
};

USTRUCT(BlueprintType)
struct TRAINING_MULTIPLAYER_API FItemDataInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|DataInstance")
	FGuid ItemInstanceID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|DataInstance")
	class UItemDataAsset* ItemDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|DataInstance")
	struct FItemProperties ItemProperties;

	FItemDataInstance()
	{
		ItemInstanceID = FGuid::NewGuid();
	}

	bool IsValid()
	{
		return ItemInstanceID.IsValid() && ItemDataAsset;
	}

	bool operator==(const FItemDataInstance& rhs)
	{
		return ItemInstanceID.IsValid() && rhs.ItemInstanceID.IsValid() && ItemInstanceID == rhs.ItemInstanceID;
	}

	friend bool operator==(const FItemDataInstance& lhs, const FItemDataInstance& rhs)
	{
		return lhs.ItemInstanceID.IsValid() && rhs.ItemInstanceID.IsValid() && lhs.ItemInstanceID == rhs.ItemInstanceID;
	}
};