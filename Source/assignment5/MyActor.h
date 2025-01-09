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
	//const �Լ� => ���ο��� ������� ���ǵ� 
	void RandomTenMove();

	//�������� 0~1 ��ȯ 
	int32_t Step();

	//�Ÿ� ����
	float Distance(FVector2D first, FVector2D second);
	
	//50%Ȯ���� �����̺�Ʈ ���� 
	bool createEvent();

private:
	//�θ��� ��ġ���� �̿�X ���� ����ɷ� ����
	FVector2D _pos; 

	//�Լ� ���� ��� �������� ī��Ʈ1���� ����,  
	uint8_t	  _moveCount = 0;

	//�̺�Ʈ ���� Ƚ�� ����
	uint8_t	  _eventCount = 0;

	//�Ÿ� ����
	float	  _toDist = 0.f;

};
