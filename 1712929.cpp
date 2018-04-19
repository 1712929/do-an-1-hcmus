#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <conio.h>
#pragma warning(disable: 4996 )
struct sv
{
	wchar_t mssv[11];
	wchar_t hoten[31];
	wchar_t khoa[31];
	int nienkhoa;
	wchar_t ngaysinh[11];
	wchar_t image[100];
	wchar_t mota[1001];
	wchar_t email[50];
	wchar_t sothich1[101];
	wchar_t sothich2[101];
};
int demsosv(FILE *&doc)
{
	int dem = 0;
	wchar_t *a = new wchar_t[1600];
	while (!feof(doc))
	{
		fgetws(a, 1600, doc);
		dem++;
	}
	return dem - 1;
}
void docthongtin(FILE *doc, sv *&x, int &n)
{
	n = demsosv(doc);
	x = new sv[n];
	fseek(doc, 124L, SEEK_SET);
	for (int i = 0; i < n; i++)
	{
		fwscanf(doc, L"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],", &x[i].mssv, &x[i].hoten, &x[i].khoa, &x[i].nienkhoa, &x[i].email, &x[i].ngaysinh, &x[i].image);
		wchar_t ch = fgetwc(doc);
		if (ch == L'\"')
			fwscanf(doc, L"%[^\"]\",", &x[i].sothich1);
		else
		{
			fseek(doc, -1L, SEEK_CUR);
			fwscanf(doc, L"%[^,],", &x[i].sothich1);
			x[i].sothich1[0] = ch;
		}
		ch = fgetwc(doc);
		if (ch == L'\"')
			fwscanf(doc, L"%[^\"]\",", &x[i].sothich2);
		else
		{
			fseek(doc, -1L, SEEK_CUR);
			fwscanf(doc, L"%[^,],", &x[i].sothich2);
			x[i].sothich2[0] = ch;
		}
		ch = fgetwc(doc);
		if (ch == L'\"')
			fwscanf(doc, L"%[^\"]\"\n", &x[i].mota);
		else
		{
			fseek(doc, -1L, SEEK_CUR);
			fwscanf(doc, L"%[^\n]\n", &x[i].mota);
			x[i].mota[0] = ch;
		}
	}
}
void xuatthongtin(FILE *doc,sv *SV, int &n)
{
	n = demsosv(doc);
	for (int i = 0; i < n; i++)
	{
		wprintf(L"\n\n\t************* SINH VIÊN THỨ %d ", i + 1);
		wprintf(L"\n-MSSV: %ls ", SV[i].mssv);
		wprintf(L"\n-Họ tên: %ls  ", SV[i].hoten);
		wprintf(L"\n-Khoa: %ls ", SV[i].khoa);
		printf("\n-Khóa: %d  ", SV[i].nienkhoa);
		wprintf(L"\n-Email: %ls  ", SV[i].email);
		wprintf(L"\n-Ngày sinh: %ls  ", SV[i].ngaysinh);
		wprintf(L"\n-Hình ảnh: %ls  ", SV[i].image);
		wprintf(L"\n-Mô tả bản thân:  %ls ", SV[i].mota);
		wprintf(L"\n-Sở thích 1: %ls  ", SV[i].sothich1);
		wprintf(L"\n-Sở thích 2: %ls  ", SV[i].sothich2);
	}
}
void main()
{
	FILE *doc_csv;
	sv *SV = NULL;
	int n;
	_wfopen_s(&doc_csv, L"npvy.csv", L"rt,ccs=UTF-8");
	if (doc_csv != NULL)
	{
		docthongtin(doc_csv, SV, n);
		xuatthongtin(doc_csv,SV,n);
		fclose(doc_csv);
	}
	else
		printf("File could not be opened.\n");
	delete[]SV;
	system("pause");
}
