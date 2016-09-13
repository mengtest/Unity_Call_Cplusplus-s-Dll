#ifndef __TEST_DLL_H__
#define __TEST_DLL_H__

#if defined (EXPORTBUILD)  
# define _DLLExport __declspec (dllexport)  
# else  
# define _DLLExport __declspec (dllimport)  
#endif  

extern "C" int _DLLExport add(int x, int y);

#endif
