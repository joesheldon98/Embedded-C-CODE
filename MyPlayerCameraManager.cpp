#include "MyPlayerCameraManager.h"
#include "FPSCharacter.h"

AMyPlayerCameraManager::AMyPlayerCameraManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerCameraManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerCameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CaptureCamera;
	CaptureCamera -= DeltaTime;

	if (CaptureCamera <= 0.0f)
	{
		APlayerController*const playerController = GetWorld()->GetFirstPlayerController();
		if (playerController)
		{
			playerController->GetPlayerViewPoint(PlayerPerspectiveCamera);         //get FPS camera pers
		}
		return preview;
	}

	if (CaptureCamera <= 0.0f)
	{
		APlayerController*const playerController = GetWorld()->GetFirstPlayerController();
		if (playerController)
		{
			playerController->GetPlayerViewPoint(RadarCamera);                 //get radar camera pers
		}
		return preview;
	}

}



