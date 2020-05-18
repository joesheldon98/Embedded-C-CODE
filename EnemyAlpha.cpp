#include "EnemyAlpha.h"
#include "EngineUtils.h"
#include "Engine.h"
#include "FPSCharacter.h"
#include "MyFinalProjectGameModeBase.h"


// Sets default values
AEnemyAlpha::AEnemyAlpha()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	CollisionBox->SetCollisionProfileName("Collided");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABoxActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABoxActor::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AEnemyAlpha::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyAlpha::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	detectPawn = CreateDefaultSubobject<UpawnComponentDetection>(TEXT("pawnDetected"));

}

void AEnemyAlpha::beAttacked()
{
	//Perform health reduction logic (currentHealth -= incomingDamage)
	onReceiveDamage(); //event emitter
}

void AEnemyAlpha::SpawnEnemies()
{
	if (Enemies)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			FRotator rotator;
			FVector location = this->Spawner->GetComponentLocation();                        //spawn at spawner mesh
			world->SpawnActor<AEnemyAlpha>(Enemies, location, rotator, spawnParams);
		}
	}
}

void AEnemyAlpha::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "OVERLAP BEGIN CALLED");    //detection overlap
}

void AEnemyAlpha::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "OVERLAP END CALLED");      //detection overlaps ends
}

void AEnemyAlpha::onReceiveDamage()
{
	//emitted in editor
}

void AEnemyAlpha::chasePlayer((const Location, float getPlayerLocation)
{
	if (OncurrentState == EAIState::Attack)
	{
		return;
	}

	FVector Direction = Location - getPlayerLocation();
	Direction.Normalize();

	AController* Controller = GetController();         //stop current movement if chase mode initiated
	if (Controller)
	{
		Controller->StopMovement();
	}
}

void AEnemyAlpha::findPlayer(APawn* detectPlayer)
{
	if (detectPlayer == nullptr)
	{
		return;
	}

	DrawDebugSphere(GetWorld(), detectPlayer->GetActorLocation(), 100.0f, 500, FColor::White, false, 10.0f);        //get players location

	AMyFinalProjectGameModeBase* GM = Cast<AGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->MulticastOnplayerKilled(detectPlayer, false);
	}

	SetAIState(EAIState::Chase);      

	AController* Controller = GetController();                  //stop current movement if seen initated
	if (Controller)
	{
		Controller->StopMovement();
	}
}

void AEnemyAlpha::AIhealth(float const value)
{
	if (value != 0.0f)
	{
		bool Destroy(bool bNetForce, bool bShouldModifyLevel)      //if health is 0, destroy actor
	}
}

void AEnemyAlpha::hitPlayer()
{
	onCurrentState = EAIState::Attack;
}

void AEnemyAlpha::freeRoam()
{
	OncurrentState = EAIState::Roam;   //perform idle state
}

void AEnemyAlpha::changeSpeed()
{
	onCurrentState = EAIState::Attack;
	//set in editor

}
