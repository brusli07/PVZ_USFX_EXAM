// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Observable.h"
#include "PartidaObservable.h"
#include "Observer.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zombie.generated.h"
class APartidaObservable;
UCLASS()
class PVZ_USFX_LAB02_API AZombie : public AActor, public IObservable, public IObserver
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZombie();

	UPROPERTY(EditAnywhere) // para ver y editar desde el unreal
	float Velocidad;

	UPROPERTY(VisibleAnywhere) // para ver desde el unreal
	int energia;

	UPROPERTY(VisibleAnywhere) // para ver desde el unreal
	int Fuerza;

	FVector LocalizacionObjetivo;
	FVector Direccion;
	float DistanciaAlObjetivo;

	bool bCanMove = false;
	float SpawnAfter = 0.0f;

	float TiempoTranscurrido;
	FTimerHandle TimerHandle;

	APartidaObservable* PartidaObservable;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshZombie;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Attack();

	void morir();

	void VelocidadRandom(float V1, float V2);

	FORCEINLINE void SetSpawnAfter(float _SpawnAfter) { SpawnAfter = _SpawnAfter; }
	FORCEINLINE float GetSpawnAfter() { return SpawnAfter; }
	FORCEINLINE void SetCanMove(bool _bCanMove) { bCanMove = _bCanMove; }

	void AddObserver(class IObserver* Observer) override;
	void RemoveObserver(class IObserver* Observer) override;
	void Notify() override;

	void Update() override;

	void SetPartidaObservable(APartidaObservable* _partidaObservable);

	void Cambiar();
};
