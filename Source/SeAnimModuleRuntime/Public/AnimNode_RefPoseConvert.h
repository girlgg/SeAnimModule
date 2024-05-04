#pragma once
#include "CoreMinimal.h"
#include "AnimNode_RefPoseConvert.generated.h"

USTRUCT(BlueprintInternalUseOnly)
struct SEANIMMODULERUNTIME_API FAnimNode_RefPoseConvert : public FAnimNode_Base
{
	GENERATED_BODY()

public:
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink WaitToConvertPose;
};
