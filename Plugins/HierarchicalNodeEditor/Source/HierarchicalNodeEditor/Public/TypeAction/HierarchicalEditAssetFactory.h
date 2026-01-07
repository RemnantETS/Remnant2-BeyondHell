// Copyright Gunfire Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HierarchicalEditAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class UHierarchicalEditAssetFactory: public UFactory
{
	GENERATED_BODY()

public:
	UHierarchicalEditAssetFactory(const FObjectInitializer& ObjectInitializer);

public: //UFactory
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
	virtual bool ConfigureProperties() override;

private:
	UClass* AssetClass;
};
