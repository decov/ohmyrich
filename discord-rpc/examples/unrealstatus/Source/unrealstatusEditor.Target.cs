using UnrealBuildTool;
using System.Collections.Generic;

public class unrealstatusEditorTarget : TargetRules
{
	public unrealstatusEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "unrealstatus" } );
	}
}
