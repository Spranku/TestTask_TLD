// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestTask_TLD : ModuleRules
{
	public TestTask_TLD(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"TestTask_TLD",
			"TestTask_TLD/Variant_Platforming",
			"TestTask_TLD/Variant_Platforming/Animation",
			"TestTask_TLD/Variant_Combat",
			"TestTask_TLD/Variant_Combat/AI",
			"TestTask_TLD/Variant_Combat/Animation",
			"TestTask_TLD/Variant_Combat/Gameplay",
			"TestTask_TLD/Variant_Combat/Interfaces",
			"TestTask_TLD/Variant_Combat/UI",
			"TestTask_TLD/Variant_SideScrolling",
			"TestTask_TLD/Variant_SideScrolling/AI",
			"TestTask_TLD/Variant_SideScrolling/Gameplay",
			"TestTask_TLD/Variant_SideScrolling/Interfaces",
			"TestTask_TLD/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
