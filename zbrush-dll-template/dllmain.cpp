// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <cstring>
#include "dllmain.h"
#include "pch.h"

// a sample exported function
float DLL_EXPORT Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	return 1.0f;
}



float  DLL_EXPORT HelloDLL(char* someText, double optValue, char* outputBuffer, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	MessageBoxA(0, someText, "DLL received Message",MB_OK | MB_ICONINFORMATION);
	strcpy(outputBuffer, "Hello from my DLL");
	
	return 0.0f;
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD fdwReason,
	LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load. 
		break;

	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;
	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		// Perform any necessary cleanup.
		break;
	default:
		break;
	}
	return TRUE;

}

