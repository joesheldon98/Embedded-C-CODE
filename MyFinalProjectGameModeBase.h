#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFinalProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYFINALPROJECT_API AMyFinalProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	AMyFinalProjectGameModeBase();

	void Score(float value);  //left and right

	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnplayerKilled(APawn* AIpawn, bool bplayerKilled)
};
