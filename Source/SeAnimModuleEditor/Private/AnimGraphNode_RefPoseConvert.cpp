#include "AnimGraphNode_RefPoseConvert.h"

#define LOCTEXT_NAMESPACE "AnimGraphNode_RefPoseConvert"

FText UAnimGraphNode_RefPoseConvert::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("RefPoseConvert", "RefPoseConvert");
}

FLinearColor UAnimGraphNode_RefPoseConvert::GetNodeTitleColor() const
{
	return FLinearColor(FColor::Orange);
}

FString UAnimGraphNode_RefPoseConvert::GetNodeCategory() const
{
	return TEXT("Convert");
}

#undef LOCTEXT_NAMESPACE
