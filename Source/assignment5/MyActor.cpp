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

	//현재 엑터의 위치 가져오기 
	//FVector CurrentLocation = GetActorLocation(); //FVector XYZ 좌표 
	
	//1. 엑터 시작 위치
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

	//매 프레임 엑터가 할 로직 총10번 0~9 
	if (_moveCount < 10)
		RandomTenMove();
	

}

void AMyActor::RandomTenMove()
{
	//이전 위치
	FVector2D prvPos = FVector2D(_pos.X, _pos.Y);

	//업뎃한 위치
	_pos =  FVector2D(_pos.X + Step(), (_pos.Y + Step()));

	//거리 구하기
	float  dist = Distance(prvPos, _pos);
	
	//누적 거리 구하기
	_toDist += dist;


	//UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: %s\n"), _moveCount+1, *_pos.ToString()); //한글쓰면 오류?

	//이벤트 발생 출력
	bool eventFlag = createEvent();
	//if (eventFlag)
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("Event Occur!!!"));
	//	_eventCount++;
	//}


	//// 정수로 변환하여 출력
	//UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: X=%d, Y=%d, 1stepDist: %f"),
	//	_moveCount + 1/*1더해서 출력*/,
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

	//10번 반복됐다면 마지막 로그 
	if (_moveCount == 10)
		UE_LOG(LogTemp, Warning, TEXT("totalDist: %f, totalEvent: %d"),
			_toDist, _eventCount);
}

int32_t AMyActor::Step()
{
	// 1. 시드값을 얻기 위한 random_device 생성
	std::random_device rd;

	// 2. Mersenne Twister 엔진 초기화
	std::mt19937 gen(rd());

	// 3. 0부터 99까지 균등 분포 정의
	std::uniform_int_distribution<int> dis(0, 99);

	// 4. 난수 생성 및 출력 ,2로 나누면 나머지 0,1 

	return dis(gen) % 2;
}

float AMyActor::Distance(FVector2D first, FVector2D second)
{
	float Distance = FVector2D::Distance(first, second);

	//double 형을 float형에 넣어도 되나?
	/*float Distance = sqrtf((second.X - first.X) * (second.X - first.X)
						+ (second.Y - first.Y) * (second.Y - first.Y));*/

	return Distance;
}

bool AMyActor::createEvent()
{
	//// 1. 시드값을 얻기 위한 random_device 생성
	//std::random_device rd;

	//// 2. Mersenne Twister 엔진 초기화
	//std::mt19937 gen(rd());

	//// 3. 0부터 99까지 균등 분포 정의
	//std::uniform_int_distribution<int> eve(0, 99);

	//// 4. 난수 생성 및 출력 ,2로 나누면 나머지 0,1 

	//return eve(gen) % 2;
	return FMath::RandRange(0, 1) == 1;
}


