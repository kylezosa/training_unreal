// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter.h"
#include "InventoryComponent.h"
#include "LooterComponent.h"

// Sets default values
ABasicCharacter::ABasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory Component"));
	LooterComponent = CreateDefaultSubobject<ULooterComponent>(TEXT("Looter Component"));
}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName(UEnum::GetValueAsString(PlayerInput::MoveForward)), this, &ABasicCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName(UEnum::GetValueAsString(PlayerInput::MoveRight)), this, &ABasicCharacter::MoveRight);

	PlayerInputComponent->BindAction(FName(UEnum::GetValueAsString(PlayerInput::Jump)), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(FName(UEnum::GetValueAsString(PlayerInput::Jump)), IE_Released, this, &ACharacter::StopJumping);
}

void ABasicCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		// Get Forward Vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);
	}
}

void ABasicCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get Right Vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Value);
	}
}

void ABasicCharacter::Punch()
{
	// Multicast_OnPunch();
	Server_OnPunch();
}

bool ABasicCharacter::Server_OnPunch_Validate()
{
	return true;
}

void ABasicCharacter::Server_OnPunch_Implementation()
{
	// UE_LOG(LogTemp, Warning, TEXT("SERVER ON PUNCH CALLED"));
	Multicast_OnPunch();
}

bool ABasicCharacter::Multicast_OnPunch_Validate()
{
	// UE_LOG(LogTemp, Warning, TEXT("MULTICAST ON VALIDATE"));
	return true;
}

void ABasicCharacter::Multicast_OnPunch_Implementation()
{
	// UE_LOG(LogTemp, Warning, TEXT("MULTICAST ON PUNCH CALLED"));
	OnPunch();
}
//void ABasicCharacter::RequestPunch(UAnimMontage* PunchMontage)
//{
//	MulticastPunch(PunchMontage);
//}
//
//void ABasicCharacter::MulticastPunch(UAnimMontage* PunchMontage)
//{
//	OnPunch(PunchMontage);
//}