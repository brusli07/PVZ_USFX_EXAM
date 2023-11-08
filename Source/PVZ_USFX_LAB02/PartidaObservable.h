// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Observable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartidaObservable.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APartidaObservable : public AActor, public IObservable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APartidaObservable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	FString EstadoPartida;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void AddObserver(class IObserver* Observer) override;
	virtual void RemoveObserver(class IObserver* Observer) override;
	virtual void Notify() override;

	void SetEstadoPartida(FString _estadoPartida);
	FORCEINLINE FString GetEstado() { return EstadoPartida; };
};
