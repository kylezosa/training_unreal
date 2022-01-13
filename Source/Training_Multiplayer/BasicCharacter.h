// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"
#include "BasicCharacter.generated.h"

UCLASS(BlueprintType)
class TRAINING_MULTIPLAYER_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicCharacter")
	float Health{ 5 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicCharacter")
	float PunchDistance{ 100 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicCharacter")
	float PunchRadius{ 80 };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BasicCharacter")
	class UInventoryComponent* InventoryComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BasicCharacter")
	class ULooterComponent* LooterComponent;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveForward(float Value);
	virtual void MoveRight(float Value);

	UFUNCTION(BlueprintCallable, Category = "BasicCharacter")
	void Punch();

	UFUNCTION(BlueprintImplementableEvent, Category = "BasicCharacter")
	void OnPunch();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_OnPunch();
	bool Server_OnPunch_Validate();
	void Server_OnPunch_Implementation();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multicast_OnPunch();
	bool Multicast_OnPunch_Validate();
	void Multicast_OnPunch_Implementation();
};

UENUM()
enum PlayerInput
{
	MoveForward UMETA(DisplayName = "MoveForward"),
	MoveRight UMETA(DisplayName = "MoveRight"),
	Turn UMETA(DisplayName = "Turn"),
	LookUp UMETA(DisplayName = "LookUp"),
	Fire UMETA(DisplayName = "Fire"),
	AlternativeFire UMETA(DisplayName = "AlternativeFire"),
	Jump UMETA(DisplayName = "Jump")
};