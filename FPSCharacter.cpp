#include "FPSCharacter.h"
#include "Engine/World.h"
#include "EnemyAlpha.h"
#include "TheProjectile.h"
#include "Camera/CameraComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComp"));
	float health = 100;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->attachCamera(CameraComponent);
	
	CameraPOV = 200.0f;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters SpawnParams;
	
	OnStart = CameraComponent->POV;
	HealthComponent->OnHealthChanged.AddDynamic(this, &FPSCharacter::damageTaken);
	
	if (this, &ABoxActor::OnOverlapBegin)
	{
		health--;
	}
	
	if (health == 0)
	{
		DOREPLIFETIME(FPSCharacter, bDied);
	}
	return 0;
}


// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Fire", MK_PRESSED, this, &FPSCharacter::StartFiring)
	PlayerInputComponent->BindAction("Fire", MK_RELEASED, this, &FPSCharacter::StopFiring)
		
	PlayerInputComponent->BindAxis("MoveVertical", this, &FPSCharacter::MoveVertical);
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &FPSCharacter::MoveHorizontal);
	
	PlayerInputComponent->BindAxis("LookX", this, &FPSCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookY", this, &FPSCharacter::AddControllerYawInput);
}


void AFPSCharacter::fireGun()
{
	FHitResult hit = bulletShot();
	AEnemyAlpha* hitActor = Cast<AEnemyAlpha>(hit.Actor);
	if (hitActor && hitActor->isAttackable)
	{
		hitActor->beAttacked();
	}
}

//shoot bullet
FHitResult AFPSCharacter::bulletShot()
{
	FVector bulletPosition;
	FRotator bulletRotation; 
	FVector endTrace = FVector::ZeroVector;  //forward vector

	APlayerController*const playerController = GetWorld()->GetFirstPlayerController();
	if (playerController)
	{
		playerController->GetPlayerViewPoint(bulletPosition, bulletRotation);
		endTrace = bulletPosition + (bulletRotation.Vector() * weaponRange);
	}

	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(bulletShot), true, Instigator);
	FHitResult hit(ForceInit);
	GetWorld() ->LineTraceSingleByChannel(hit, bulletPosition, endTrace, ECC_Visibility, traceParams);

	return FHitResult();
}

void AFPSCharacter::HorizontalMovement(float Val)
{
	if (Val != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Val);
	}
}

void AFPSCharacter::VerticalMovement(float Val)
{
	if (Val != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Val);
	}
}
