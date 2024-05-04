#include "AnimNode_RefPoseConvert.h"

#include "Animation/AnimInstanceProxy.h"

void FAnimNode_RefPoseConvert::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Initialize_AnyThread())
	FAnimNode_Base::Initialize_AnyThread(Context);
	WaitToConvertPose.Initialize(Context);
}

void FAnimNode_RefPoseConvert::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(CacheBones_AnyThread)
	FAnimNode_Base::CacheBones_AnyThread(Context);
	WaitToConvertPose.CacheBones(Context);
}

void FAnimNode_RefPoseConvert::Update_AnyThread(const FAnimationUpdateContext& Context)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Update_AnyThread)
	FAnimNode_Base::Update_AnyThread(Context);
	WaitToConvertPose.Update(Context);
}

void FAnimNode_RefPoseConvert::Evaluate_AnyThread(FPoseContext& Output)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Evaluate_AnyThread)
	FAnimNode_Base::Evaluate_AnyThread(Output);

	if (!WaitToConvertPose.GetLinkNode())
	{
		return;
	}

	FPoseContext WaitToConvertPoseContext(Output);
	WaitToConvertPose.Evaluate(WaitToConvertPoseContext);

	for (const FCompactPoseBoneIndex BoneIndex : Output.Pose.ForEachBoneIndex())
	{
		const FTransform& BoneTransform = WaitToConvertPoseContext.Pose[BoneIndex];
		FTransform OutTransform = Output.Pose.GetRefPose(BoneIndex);

		// 位移直接相加
		OutTransform.AddToTranslation(BoneTransform.GetTranslation());

		if (!BoneTransform.GetRotation().IsIdentity())
		{
			OutTransform.SetRotation(BoneTransform.GetRotation());
		}

		Output.Pose[BoneIndex] = OutTransform;
	}
}
