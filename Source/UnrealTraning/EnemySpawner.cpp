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

	//waveClock = timeBetweenWaves;
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (!ongovingWave)
	//{
	//	waveClock -= DeltaTime;

	//	if (waveClock <= 0)
	//	{
	//		ongovingWave = true;
	//		waveClock = timeBetweenWaves;
	//	}

	//	return;
	//}

	if (!ongoingWave || doneSpawning)
		return;

	if (spawnAmount[currentWave] > 0)
	{
		if (spawnClock > 0)
			spawnClock -= DeltaTime;

		if (spawnClock <= 0)
		{
			//Reset timer
			spawnAmount[currentWave]--;
			spawnClock = timeBetweenSpawn;

			//Spawn in world
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters spawnParameters;

				spawnParameters.Owner = this;

				FRotator rotator;

				//FVector spawnLocation = GetActorLocation();
				AActor* spawnLocation = spawnLocations[FMath::RandRange(0, spawnLocations.Num() - 1)];

				world->SpawnActor<AActor>(enemy, spawnLocation->GetTargetLocation(), rotator, spawnParameters);
			}

			//////Next wave
			//if (spawnAmount[currentWave] == 0 && !doneSpawning)
			//{
			//	if (currentWave == spawnAmount.Num())
			//	{
			//		doneSpawning = true;
			//	}
			//	else
			//	{
			//		currentWave++;
			//		activeEnemies = spawnAmount[currentWave];
			//		ongovingWave = false;
			//	}
			//}
		}
	}
}

void AEnemySpawner::NextWave()
{
	if (doneSpawning)
		return;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Wave begins!"));

	currentWave++;

	if (currentWave >= spawnAmount.Num() - 1)
		doneSpawning = true;

	ongoingWave = true;
}