#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <conio.h>
#include "readcsv.h"
#pragma warning(disable: 4996 )
struct sv
{
	wchar_t *mssv;
	wchar_t *hoten;
	wchar_t *khoa;
	wchar_t *nienkhoa;
	wchar_t *ngaysinh;
	wchar_t *image;
	wchar_t *mota;
	wchar_t *email;
	unsigned int demsothich;
	wchar_t **sothich;
};
void dssv(sv *&SV, int sosv, wchar_t **line)
{
	SV = new sv[sosv];
	for (int i = 0; i < sosv; i++)
	{
		int vt = 0;
		wchar_t *dong = new wchar_t[sosv];
		dong = line[i];
		variable(dong, vt, SV[i].mssv);
		variable(dong, vt, SV[i].hoten);
		variable(dong, vt, SV[i].khoa);
		variable(dong, vt, SV[i].nienkhoa);
		variable(dong, vt, SV[i].ngaysinh);
		variable(dong, vt, SV[i].image);
		variable(dong, vt, SV[i].mota);
		variable(dong, vt, SV[i].email);
		// so thich
		wchar_t *tmp = L"tmp";
		unsigned int dem = 0;
		SV[i].demsothich = 0;
		while (tmp != L"")
		{
			tmp = L"";
			variable(dong, vt, tmp);
			if (tmp != L"")
			{
				khoitao(SV[i].sothich[dem], dem);
				SV[i].sothich[dem] = tmp;
				dem++;
			}
		}
		SV[i].demsothich = dem;
	}
}
void xuatdssv(sv *SV, int sosv)
{
	for (int i = 0; i < sosv; i++)
	{
		wprintf(L"\n\n\t************* SINH VIÊN THỨ %d ", i + 1);
		wprintf(L"\n-MSSV: %ls ", SV[i].mssv);
		wprintf(L"\n-Họ tên: %ls  ", SV[i].hoten);
		wprintf(L"\n-Khoa: %ls ", SV[i].khoa);
		wprintf(L"\n-Khóa: %ls  ", SV[i].nienkhoa);
		wprintf(L"\n-Ngày sinh: %ls  ", SV[i].ngaysinh);
		wprintf(L"\n-Hình ảnh: %ls  ", SV[i].image);
		wprintf(L"\n-Mô tả bản thân:  %ls ", SV[i].mota);
		wprintf(L"\n");
	}
}
void wmain()
{
	FILE *doc;
	wchar_t *lines, *filename;
	int sosv = 0;
	sv *SV;
	wchar_t *fomart = L"mssv,hoten,khoa,nienkhoa,ngaysinh,image,mota,sothich";
	sosv = demsosv(doc, filename);
}
