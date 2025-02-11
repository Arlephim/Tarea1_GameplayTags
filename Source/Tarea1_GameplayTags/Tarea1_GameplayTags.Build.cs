// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tarea1_GameplayTags : ModuleRules
{
	public Tarea1_GameplayTags(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput"});
        
        PrivateDependencyModuleNames.AddRange(new string[]
        {
	        "GameplayAbilities", "GameplayTasks", "GameplayTags"
        });
    }
}
