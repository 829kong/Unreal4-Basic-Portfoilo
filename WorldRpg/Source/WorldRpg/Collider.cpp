// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	m_SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	m_SphereComponent->SetupAttachment(GetRootComponent());
	m_SphereComponent->InitSphereRadius(40.f);
	m_SphereComponent->SetCollisionProfileName("Pawn");

	m_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	m_MeshComponent->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Asset/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SM.Succeeded())
	{
		m_MeshComponent->SetStaticMesh(SM.Object);
		m_MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
		m_MeshComponent->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.75f));
		//m_MeshComponent->SetWorldScale3D(FVector(0.75f, 0.75f, 0.75f));
	}

	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring"));
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	m_SpringArm->SetupAttachment(GetRootComponent());
	m_SpringArm->SetRelativeRotation(FRotator(-45.f, 0, 0));
	m_SpringArm->TargetArmLength = 500.f;
	m_SpringArm->bEnableCameraLag = true;
	m_SpringArm->CameraLagSpeed = 3.f;

	m_Camera->SetupAttachment(m_SpringArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForword"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);
}

void ACollider::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ACollider::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

