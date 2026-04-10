// Fill out your copyright notice in the Description page of Project Settings.


#include "NewCppTutorialGameModeBase.h"

void ANewCppTutorialGameModeBase::InitGameState()
{
    Super::InitGameState();

    // Check if no hard override is active
    if (DefaultPawnClass == ADefaultPawn::StaticClass() || !DefaultPawnClass)
    {
        // Update to custom implementation
        DefaultPawnClass = CustomXPCharacterClass;
    }
}

