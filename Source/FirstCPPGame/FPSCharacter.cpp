// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Engine/World.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



FHitResult AFPSCharacter::instantShot()
{
	// Gets the location and rotation of the camera, if shooting from a gun you should go those instead
	FVector rayLocation;
	FRotator rayRotation;
	FVector endTrace = FVector::ZeroVector;

	// Gets the player controller
	APlayerController* const playerController = GetWorld()->GetFirstPlayerController();
	
	// Check to see if a player controller was actually obtained and add functionality if it was
	if (playerController)
	{
		playerController->GetPlayerViewPoint(rayLocation, rayRotation);

		// Starting location + forward direction of your body rotation * weaponRange
		endTrace = rayLocation + (rayRotation.Vector() * weaponRange);
	}

	// Tell it to ignore the shooter so you don't shoot yourself by accident
	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(instantShot), true, Instigator);
	// Default to 0 unless something actually hits
	FHitResult hit(ForceInit);
	// Does the actual shot using LineTrace
	GetWorld()->LineTraceSingleByChannel(hit, rayLocation, endTrace, EEC_Visibility, traceParams)

	return hit;
}