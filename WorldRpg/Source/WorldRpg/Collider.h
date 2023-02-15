// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class WORLDRPG_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere,Category = "Mesh")
	class UStaticMeshComponent* m_MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USphereComponent* m_SphereComponent;

	UPROPERTY(VisibleAnywhere,Category = "Camera")
	class UCameraComponent* m_Camera;

	UPROPERTY(VisibleAnywhere,Category = "Camera")
	class USpringArmComponent* m_SpringArm;

	FORCEINLINE UStaticMeshComponent* GetMeshComponent() { return m_MeshComponent; }
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* MeshComponent) { m_MeshComponent = MeshComponent; }
	FORCEINLINE USphereComponent* GetSphereComponent() { return m_SphereComponent; }
	FORCEINLINE void SetSphereComponent(USphereComponent* SphereComponent) { m_SphereComponent = SphereComponent; }


private:
	void MoveForward(float Value);
	void MoveRight(float Value);
};
