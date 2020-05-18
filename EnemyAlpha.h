#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSCharacter.h"
#include "EnemyAlpha.generated.h"

class detectPawn;
class USHealthComponent

UCLASS()
class MYFINALPROJECT_API AEnemyAlpha : public AActor
{
	GENERATED_BODY()

		UENUM(BlueprintType)
		enum class EAIState : uint8
	{
		Idle,
		Roam,
		Chase,
		Attack,
		Dead
	};
	
public:	
	// Sets default values for this actor's properties
	AEnemyAlpha();

	UPROPERTY(VisibleAnywhere, Category = "Components")
		detectPawn* pawnComponentDetection;

	UPROPERTY(ReplicatedUsing = OncurrentState)
		EAIState currentState;

	UFUNCTION()
		void OncurrentState();

	void setcurrentState(EAIState newState);
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USHealthComponent* HealthComp;

	UFUNCTION(BlueprintImplementableEvent, Category = "AI")
		void OncurrentState(EAIState newState);

	UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
		void onReceiveDamage();

	UPROPERTY(EditAnywhere, Category = "Attack")
		bool isAttackable{true};

	UFUNCTION(BlueprintImplementableEvent, Category = "ChasePlayer")
		void chasePlayer(const Location, float getPlayerLocation);

	UFUNCTION(BlueprintImplementableEvent, Category = "FindPlayer")
		void findPlayer(APawn* detectPlayer);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Health")
		void AIhealth(float const value);

	UFUNCTION(BlueprintImplementableEvent, Category = "HitPlayer")
		void hitPlayer();

	UFUNCTION(BlueprintImplementableEvent, Category = "freeRoam")
		void freeRoam();

	UFUNCTION(BlueprintImplementableEvent, Category = "ChangeSpeed")
		void changeSpeed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void beAttacked();  //enables enemy to be attacked
	
	UFUNCTION(BlueprintCallable);
	void SpawnEnemies();

	UPROPERTY(EditAnywhere)
		TArray<AEnemyAlpha*> Enemies;   //array of enemy. 

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UBoxComponent * CollisionBox;
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


private: 

};
