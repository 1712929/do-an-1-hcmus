#ifndef read_csv_h
#define read_csv_h
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include"memory.h"
#include <fstream>
#pragma warning(disable: 4996 )
int demsosv(FILE *&doc,wchar_t *filename)
{
	int dem = 0;
	wchar_t *a = (wchar_t*)malloc(sizeof(wchar_t));
	FILE *f =_wfopen(filename, L"w, ccs=UTF-8");
	while (!feof(doc))
	{
		fgetws(a, sizeof(wchar_t), doc);
		dem++;
		khoitao(a, dem);
	}
	fclose(f);
	return dem;
}
void vitriphancach(wchar_t *&line, int &vt)
{
	while (line[vt] != ','&&vt < wcslen(line))
	{
		vt++;
	}
	vt++;
}
void vitrisauspace(wchar_t *&line, int &vt)
{
	while (line[vt] != ' '&&vt < wcslen(line))
	{
		vt++;
	}
}
void vitriphancachcokep(wchar_t *&line, int &vt, wchar_t *&ch)
{
	ch = L"";
	vt++;
	while (line[vt] != L'\"'&& vt < wcslen(line))
	{
		ch += line[vt];
		vt++;
	}
	vitriphancach(line, vt);
	vitrisauspace(line, vt);
}
void vitriphancachkhongkep(wchar_t *&line, int &vt, wchar_t *&ch)
{
	ch = L"";
	vt++;
	while (line[vt] != L','&& vt < wcslen(line))
	{
		ch += line[vt];
		vt++;
	}
	vitriphancach(line, vt);
	vitrisauspace(line, vt);
}
void variable(wchar_t *&line, int &vt, wchar_t *&ch)
{
	if (line[vt] == '\"')
	{
		vitriphancachcokep(line, vt, ch);
	}
	else vitriphancachkhongkep(line, vt, ch);
}
#endif 