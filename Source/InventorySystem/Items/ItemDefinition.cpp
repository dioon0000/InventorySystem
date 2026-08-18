#include "Items/ItemDefinition.h"
#include "Fragments/InventoryItemFragment.h"

const UInventoryItemFragment* UItemDefinition::FindFragmentByClass(const TSubclassOf<UItemDefinition> ItemDefinition,
                                                                   const TSubclassOf<UInventoryItemFragment> FragmentClass)
{
	// 입력받은 아이템 클래스와 프래그먼트 클래스가 유효하다면 프래그먼트 클래스를 반환
	if (ItemDefinition && FragmentClass)
	{
		UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
		
		for (const TObjectPtr<UInventoryItemFragment>& Fragment : ItemCDO->Fragments)
		{
			if (Fragment->IsA(FragmentClass))
			{
				return Fragment;
			}
		}
	}

	return nullptr;
}
