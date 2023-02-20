// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
		
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (spawnAmount > 0)
	{
		if (spawnClock > 0)
			spawnClock -= DeltaTime;

		if (spawnClock <= 0)
		{
			//Reset timer
			spawnAmount--;
			spawnClock = timeBetweenSpawn;

			//Spawn in world
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters spawnParameters;

				spawnParameters.Owner = this;

				FRotator rotator;

				FVector spawnLocation = GetActorLocation();

				world->SpawnActor<AActor>(enemy, spawnLocation, rotator, spawnParameters);
			}
		}
	}
}

