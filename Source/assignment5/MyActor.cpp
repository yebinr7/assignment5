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

	//���� ������ ��ġ �������� 
	//FVector CurrentLocation = GetActorLocation(); //FVector XYZ ��ǥ 
	
	//1. ���� ���� ��ġ
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

	//�� ������ ���Ͱ� �� ���� 
	if(_moveCount<10)
		RandomTenMove();
}

void AMyActor::RandomTenMove()
{

	_pos = { (_pos.X + Step()), (_pos.Y + Step()) };

	//UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: %s\n"), _moveCount+1, *_pos.ToString()); //�ѱ۾��� ����?

	  // ������ ��ȯ�Ͽ� ���
	UE_LOG(LogTemp, Warning, TEXT("time: %d, pos: X=%d, Y=%d"),
		_moveCount + 1,
		static_cast<int32>(_pos.X),
		static_cast<int32>(_pos.Y)
	);
	_moveCount++;
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


