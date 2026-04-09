// Fill out your copyright notice in the Description page of Project Settings.


#include "XPPawn.h"

// Sets default values
AXPPawn::AXPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AXPPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

