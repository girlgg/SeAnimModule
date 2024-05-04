#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "SeAnimModuleRuntime/Public/AnimNode_RefPoseConvert.h"
#include "AnimGraphNode_RefPoseConvert.generated.h"

/**
 * 
 */
UCLASS()
class SEANIMMODULEEDITOR_API UAnimGraphNode_RefPoseConvert : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FString GetNodeCategory() const override;

	UPROPERTY(EditAnywhere, Category = Settings)
	FAnimNode_RefPoseConvert Node;
};
