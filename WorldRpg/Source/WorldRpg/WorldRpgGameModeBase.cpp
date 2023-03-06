// Copyright Epic Games, Inc. All Rights Reserved.


#include "WorldRpgGameModeBase.h"
#include "MainChar.h"

AWorldRpgGameModeBase::AWorldRpgGameModeBase()
{
	DefaultPawnClass = AMainChar::StaticClass();
	static ConstructorHelpers::FClassFinder<AMainChar> MainChar(TEXT("Blueprint'/Game/BluePrint/BP_MainChar.BP_MainChar_C'"));

	if (MainChar.Succeeded())
		DefaultPawnClass = MainChar.Class;
}
	