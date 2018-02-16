// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaTime ) override;

private:
	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	UPROPERTY( EditAnywhere )
	float CrosshairXLocation = 0.5f;
	
	UPROPERTY( EditAnywhere )
	float CrosshairYLocation = 0.33333f;

	UPROPERTY( EditAnywhere )
	float LineTraceRange = 1000000.f;

	// rturn an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation( FVector& OutHitLocation ) const;
	
	bool GetLookDirection( FVector2D ScreenLocation, FVector& LookDirection ) const;

	bool GetLookVectorHitLocation( FVector LookDirection, FVector& OutHitLocation ) const;

};
