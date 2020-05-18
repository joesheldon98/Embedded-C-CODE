#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYFINALPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UTexture2D* Crosshair;
	UTexture2D* MiniMap;
	UTexture2D* HealthBar;
	UTexture2D* Score;
	UTexture2D* AmmoCount;
	UTexture2D* Objectives;
	UTexture2D* Killfeed;
	UTexture2D* StartScreen;
	UTexture2D* DeathScreen;

public:
	
	AMyHUD();

	virtual void DrawHUD() override;   //draw call
};
