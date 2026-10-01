#include "EquipmentInstance.h"

#include "EquipmentDefinition.h"
#include "Fragments/InventoryItemFragment_Equippable.h"
#include "GameFramework/Character.h"
#include "Items/ItemInstance.h"

void UEquipmentInstance::Initialize(UItemInstance* ItemInstance, ACharacter* Character)
{
	if (!ItemInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("UEquipmentInstance::Initialize - ItemInstance is Null"));
		return;
	}
	
	SourceItemInstance = ItemInstance;
	
	const UInventoryItemFragment_Equippable* EquippableFragment = 
		Cast<UInventoryItemFragment_Equippable>(
			ItemInstance->FindFragmentByClass(UInventoryItemFragment_Equippable::StaticClass())
			);
	
	if (!EquippableFragment)
	{
		UE_LOG(LogTemp, Error, TEXT(
			"UEquipmentInstance::Initialize - EquippableFragment is Null for ItemInstance : %s"), *ItemInstance->GetName()
			);
		
		return;
	}
	
	EquipmentDefinition = EquippableFragment->EquipmentDefinition;
	
	HandleEquipItem(Character);
}

void UEquipmentInstance::HandleEquipItem(ACharacter* Character)
{
	UEquipmentDefinition* EquipmentDefinitionCDO = EquipmentDefinition.GetDefaultObject();
	
	if (!EquipmentDefinitionCDO)
	{
		UE_LOG(LogTemp, Error, TEXT("UEquipmentInstance::HandleEquipItem - EquipmentDefinitionCDO is Null"));
		return ;
	}
	
	SpawnedEquipmentActor = GetWorld()->SpawnActor(EquipmentDefinitionCDO->EquipmentActorClass);
	
	if (!SpawnedEquipmentActor)
	{
		UE_LOG(LogTemp, Error, TEXT("UEquipmentInstance::HandleEquipItem - SpawnedEquipmentActor is Null"));
		return;
	}
	
	SpawnedEquipmentActor->AttachToComponent(
		Character->GetMesh(),
		FAttachmentTransformRules::SnapToTargetIncludingScale,
		EquipmentDefinitionCDO->AttachSocketName
		);
	
}

void UEquipmentInstance::HandleUnEquipItem(ACharacter* Character)
{
	if (SpawnedEquipmentActor)
	{
		SpawnedEquipmentActor->Destroy();
		// 가비지 컬렉터가 자동으로 제거할 수 있도록 포인터를 nullptr로 설정
		SpawnedEquipmentActor = nullptr;
	}
}
