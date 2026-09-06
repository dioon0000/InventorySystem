#include "ItemInstance.h"
#include "ItemDefinition.h"
#include "Fragments/InventoryItemFragment.h"

float UItemInstance::GetStatValue(FGameplayTag StatTag)
{
	return StatsMap.FindRef(StatTag);
}

void UItemInstance::SetStatValue(FGameplayTag StatTag, float StatValue)
{
	StatsMap.Add(StatTag, StatValue);
}

void UItemInstance::Initialize(TSubclassOf<UItemDefinition> ItemDef, const TMap<FGameplayTag, float>& InitalStats)
{
	if (!ItemDef)
	{
		return ;
	}
	
	ItemDefinition = ItemDef;
	
	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
		
	for (const TObjectPtr<UInventoryItemFragment>& Fragment : ItemCDO->Fragments)
	{
		Fragment->OnInstanceCreated(this);
	}
	
	if (!InitalStats.IsEmpty())
	{
		StatsMap = InitalStats;
	}
}

const UInventoryItemFragment* UItemInstance::FindFragmentByClass(const TSubclassOf<UInventoryItemFragment> FragmentClass)
{
	if (!FragmentClass) return nullptr;
	
	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
	
	return ItemCDO->FindFragmentByClass(ItemDefinition, FragmentClass);
}
