// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02GameModeBase.generated.h"

class APlanta_Ataque;
class APartidaObservable;
class AZombie;
class APlant;
UCLASS()
class PVZ_USFX_LAB02_API APVZ_USFX_LAB02GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	APVZ_USFX_LAB02GameModeBase();

	APartidaObservable* PartidaObservable;
	FVector SpawnLocationZombie;
	TArray<AZombie*> ArrayZombies;
	AZombie* NuevoZombie;
	int32 NumberZombiesComun = 10;
	int32 NumberZombiesCono = 15;

	int32 NumberZombiesSpawned = 0;


	TMap<FString, APlanta_Ataque*> MapPlantas;

//	APlant* NuevaPlanta;
	FVector SpawnLocationPlant;
	FVector SpawnLocationPlantTemp;

	FTimerHandle Temporizador;
	float TiempoTranscurrido;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	// Called every frame

	void aumentovelocidad();

};
