// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "LooterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINING_MULTIPLAYER_API ULooterComponent : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULooterComponent();


};
