#pragma once

#include "CoreMinimal.h"
#include "ChaosWheeledVehiclePawn.h"
#include "PlayerCar.generated.h"

UCLASS()
class CARGAMERACING_API APlayerCar : public AChaosWheeledVehiclePawn
{
    GENERATED_BODY()

public:
    APlayerCar();

protected:
    virtual void BeginPlay() override;

public:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Input functions
    void Throttle(float Value);
    void Steer(float Value);
    void Brake(float Value);
};
