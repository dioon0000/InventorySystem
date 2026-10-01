#include "InventoryItemFragment_Usable.h"

#include "ItemActions/ItemAction.h"

bool UInventoryItemFragment_Usable::Use(AActor* ItemOwner, UItemInstance* ItemInstance)
{
	bool bAnySucceeded = false;
	
	for (const TObjectPtr<UItemAction>& Action : OnUseActions)
	{
		if (Action && Action->Execute(ItemOwner, ItemInstance))
		{
			bAnySucceeded = true;
		}
	}
	return bAnySucceeded;
}
