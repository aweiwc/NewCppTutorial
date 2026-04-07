// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCollectableActor.h"

// Sets default values
AMyCollectableActor::AMyCollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the (root) component for rendering
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh_"));
	RootComponent = StaticMesh;

	//Create Collision box
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision_"));
	BoxCollision->SetupAttachment(StaticMesh);
}

void AMyCollectableActor::jump(float velocity)
{
	/*auto NewLocation = GetActorLocation();
	NewLocation.Z += velocity;
	SetActorLocation(NewLocation);*/

	if (!Islaunched) 
	{
		//Excute jump using the physics system
		StaticMesh->AddImpulse({ .0f,.0f,velocity * 500.f });

		//Initiate object destruction
		SetActorTickEnabled(true);
		Islaunched = true;
		
	}
}

// Called when the game starts or when spawned
void AMyCollectableActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Setup per instance OnComponentOverlap event
	FScriptDelegate DelegateSubscriber;
	DelegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSubscriber);

	//Ticking is only required after launching
	SetActorTickEnabled(false);	
}

void AMyCollectableActor::OnComponentBeginOverlap(UBoxComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//debug
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,"True", true, {3, 3});
	if (!Islaunched && OtherActor->IsA(TriggerClass)) 
	{
		OnJumpTrigger.Broadcast(OtherActor, Component);
	}
}

// Called every frame
void AMyCollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Islaunched) 
	{
		Livetime -= DeltaTime;
		if(Livetime <= .0f)
		{
			Destroy();
		}
	}
}

