// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemStructs.generated.h"

USTRUCT(BlueprintType)
struct TRAINING_MULTIPLAYER_API FS_ItemProperties
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

	FS_ItemProperties()
	{
		IsDroppable = true;
		IsAutoLootable = false;
		IsLootable = true;
		IsUsable = false;
		IsStackable = false;
		Quantity = 1;
	}
};