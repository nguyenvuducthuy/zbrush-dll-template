// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include <cstring>
#include <strstream>
#include <string> // std strings

#include "dllmain.h"
#include "pch.h"

#include "shellapi.h"

using namespace std;

string helloDll = "Hello from my DLL";

//init thing 
int main() {
	//some code here..
}

// a sample exported function
float DLL_EXPORT Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	return 5.0f;
}



float  DLL_EXPORT HelloDLL(char* someText, double optValue, char* outputBuffer, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	MessageBoxA(0, someText, "DLL received Message", MB_OK | MB_ICONINFORMATION);
	strcpy(outputBuffer, helloDll.c_str());

	return 0.0f;
}

long double DLL_EXPORT LaunchAppWithFile(LPCSTR lpFile, int a2, int a3, int a4)
{
	const CHAR *v5; // application path
	const CHAR *v6; // file to open by application path

	if (a4 != 0 && lpFile != 0)
	{
		v6 = lpFile;
		v5 = (const CHAR *)a4;
	}
	else
	{
		if (a4 != 0 || lpFile == 0)
			return -1.0;
		v5 = lpFile;
		v6 = 0;
	}
	ShellExecuteA(0, "open", v5, v6, 0, 1);

	return 0.0;
}

int DLL_EXPORT anhungxadieu(int num, double number, void* memblock, void* memblock2)
{
	int mbSize = (int)number; // the second argument has to be a double

	// Read from the memory block via a strstream
	std::strstream mbStream((char*)memblock, mbSize);

	// Read the first integer written into the memory block by the ZScript
	int val = 0;
	mbStream.read((char*)&val, 4);

	MessageBoxA(0, mbStream.str() , "kuku", MB_OK | MB_ICONINFORMATION);
	string kuku = std::to_string(num);
	strcpy((char*)memblock, kuku.c_str());

	return val;
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

//	default:
//		break;
	}
	return TRUE;

}

