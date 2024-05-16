#include "ProjectileSphere.h"
#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"

AProjectileSphere::AProjectileSphere() {
	this->Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
}

