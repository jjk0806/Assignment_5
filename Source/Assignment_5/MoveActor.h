#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class ASSIGNMENT_5_API AMoveActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector2D SetMoveVector();
	void Move();
	UPROPERTY(VisibleAnywhere)
	int32 moveCount = 0;
	UPROPERTY(VisibleAnywhere)
	FVector2D startLocation = FVector2D(0,0);
	UPROPERTY(VisibleAnywhere)
	FVector2D currentLocation;
};
