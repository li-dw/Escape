// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


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
    defaultPawn=GetWorld()->GetFirstPlayerController()->GetPawn();
    
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    // ...
    
    if (pressurePlate->IsOverlappingActor(defaultPawn)) {
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
    
    const FRotator newRotation = FRotator(0.f, rotationAngle, 0.f);
    Owner->SetActorRotation(newRotation);
}

void UOpenDoor::CloseDoor()
{
    const auto closeRotation=FRotator(0.f,0.f,0.f);
    Owner->SetActorRotation(closeRotation);
}


