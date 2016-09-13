#ifndef __TEST_DLL_H__
#define __TEST_DLL_H__

#if defined (EXPORTBUILD)  
# define _DLLExport extern "C" __declspec (dllexport)  
# else  
# define _DLLExport extern "C" __declspec (dllimport)  
#endif  

_DLLExport int add(int x, int y);

typedef struct
{
	int a;
	int b;
	int c;
} CppStruct;

_DLLExport bool getStructData(CppStruct& d);
// _DLLExport bool getStructData(CppStruct* d);

#endif
