// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScaleTT.generated.h"

UCLASS()
class WORLDRPG_API AScaleTT : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScaleTT();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMC0;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMC1;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMC2;

};
