#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent; 
class USceneComponent;
class UCameraComponent;
class USoundComponent;
class UAnimationComponent;
class UTheProjectile;

UCLASS()
class MYFINALPROJECT_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

		//List of mesh's 

   UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
   class USkeletalMeshComponent* FPPerspective;    //FPS perspective

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class UCameraComponent* CameraPerspective;    //Camera perspective

    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    class USkeletalMeshComponent* CharacterGun;    //Player's gun

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* CharacterGunTip; //Tip of gun

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
    TSubclassOf<class UTheProjectile> MyProjectile;    //Spawn Projectile 
												  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)   //Gun tip 
		FVector GunMuzzle;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float weaponRange{ 500 };                              //Range of weapon 

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void fireGun();                                        //Fire the gun 

	UPROPERTY(VisibleAnywhere, Category = "Camera")           //Create the camera
		UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Movement of objects/actors
	FHitResult bulletShot();   //Shoot the bullets
	void HorizontalMovement(float Val);  //left and right
	void VerticalMovement(float Val);   //forward and back

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	USkeletalMeshComponent* GetMesh1P() const { return FPPerspective; }   // fp perspective
	UCameraComponent* GetFPSCamera() const { return CameraPerspective; }  //camera
};
