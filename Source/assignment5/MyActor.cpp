// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "random"
#include "chrono"
#include "cmath"

// Sets default values
AMyActor::AMyActor()
	:_pos({0.f,0.f})
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello, World"));

	//���� ������ ��ġ �������� 
	//FVector CurrentLocation = GetActorLocation(); //FVector XYZ ��ǥ 
	
	//1. ���� ���� ��ġ
	_pos = {0., 0.};
	//UE_LOG(LogTemp, Warning, TEXT("_pos: %s\n"), *_pos.ToString());
	UE_LOG(LogTemp, Warning, TEXT("initial position: X=%d, Y=%d"),
		static_cast<int32>(_pos.X),
		static_cast<int32>(_pos.Y));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�� ������ ���Ͱ� �� ���� ��10�� 0~9 
	if (_moveCount < 10)
		RandomTenMove();
	

}

void AMyActor::RandomTenMove()
{
	//���� ��ġ
	FVector2D prvPos = FVector2D(_pos.X, _pos.Y);

	//������ ��ġ
	_pos =  FVector2D(_pos.X + Step(), (_pos.Y + Step()));

	//�Ÿ� ���ϱ�
	float  dist = Distance(prvPos, _pos);
	
	//���� �Ÿ� ���ϱ�
	_toDist += dist;


	//UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: %s\n"), _moveCount+1, *_pos.ToString()); //�ѱ۾��� ����?

	//�̺�Ʈ �߻� ���
	bool eventFlag = createEvent();
	//if (eventFlag)
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("Event Occur!!!"));
	//	_eventCount++;
	//}


	//// ������ ��ȯ�Ͽ� ���
	//UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: X=%d, Y=%d, 1stepDist: %f"),
	//	_moveCount + 1/*1���ؼ� ���*/,
	//	static_cast<int32>(_pos.X),
	//	static_cast<int32>(_pos.Y),
	//	dist,
	//	eventFlag ? TEXT(", Event Occur!!!") : TEXT("")
	//);


	if (eventFlag)
	{
		UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: X=%d, Y=%d, 1stepDist: %f, Event Occur!!!"),
			_moveCount + 1,
			static_cast<int32>(_pos.X),
			static_cast<int32>(_pos.Y),
			dist
		);
		_eventCount++;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: X=%d, Y=%d, 1stepDist: %f"),
			_moveCount + 1,
			static_cast<int32>(_pos.X),
			static_cast<int32>(_pos.Y),
			dist
		);
	}





	_moveCount++;

	//10�� �ݺ��ƴٸ� ������ �α� 
	if (_moveCount == 10)
		UE_LOG(LogTemp, Warning, TEXT("totalDist: %f, totalEvent: %d"),
			_toDist, _eventCount);
}

int32_t AMyActor::Step()
{
	// 1. �õ尪�� ��� ���� random_device ����
	std::random_device rd;

	// 2. Mersenne Twister ���� �ʱ�ȭ
	std::mt19937 gen(rd());

	// 3. 0���� 99���� �յ� ���� ����
	std::uniform_int_distribution<int> dis(0, 99);

	// 4. ���� ���� �� ��� ,2�� ������ ������ 0,1 

	return dis(gen) % 2;
}

float AMyActor::Distance(FVector2D first, FVector2D second)
{
	float Distance = FVector2D::Distance(first, second);

	//double ���� float���� �־ �ǳ�?
	/*float Distance = sqrtf((second.X - first.X) * (second.X - first.X)
						+ (second.Y - first.Y) * (second.Y - first.Y));*/

	return Distance;
}

bool AMyActor::createEvent()
{
	//// 1. �õ尪�� ��� ���� random_device ����
	//std::random_device rd;

	//// 2. Mersenne Twister ���� �ʱ�ȭ
	//std::mt19937 gen(rd());

	//// 3. 0���� 99���� �յ� ���� ����
	//std::uniform_int_distribution<int> eve(0, 99);

	//// 4. ���� ���� �� ��� ,2�� ������ ������ 0,1 

	//return eve(gen) % 2;
	return FMath::RandRange(0, 1) == 1;
}


