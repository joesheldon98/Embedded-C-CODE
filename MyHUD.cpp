#include "MyHUD.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "Engine/Canvas.h"
#include "UObject/ConstructorHelpers.h"

AMyHUD::AMyHUD()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairObj(TEXT("/Content/Blueprints/MyCrosshair"));
	Crosshair = CrosshairObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> MinimapObj(TEXT("/Content/Blueprints/HUD/Minimap"));
	MiniMap = MinimapObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> HealthBarObj(TEXT("/Content/Blueprints/HUD/HealthBar"));
	HealthBar = HealthBarObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> ScoreTexObj(TEXT("/Content/Blueprints/HUD/Score"));
	Score = ScoreTexObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> AmmoCountObj(TEXT("/Content/Blueprints/HUD/Ammo"));
	AmmoCount = AmmoCountObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> ObjectivesObj(TEXT("/Content/Blueprints/HUD/Objectives"));
	Objectives = ObjectivesObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> KillfeedObj(TEXT("/Content/Blueprints/HUD/Killfeed"));
	Killfeed = KillfeedObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> StartScreenObj(TEXT("/Content/Blueprints/HUD/Killfeed"));
	Killfeed = StartScreenObj.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> DeathScreenObj(TEXT("/Content/Blueprints/HUD/Killfeed"));
	Killfeed = DeathScreenObj.Object;
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	//Crosshair 
	const FVector2D axisPosition(Canvas->ClipX * 0.48f, Canvas->ClipY * 0.56f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 10.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, Crosshair->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//MiniMap
	const FVector2D axisPosition(Canvas->ClipX * -265.0f, Canvas->ClipY * 156.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 5.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, MiniMap->Resource, FLinearColor::Black);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//HealthBar
	const FVector2D axisPosition(Canvas->ClipX * 0.52f, Canvas->ClipY * 1000.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 100.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, HealthBar->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//Score
	const FVector2D axisPosition(Canvas->ClipX * -132.0f, Canvas->ClipY * 96.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 10.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, Score->Resource, FLinearColor::Red);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//AmmoCount
	const FVector2D axisPosition(Canvas->ClipX * -200.0f, Canvas->ClipY * -90.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 10.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, AmmoCount->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//Objectives
	const FVector2D axisPosition(Canvas->ClipX * -173.0f, Canvas->ClipY * 20.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 5.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, Objectives->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//Killfeed
	const FVector2D axisPosition(Canvas->ClipX * 0.52f, Canvas->ClipY * 20.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 2.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, Killfeed->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//StartScreen
	const FVector2D axisPosition(Canvas->ClipX * 0.48f, Canvas->ClipY * 56.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 2.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, StartScreen->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);

	//DeathScreen
	const FVector2D axisPosition(Canvas->ClipX * 0.48f, Canvas->ClipY * 56.0f);  //centre align it
	const FVector2D alignPosition((axisPosition.X), (axisPosition.Y + 2.0f));  //draw on pos 
	FCanvasTileItem drawTexture(alignPosition, DeathScreen->Resource, FLinearColor::White);  // draw texture
	drawTexture.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(drawTexture);
}
