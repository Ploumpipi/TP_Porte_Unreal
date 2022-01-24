// Fill out your copyright notice in the Description page of Project Settings.


#include "COpenDoor.h"

// Sets default values for this component's properties
UCOpenDoor::UCOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetOverlappingActors();

	UE_LOG(LogTemp, Warning, TEXT("Mass : %f", SetTotalMass()));

	if (Tvolume) {
		if (SetTotalMass() > fltMassTest) {
			UE_LOG(LogTemp, Warning, TEXT("Open door"));
			OpenDoor();
			fltLastDoorOpenTime;
		}
	}
	// ...
}

void UCOpenDoor::GetOverlappingActors()
{
	if (Tvolume != nullptr) {
		Tvolume->GetOverlappingActors(Actors);
	}
	return;
}

float UCOpenDoor::SetTotalMass()
{
	UStaticMeshComponent* Mesh;
	float fltTotalMass = 0;
	for (AActor* actors : Actors) {
		Mesh = actors->FindComponentByClass<UStaticMeshComponent>();
		if (Mesh) {
			fltTotalMass = fltTotalMass + Mesh->GetMass();
		}
	}
	return fltTotalMass;
}

void UCOpenDoor::OpenDoor() const
{
	openDoor.Broadcast();
}

void UCOpenDoor::CloseDoor() const
{
	closeDoor.Broadcast();
}

