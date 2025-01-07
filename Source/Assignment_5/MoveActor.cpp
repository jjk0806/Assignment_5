#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timerHandle;
	startLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Start!!"));
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AMoveActor::Move, 1, true, 2);
}

void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float distance(const FVector& first, const FVector& second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx*dx +  dy*dy);
}

FVector AMoveActor::SetMoveVector()
{
	int32 RandomValue1 = FMath::RandRange(0, 1);
	int32 RandomValue2 = FMath::RandRange(0, 1);	

	while (RandomValue1 == 0 && RandomValue2 == 0)
	{
		RandomValue1 = FMath::RandRange(0, 1);
		RandomValue2 = FMath::RandRange(0, 1);
	}

	return FVector(RandomValue1, RandomValue2, 0);
}

void AMoveActor::Move()
{
	SetActorLocation(GetActorLocation() + SetMoveVector());
	++moveCount;

	if (moveCount % 10 == 0)	
	{
		UE_LOG(LogTemp, Warning, TEXT("Move! Dist: %f, MoveCount: %d"), distance(startLocation, GetActorLocation()), moveCount);
	}	
}
