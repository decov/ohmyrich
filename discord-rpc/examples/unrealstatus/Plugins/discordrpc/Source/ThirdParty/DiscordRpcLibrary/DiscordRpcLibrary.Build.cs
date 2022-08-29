using System.IO;
using UnrealBuildTool;

public class DiscordRpcLibrary : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
    public DiscordRpcLibrary(ReadOnlyTargetRules Target) : base(Target)
#else
    public DiscordRpcLibrary(TargetInfo Target)
#endif
    {
        Type = ModuleType.External;
        Definitions.Add("DISCORD_DYNAMIC_LIB=1");

        string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "..", "ThirdParty", "DiscordRpcLibrary"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string lib = Path.Combine(BaseDirectory, "Win64");

            PublicIncludePaths.Add(Path.Combine(BaseDirectory, "Include"));

            PublicLibraryPaths.Add(lib);
            PublicAdditionalLibraries.Add(Path.Combine(lib, "discord-rpc.lib"));

            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(lib, "discord-rpc.dll")));
            PublicDelayLoadDLLs.Add("discord-rpc.dll");
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            string lib = Path.Combine(BaseDirectory, "Linux", "x86_64-unknown-linux-gnu");

            PublicIncludePaths.Add(Path.Combine(BaseDirectory, "Include"));

            PublicLibraryPaths.Add(lib);
            PublicAdditionalLibraries.Add(Path.Combine(lib, "libdiscord-rpc.so"));
            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(lib, "libdiscord-rpc.so")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            string lib = Path.Combine(BaseDirectory, "Mac");

            PublicIncludePaths.Add(Path.Combine(BaseDirectory, "Include"));

            PublicLibraryPaths.Add(lib);
            PublicAdditionalLibraries.Add(Path.Combine(lib, "libdiscord-rpc.dylib"));
            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(lib, "libdiscord-rpc.dylib")));
        }
    }
}
