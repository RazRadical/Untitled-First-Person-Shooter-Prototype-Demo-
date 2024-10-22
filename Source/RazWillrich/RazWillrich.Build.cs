// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RazWillrich : ModuleRules
{
	public RazWillrich(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks", "UMG", "Slate", "SlateCore" });
	}
}
