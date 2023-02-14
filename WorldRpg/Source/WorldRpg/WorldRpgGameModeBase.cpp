// Copyright Epic Games, Inc. All Rights Reserved.


#include "WorldRpgGameModeBase.h"
#include "Critter.h"

AWorldRpgGameModeBase::AWorldRpgGameModeBase()
{
	DefaultPawnClass = ACritter::StaticClass();
	static ConstructorHelpers::FClassFinder<ACritter> Critter(TEXT("Class'/Script/WorldRpg.Critter'"));

	if (Critter.Succeeded())
		DefaultPawnClass = Critter.Class;
}
