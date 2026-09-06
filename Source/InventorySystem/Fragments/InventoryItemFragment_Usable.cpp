#include "InventoryItemFragment_Usable.h"

#include "ItemActions/ItemAction.h"

bool UInventoryItemFragment_Usable::Use(AActor* ItemOwner)
{
	bool bAnySucceeded = false;
	
	for (const TObjectPtr<UItemAction>& Action : OnUseActions)
	{
		if (Action && Action->Execute(ItemOwner))
		{
			bAnySucceeded = true;
		}
	}
	return bAnySucceeded;
}
