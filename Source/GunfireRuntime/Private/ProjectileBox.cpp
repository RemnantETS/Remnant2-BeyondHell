#include "ProjectileBox.h"
#include "Components/BoxComponent.h"

AProjectileBox::AProjectileBox() {
	this->Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
}

