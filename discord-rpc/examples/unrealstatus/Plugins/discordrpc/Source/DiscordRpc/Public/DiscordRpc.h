#pragma once

#include "ModuleManager.h"

class FDiscordRpcModule : public IModuleInterface {
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    void* DiscordRpcLibraryHandle;

    static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
    static void FreeDependency(void*& Handle);
};
