// Fill out your copyright notice in the Description page of Project Settings.


#include "ScaleTT.h"

// Sets default values
AScaleTT::AScaleTT()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SMC0 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMC0"));
	SMC1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMC1"));
	SMC2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMC2"));

	SMC0->SetupAttachment(GetRootComponent());
	SMC1->SetupAttachment(GetRootComponent());
	SMC2->SetupAttachment(GetRootComponent());

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> SM0;
		ConstructorHelpers::FObjectFinder<UStaticMesh> SM1;
		ConstructorHelpers::FObjectFinder<UStaticMesh> SM2;

		FConstructorStatics()
			:SM0(TEXT("StaticMesh'/Game/Asset/StarterContent/Shapes/Shape_Cone.Shape_Cone'")),
			SM1(TEXT("StaticMesh'/Game/Asset/StarterContent/Shapes/Shape_Cube.Shape_Cube'")),
			SM2(TEXT("StaticMesh'/Game/Asset/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"))
		{}
	};
	static FConstructorStatics ConstructorStatics;

	if (ConstructorStatics.SM0.Succeeded())
	{
		SMC0->SetStaticMesh(ConstructorStatics.SM0.Object);
		SMC0->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		SMC0->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
	}

	if (ConstructorStatics.SM1.Succeeded())
	{
		SMC1->SetStaticMesh(ConstructorStatics.SM1.Object);
		SMC1->SetRelativeLocation(FVector(-200.f, 0.f, 0.f));
		SMC1->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
	}

	if (ConstructorStatics.SM2.Succeeded())
	{
		SMC2->SetStaticMesh(ConstructorStatics.SM2.Object);
		SMC2->SetRelativeLocation(FVector(200.f, 0.f, 0.f));
		SMC2->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
	}



}

// Called when the game starts or when spawned
void AScaleTT::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScaleTT::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FRotator NewRotator = FRotator(0.f, 0.f, 0.f);
	NewRotator = NewRotator + FRotator(30.f, 0.f, 0.f);
	SMC0->SetRelativeRotation(NewRotator);
	SMC1->SetRelativeRotation(NewRotator);
	SMC2->SetRelativeRotation(NewRotator);
}

