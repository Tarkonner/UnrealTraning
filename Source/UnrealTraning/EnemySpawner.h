// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class UNREALTRANING_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
		TArray<AActor*> spawnLocations;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> enemy;
	UPROPERTY(EditAnywhere)
		TArray<int> spawnAmount;
	UPROPERTY(EditAnywhere)
		float timeBetweenSpawn = 2.5f;
	UPROPERTY(EditAnywhere)
		float timeBetweenWaves = 10;

	//Current wave
	bool ongovingWave = false;
	int activeEnemies = true;

private:
	//Timers
	float spawnClock;
	float waveClock;
	//Waves
	int currentWave = 0;
	bool doneSpawning = false;
};
