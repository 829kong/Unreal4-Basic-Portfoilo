// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Critter.generated.h"

UCLASS()
class WORLDRPG_API ACritter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACritter();

	UPROPERTY()
	class UStaticMeshComponent* m_MeshComp;

	UPROPERTY()
	class UCameraComponent* m_Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void MoveForward(float Value);
	void MoveRight(float Value);

public:
	UPROPERTY()
	FVector m_CurrentVelocity;

	UPROPERTY(EditAnywhere,Category = "Speed")
	float m_MaxSpeed;

};
