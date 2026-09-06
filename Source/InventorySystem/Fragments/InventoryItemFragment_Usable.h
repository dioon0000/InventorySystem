#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "InventoryItemFragment_Usable.generated.h"

class UItemAction;
UCLASS()
class INVENTORYSYSTEM_API UInventoryItemFragment_Usable : public UInventoryItemFragment
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
	bool Use(AActor* ItemOwner);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options")
	bool bConsumeOnUse = true;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Actions")
	TArray<TObjectPtr<UItemAction>> OnUseActions;
};
