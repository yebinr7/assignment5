// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "random"
#include "chrono"

// Sets default values
AMyActor::AMyActor()
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
	UE_LOG(LogTemp, Warning, TEXT("_pos: X=%d, Y=%d"),
		static_cast<int32>(_pos.X),
		static_cast<int32>(_pos.Y));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//매 프레임 엑터가 할 로직 
	if(_moveCount<10)
		RandomTenMove();
}

void AMyActor::RandomTenMove()
{

	_pos = { (_pos.X + Step()), (_pos.Y + Step()) };

	//UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: %s\n"), _moveCount+1, *_pos.ToString()); //한글쓰면 오류?

	  // 정수로 변환하여 출력
	UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: X=%d, Y=%d"),
		_moveCount + 1,
		static_cast<int32>(_pos.X),
		static_cast<int32>(_pos.Y)
	);
	_moveCount++;
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


