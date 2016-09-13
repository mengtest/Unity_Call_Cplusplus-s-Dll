#define EXPORTBUILD

#include "test.h"

_DLLExport int add(int x, int y)
{
	return x + y;
}

_DLLExport bool getStructData(CppStruct& d)
{
	d.a = 10;
	d.b = 20;
	d.c = 30;

	return false;
}

// _DLLExport bool getStructData(CppStruct* d)
// {
//  d->a = 10;
//  d->b = 20;
//  d->c = 30;
//
//  return false;
// }