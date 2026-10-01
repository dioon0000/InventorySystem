#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "InventoryItemFragment_Equippable.generated.h"

class UEquipmentDefinition;

UCLASS()
class INVENTORYSYSTEM_API UInventoryItemFragment_Equippable : public UInventoryItemFragment
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TSubclassOf<UEquipmentDefinition> EquipmentDefinition;
};
