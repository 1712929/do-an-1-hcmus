#ifndef memory_h
#define memory_h
#include<stdio.h>
#include <iostream>
#include <wchar.h>
#pragma warning(disable: 4996 )
void khoitao(wchar_t *&a, int n)
{
	wchar_t *temp = new wchar_t[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = a[i];
	}
	a = new wchar_t[n + 1];
	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}
	delete[]temp;
}
#endif