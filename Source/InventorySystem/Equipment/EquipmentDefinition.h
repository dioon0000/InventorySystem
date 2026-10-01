#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EquipmentDefinition.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract, Const)
class INVENTORYSYSTEM_API UEquipmentDefinition : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment Actor")
	TSubclassOf<AActor> EquipmentActorClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment Actor")
	FName AttachSocketName;
};
