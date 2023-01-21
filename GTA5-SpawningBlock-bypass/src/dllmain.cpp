#include "Hooking.h"

void init()
{
    hook::nop(scanner::GetAddress(L"GTA5.exe", "48 85 C0 0F 84 ? ? ? ? 8B 48 50"), 0x18); // entity request block
    hook::nop(scanner::GetAddress(L"GTA5.exe", "FF 52 ? 84 C0 ? ? 48 8B C3", 5), 2); // player spawn checks
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		init();
	}

	return TRUE;
}

