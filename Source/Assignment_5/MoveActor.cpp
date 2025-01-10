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
	UE_LOG(LogTemp, Warning, TEXT("Start!!"));
	currentLocation = startLocation;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AMoveActor::Move, 1, true, 2);
}

void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//test
}

float distance(const FVector2D& first, const FVector2D& second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx*dx +  dy*dy);
}

FVector2D AMoveActor::SetMoveVector()
{
	int32 RandomValue1 = FMath::RandRange(0, 1);
	int32 RandomValue2 = FMath::RandRange(0, 1);	

	while (RandomValue1 == 0 && RandomValue2 == 0)
	{
		RandomValue1 = FMath::RandRange(0, 1);
		RandomValue2 = FMath::RandRange(0, 1);
	}

	return FVector2D(RandomValue1, RandomValue2);
}

void AMoveActor::Move()
{
	FVector2D randomVector = SetMoveVector();
	currentLocation += randomVector;
	UE_LOG(LogTemp, Warning, TEXT("%s randomVector Move! CurrentLocation: %s"), *randomVector.ToString(), *currentLocation.ToString());
	++moveCount;

	if (moveCount % 10 == 0)	
	{
		UE_LOG(LogTemp, Warning, TEXT("Move! Dist: %f, MoveCount: %d"), distance(startLocation, currentLocation), moveCount);
		UE_LOG(LogTemp, Warning, TEXT("EventFunction Call"));
	}	
}
