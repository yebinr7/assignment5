// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class ASSIGNMENT5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//const 함수 => 내부에서 멤버변수 못건듬 
	void RandomTenMove();

	//랜덤으로 0~1 반환 
	int32_t Step();
private:
	//부모의 위치정보 이용X 내가 만든걸로 ㄱㄱ
	FVector2D _pos; 

	//함수 통해 몇번 움직였나 카운트,  
	uint8_t	  _moveCount = 0;
};
