#pragma once
#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
*  in your project.
*/

#define DLL_EXPORT __declspec(dllexport)


#ifdef __cplusplus
extern "C"
{
#endif

	//ZBrush expects these arguments for a dll function, though it's best to only use the first three
	float DLL_EXPORT Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

	float DLL_EXPORT HelloDLL(char* sometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

	long double DLL_EXPORT LaunchAppWithFile(LPCSTR lpFile, int a2, int a3, int a4);

	int DLL_EXPORT anhungxadieu(int num, double number, void* memblock, void* memblock2);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__