using UnrealBuildTool;
using System.Collections.Generic;

public class unrealstatusTarget : TargetRules
{
	public unrealstatusTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "unrealstatus" } );
	}
}
