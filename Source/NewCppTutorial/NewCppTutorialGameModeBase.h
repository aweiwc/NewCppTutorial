// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"
#include "XPPawn.h"
#include "NewCppTutorialGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class NEWCPPTUTORIAL_API ANewCppTutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void InitGameState() override;

private:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AXPPawn> CustomXPPawnClass = AXPPawn::StaticClass();
};
