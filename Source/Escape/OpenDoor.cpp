// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

#define  OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
    
    // ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
    Super::BeginPlay();
    
    Owner = GetOwner();
    
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    // ...
    
    if (GetPlateTotalMass()>30.f) {
        OpenDoorByObject();
        lastOpenDoorTime=GetWorld()->GetTimeSeconds();
    }
    
    if(GetWorld()->GetTimeSeconds()-lastOpenDoorTime>openDoorDelay)
    {
        CloseDoor();

    }
   
}


void UOpenDoor::OpenDoorByObject()
{
    
    //	auto ownerRotation = Owner->GetTransform().GetRotation();
    //	UE_LOG(LogTemp, Warning, TEXT("owner rotation is %s"), *ownerRotation.ToString());
    
//    const FRotator newRotation = FRotator(0.f, rotationAngle, 0.f);
//    Owner->SetActorRotation(newRotation);
    DoorOpen.Broadcast();
}

void UOpenDoor::CloseDoor()
{
    const auto closeRotation=FRotator(0.f,0.f,0.f);
    Owner->SetActorRotation(closeRotation);
}

const float UOpenDoor::GetPlateTotalMass()
{
    float totalMass=0.f;
    TArray<AActor*> objAActorArray;
    pressurePlate->GetOverlappingActors(OUT objAActorArray);
    if (objAActorArray.Num()>0) {
//        for (int i=0; i<objAActorArray.Num(); i++) {
//            UE_LOG(LogTemp, Warning, TEXT("name is %s"),*objAActorArray[i]->GetName());
//            totalMass+=objAActorArray[i]->FindComponentByClass<UPrimitiveComponent>()->GetMass();
//        }
        for (const auto& actor : objAActorArray) {
            totalMass+=actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
        }
    }
    return totalMass;
    
}

