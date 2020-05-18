#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "MyPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class MYFINALPROJECT_API AMyPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

public:
		AMyPlayerCameraManager();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
		AActor* PlayerPerspectiveCamera;

	UPROPERTY(EditAnywhere)
		AActor* RadarCamera;

	float CaptureCamera;
	int preview;
	
};
