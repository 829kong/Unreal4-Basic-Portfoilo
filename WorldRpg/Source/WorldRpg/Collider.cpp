// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ColliderMovementComponent.h"

// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(m_SphereComponent);
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
	m_SpringArm->SetupAttachment(GetRootComponent());
	m_SpringArm->SetRelativeRotation(FRotator(-45.f, 0, 0));
	m_SpringArm->TargetArmLength = 500.f;
	m_SpringArm->bEnableCameraLag = true;
	m_SpringArm->CameraLagSpeed = 3.f;

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(m_SpringArm);

	m_ColliderMovementComp = CreateDefaultSubobject<UColliderMovementComponent>(TEXT("ColliderMovement"));
	m_ColliderMovementComp->UpdatedComponent = RootComponent;

	m_MaxSpeed = 100.f;
	CameraInput = FVector2D(0.f, 0.f);

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

	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += CameraInput.X;
	SetActorRotation(NewRotation);

	FRotator NewSpringArmRotation = m_SpringArm->GetComponentRotation();
	NewSpringArmRotation.Pitch = FMath::Clamp(NewSpringArmRotation.Pitch += CameraInput.Y, - 80.f, -15.f);
	m_SpringArm->SetWorldRotation(NewSpringArmRotation);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MovePitch"), this, &ACollider::MovePitch);
	PlayerInputComponent->BindAxis(TEXT("MoveYaw"), this, &ACollider::MoveYaw);
}

UPawnMovementComponent* ACollider::GetMovementComponent() const
{
	return m_ColliderMovementComp;
}

void ACollider::MoveForward(float Value)
{
	if (m_ColliderMovementComp)
	{
		m_ColliderMovementComp->AddInputVector(GetActorForwardVector()*Value);
	}
}

void ACollider::MoveRight(float Value)
{
	if (m_ColliderMovementComp)
	{
		m_ColliderMovementComp->AddInputVector(GetActorRightVector()*Value);
	}
}

void ACollider::MovePitch(float Value)
{
	CameraInput.Y = Value;
}

void ACollider::MoveYaw(float Value)
{
	CameraInput.X = Value;
}

