// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
//    physicsHandle=GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    physicsHandle=GetWorld()->GetFirstPlayerController()->GetPawn()->FindComponentByClass<UPhysicsHandleComponent>();
    if(physicsHandle)
    {
        
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("can't find PhysicsHandleComponent"));
    }
    
    inputHandle=GetOwner()->FindComponentByClass<UInputComponent>();
    if(inputHandle)
    {
        UE_LOG(LogTemp, Warning, TEXT("had found inputComponent"));
        inputHandle->BindAction("Grab", IE_Pressed, this,&UGrabber::Grab);
        inputHandle->BindAction("Release", IE_Released, this, &UGrabber::Release);
    }
    else
    {
        
    }
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
    FVector viewVecotr;
    FRotator viewRotator;
    
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT viewVecotr, OUT viewRotator);
    
    /*UE_LOG(LogTemp, Warning, TEXT("viewLocation is %s,viewRotator is %s"),*viewVecotr.ToString(),*viewRotator.ToString());*/

	FVector rayLineEnd = viewVecotr + viewRotator.Vector()* lineReachDistance;
	
	DrawDebugLine(GetWorld(), viewVecotr, rayLineEnd, FColor(255, 0, 0), false, 0.f, 0, 10.f);
    
    FHitResult lineTraceHit;
    FCollisionQueryParams tracePara(FName(TEXT("")),false,GetOwner());
    GetWorld()->LineTraceSingleByObjectType(OUT lineTraceHit, viewVecotr, rayLineEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),tracePara);
    
    AActor* hitObjectActor=lineTraceHit.GetActor();
    if (hitObjectActor) {
        UE_LOG(LogTemp, Warning, TEXT("hit object name is %s"),*hitObjectActor->GetName())

    }
    

}

void UGrabber::Grab()
{
    UE_LOG(LogTemp, Warning, TEXT("input pressed"));

}

void UGrabber::Release()
{
    UE_LOG(LogTemp, Warning, TEXT("input Release"));
}

