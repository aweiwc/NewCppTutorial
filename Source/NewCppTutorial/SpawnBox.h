// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "SpawnBox.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // Called when the actor stops playing
    void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

	// Will spawn an actor of the specificed class now
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	// Will schedule an actor spawn
	void ScheduleActorSpawn();

private:
	UFUNCTION()
	void SpawnActorScheduled();

public:
    // Actor class to spawn
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClassToBeSpawned;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ShouldSpawn = true;

    // Average time between spawns (without random)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AvgSpawnTime = 5.f;

    // Random +/- offset of the spawn time
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomSpawnTimeOffset = 1.f;

private:
    // Box in which we will spawn the actors
    UPROPERTY(EditDefaultsOnly)
    UBoxComponent* SpawnBox;

    // Helper for timing
    FTimerHandle SpawnTimerHandle;
};
