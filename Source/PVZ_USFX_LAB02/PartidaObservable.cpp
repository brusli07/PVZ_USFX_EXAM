// Fill out your copyright notice in the Description page of Project Settings.


#include "PartidaObservable.h"
#include "Observer.h"
// Sets default values
APartidaObservable::APartidaObservable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APartidaObservable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APartidaObservable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APartidaObservable::SetEstadoPartida(FString _estadoPartida)
{
	EstadoPartida = _estadoPartida;
	Notify();
}

void APartidaObservable::AddObserver(IObserver* Observer)
{
	Observers.Add(Observer);
}

void APartidaObservable::RemoveObserver(IObserver* Observer)
{
	Observers.Remove(Observer);
}

void APartidaObservable::Notify()
{
	for (int32 i = Observers.Num() - 1; i >= 0; i--)
	{
		if (Observers[i]) // si el observador existe
		{
			Observers[i]->Update();
		}
		else // si el observador no existe, se elimina del array
		{
			Observers.RemoveAt(i);
		}
	}
}

