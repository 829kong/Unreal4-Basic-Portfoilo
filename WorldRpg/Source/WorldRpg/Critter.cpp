// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	struct FConstructorStatics
	{
		FConstructorStatics()
		{}
	};

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	m_SkeltalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalComponent"));
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_SkeltalMesh->SetupAttachment(GetRootComponent());
	m_Camera->SetupAttachment(GetRootComponent());
	m_Camera->SetRelativeLocation(FVector(-300.f, 0.f, 300.f));
	m_Camera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	static FConstructorStatics ConstructorStatics;

	m_CurrentVelocity = FVector(0.f);
	m_MaxSpeed = 100.f;
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() + (m_CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);
}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACritter::MoveRight);
}

void ACritter::MoveForward(float Value)
{
	m_CurrentVelocity.X = FMath::Clamp(Value, -1.f, 1.f) * m_MaxSpeed;
}

void ACritter::MoveRight(float Value)
{
	m_CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * m_MaxSpeed;
}

