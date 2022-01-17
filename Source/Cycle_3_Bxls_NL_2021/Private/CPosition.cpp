// Fill out your copyright notice in the Description page of Project Settings.


#include "CPosition.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UCPosition::UCPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPosition::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Object Name : %s"), *getPawnName());
	// ...
	if (GEngine != nullptr) {
		GEngine->AddOnScreenDebugMessage(1, 10, FColor::Blue, getPawnName());
	}

	
}


// Called every frame
void UCPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("Object Position : %s"), *getPawnPosition().ToString());
	
	if (GEngine != nullptr) {
		GEngine->AddOnScreenDebugMessage(1, 10, FColor::Blue, getPawnPosition().ToString());
	}
	

	// ...
}

FString UCPosition::getPawnName() const
{
	FString strObjectName=GetOwner()->GetName();
	return strObjectName;
}

FVector UCPosition::getPawnPosition() const
{
	FVector vObjectPosition = GetOwner()->GetActorTransform().GetLocation();
	return vObjectPosition;
}

