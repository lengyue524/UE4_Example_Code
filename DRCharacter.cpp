// Fill out your copyright notice in the Description page of Project Settings.

#include "UEProject.h"
#include "DRCharacter.h"


// Sets default values
ADRCharacter::ADRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    PrimaryActorTick.bAllowTickOnDedicatedServer = true;
    Hunger = 100;
    Thirst = 100;
    Fatigue = 100;
    HungerTimeline = CreateDefaultSubobject<UTimelineComponent>(FName(TEXT("HungerTimeline")));
    ThirstTimeline = CreateDefaultSubobject<UTimelineComponent>(FName(TEXT("ThirstTimeline")));
    FatigueTimeline = CreateDefaultSubobject<UTimelineComponent>(FName(TEXT("FatigueTimeline")));
    AddOwnedComponent(HungerTimeline);
    AddOwnedComponent(ThirstTimeline);
    AddOwnedComponent(FatigueTimeline);
}
// Called when the game starts or when spawned
void ADRCharacter::BeginPlay()
{
	Super::BeginPlay();
    if (HungerCurve) {
        FOnTimelineFloat HungerUpdate;
        HungerUpdate.BindUFunction(this,FName(TEXT("OnHungerTimeline")));
        HungerTimeline->AddInterpFloat(HungerCurve, HungerUpdate,FName{TEXT("HungerCurve")});
        HungerTimeline->PlayFromStart();
    }
    if (FatigueCurve) {
        FOnTimelineFloat FatigueUpdate;
        FatigueUpdate.BindUFunction(this,FName(TEXT("OnFatigueTimeline")));
        FatigueTimeline->AddInterpFloat(FatigueCurve, FatigueUpdate,FName{TEXT("FatigueCurve")});
        FatigueTimeline->PlayFromStart();
    }
    if (ThirstCurve) {
        FOnTimelineFloat ThirstUpdate;
        ThirstUpdate.BindUFunction(this,FName(TEXT("OnThirstTimeline")));
        ThirstTimeline->AddInterpFloat(ThirstCurve, ThirstUpdate,FName{TEXT("ThirstCurve")});
        ThirstTimeline->PlayFromStart();
    }
}

// Called every frame
void ADRCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
    //HungerTimeline.TickTimeline(DeltaTime);
    //GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("c++:%d"),HungerTimeline->IsPlaying()));
}

// Called to bind functionality to input
void ADRCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ADRCharacter::Eat(float FoodValue)
{
    float CurrentPosition = HungerTimeline->GetPlaybackPosition();
    HungerTimeline->SetPlaybackPosition(CurrentPosition+FoodValue, true);
}

void ADRCharacter::Rest(float RestValue)
{
    float CurrentPosition = FatigueTimeline->GetPlaybackPosition();
    FatigueTimeline->SetPlaybackPosition(CurrentPosition+RestValue, true);
}
void ADRCharacter::Drink(float WaterValue)
{
    float CurrentPosition = ThirstTimeline->GetPlaybackPosition();
    ThirstTimeline->SetPlaybackPosition(CurrentPosition+WaterValue, true);
}
void ADRCharacter::OnHungerTimeline(float Output)
{
    Hunger = Output;
    //GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Hunger:%d"),Hunger));
}
void ADRCharacter::OnFatigueTimeline(float Output)
{
    Fatigue = Output;
    //GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Fatigue:%d"),Fatigue));
}
void ADRCharacter::OnThirstTimeline(float Output)
{
    Thirst = Output;
    //GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Thirst:%d"),Thirst));
}