// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenDoor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseDoor);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPE_API UOpenDoor : public UActorComponent
{
    GENERATED_BODY()
    
public:
    // Sets default values for this component's properties
    UOpenDoor();
    
protected:
    // Called when the game starts
    virtual void BeginPlay() override;
    
public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    UPROPERTY(BlueprintAssignable)
    FOnOpenDoor DoorOpen;
    
    UPROPERTY(BlueprintAssignable)
    FOnCloseDoor OnClose;
    
private:
    UPROPERTY(VisibleAnywhere)
    AActor* Owner;
//    UPROPERTY(VisibleAnywhere)
//    float rotationAngle = -60.f;
    UPROPERTY(EditAnywhere)
    ATriggerVolume* pressurePlate;
    
//    UPROPERTY(EditAnywhere)
//    AActor* defaultPawn;
    
//    UPROPERTY(EditAnywhere)
//    float openDoorDelay=1.f;
//    
//    float lastOpenDoorTime;
    
//    void OpenDoorByObject();
    
    UPROPERTY(EditAnywhere)
    float totalmass=30.f;
//    void CloseDoor();
    const float GetPlateTotalMass();
};
