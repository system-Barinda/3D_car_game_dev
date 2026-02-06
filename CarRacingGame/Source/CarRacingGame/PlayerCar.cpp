#include "PlayerCar.h"
#include "Components/InputComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"

APlayerCar::APlayerCar()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APlayerCar::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCar::Throttle);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCar::Steer);
    PlayerInputComponent->BindAxis("Brake", this, &APlayerCar::Brake);
}

void APlayerCar::Throttle(float Value)
{
    if (auto* MoveComp = GetVehicleMovementComponent())
    {
        MoveComp->SetThrottleInput(Value);
    }
}

void APlayerCar::Steer(float Value)
{
    if (auto* MoveComp = GetVehicleMovementComponent())
    {
        MoveComp->SetSteeringInput(Value);
    }
}

void APlayerCar::Brake(float Value)
{
    if (auto* MoveComp = GetVehicleMovementComponent())
    {
        MoveComp->SetBrakeInput(Value);
    }
}
