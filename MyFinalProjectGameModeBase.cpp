#include "MyFinalProjectGameModeBase.h"
#include "MyHUD.h"
#include "FPSCharacter.h"
#include "EnemyAlpha.h"
#include "UObject/ConstructorHelpers.h"

AMyFinalProjectGameModeBase::AMyFinalProjectGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> MyCharacterFinder(TEXT("/Content/Blueprints/MyCharacter"));
	DefaultPawnClass = MyCharacterFinder.Class;

	static ConstructorHelpers::FClassFinder<APawn> AIEnemyFinder(TEXT("/Content/Blueprints/AIEnemy"));
	DefaultPawnClass = AIEnemyFinder.Class;

	static ConstructorHelpers::FClassFinder<APawn> GunFinder(TEXT("/Content/Blueprints/Weapons/AR4/Weapon_base"));
	DefaultPawnClass = GunFinder.Class;

	HUDClass = AMyHUD::StaticClass();

}

void AMyFinalProjectGameModeBase::Score(float value)
{
	if (value != 0.0f)
	{
		onCurrentState = EAIState::Dead;         //+10 score per kill
		Score = value + 10;
	}
}

void AMyFinalProjectGameModeBase::MulticastOnplayerKilled(APawn* AIpawn, bool bplayerKilled)
{
	if (AIpawn)
	{
		TArray<AActor*> ReturnedActors;
		UGameplayStatics::GetAllActorsOfClass(this, ReturnedActors);     //spawn actors if player is alive
	}

	AFPSCharacter* Health = GetCurrentHealth<class UHealthComponent>();         //get player health
	if (Health)
	{
		Health->MulticastOnplayerKilled(AIpawn, bplayerKilled);
	}

	MulticastOnplayerKilled(AIpawn, bplayerKilled);
}

