// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStageTimer.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UENUM(BlueprintType)
enum class EMonsterType : uint8
{
	Zombie UMETA (DisplayName = "Zombie"),
	Skeleton UMETA (DisplayName = "Skeleton"),
};
UCLASS()
class PROJECTA_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	

	int _hp;
	int _damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EMonsterType  _MonsterTypeEnum;
	
	UAnimInstance* animInstance;
	FBodyInstance * RHand;
	FVector _attackStartPos;

	FTimerHandle _hitTimerHandle;

	AActor* _targetObject;
	AGameStageTimer* _gameStageTimer;
	

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool _bCanAttack;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	bool _bDead;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	bool _bHit;

	UPROPERTY(EditDefaultsOnly);
	UAnimMontage* _attackMontage;

	UPROPERTY(EditDefaultsOnly);
	UAnimMontage* _hitMontage;
	
	void DecreaseHP(int value);

	bool FireRay();
	
	UFUNCTION(BlueprintCallable)
	void AttackStart();

	
	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	inline void HitTimerFunc() {_bHit = false;}
	



	
	virtual void PostInitializeComponents() override;
	



	

	
	
};
