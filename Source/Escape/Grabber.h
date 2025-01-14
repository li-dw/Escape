// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		float lineReachDistance = 100.f;
    UPROPERTY(EditAnywhere)
    UPhysicsHandleComponent* physicsHandle=nullptr;
    
    UPROPERTY(EditAnywhere)
    UInputComponent* inputHandle=nullptr;
    
    UPROPERTY(EditAnywhere)
    FVector rayStartLocation;
    
    void Grab();
    
    void Release();
    
    void FindPhysicsHandle();
    
    void SetInputHandle();
    
    const FHitResult GetFirstHitResult();
    
    inline const FVector GetLineEndVector();
    
    inline const FVector GetLineStartVector();
    
};
