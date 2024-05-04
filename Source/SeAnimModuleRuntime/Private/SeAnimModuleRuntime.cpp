// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeAnimModuleRuntime.h"

#define LOCTEXT_NAMESPACE "FSeAnimModuleRuntimeModule"

void FSeAnimModuleRuntimeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSeAnimModuleRuntimeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSeAnimModuleRuntimeModule, SeAnimModuleRuntime)