// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Curves/CurveFloat.h"
#include "DRCharacter.generated.h"

UCLASS()
class UEPROJECT_API ADRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADRCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
    //力量
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Strength;
    //攻击
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Attack;
    //负重
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Burden;
    //体质
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Constitution;
    //生命值
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Health;
    //防御值
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Armor;
    //耐力
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Endurance;
    //饥饿度
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Hunger;
    //饥饿速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    UCurveFloat* HungerCurve;
    //疲劳度
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Fatigue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    UCurveFloat* FatigueCurve;
	//干渴度
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 Thirst;
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    UCurveFloat* ThirstCurve;
    
    
    //视野
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 FieldOfVision;
    //近程格挡
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 ProximityParry;
    //远程格挡
    UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="States")
    int32 RemoteBlock;
    
    UFUNCTION(BlueprintCallable,Category="Actions")
    void Eat(float FoodValue);
    UFUNCTION(BlueprintCallable,Category="Actions")
    void Rest(float RestValue);
    UFUNCTION(BlueprintCallable,Category="Actions")
    void Drink(float WaterValue);

    UPROPERTY(BlueprintReadOnly ,Category="States")
    UTimelineComponent* HungerTimeline;
    UPROPERTY(BlueprintReadOnly ,Category="States")
    UTimelineComponent* FatigueTimeline;
    UPROPERTY(BlueprintReadOnly ,Category="States")
    UTimelineComponent* ThirstTimeline;
private:
    UFUNCTION()
    void OnHungerTimeline(float Output);
    UFUNCTION()
    void OnFatigueTimeline(float Output);
    UFUNCTION()
    void OnThirstTimeline(float Output);
};
