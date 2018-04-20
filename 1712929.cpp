#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <conio.h>
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
	wchar_t **sothich;
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
	return dem-1;
}
void docthongtin1sv(FILE *doc, unsigned &demsothich, sv &A)
{
	_setmode(_fileno(doc), _O_U8TEXT);
	wchar_t* p = (wchar_t*)malloc(sizeof(sv));
	demsothich = 0;
	wchar_t* flag[10];
	wchar_t* del;
	if (doc != NULL)
	{
		fgetws(p, sizeof(sv), doc);
		del = wcstok(p, L"\"");
		A.mssv = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.hoten = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.khoa = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.nienkhoa = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.ngaysinh = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.image = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.email = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		A.mota = wcstok(NULL, L"\"");
		del = wcstok(NULL, L"\"");
		flag[demsothich] = wcstok(NULL, L"\"");
		while (flag[demsothich] != NULL)
		{
			demsothich++;
			del = wcstok(NULL, L"\"");
			flag[demsothich] = wcstok(NULL, L"\"");
		}
		A.sothich = (wchar_t**)malloc(demsothich * sizeof(wchar_t*));
		for (int i = 0; i < demsothich; i++)
		{
			*(A.sothich + i) = flag[i];
		}
		free(A.sothich);
	}
}
void docdssv(FILE *doc,int &n)
{
	n = demsosv(doc);
	unsigned int demsothich;
	sv *a = (sv*)malloc(n*sizeof(sv));// bi loi!
	for (int i = 0; i < n; i++)
	{
		docthongtin1sv(doc, demsothich, a[i]);
	}
}
void xuatthongtin(FILE *doc, sv *SV, int &n,unsigned int &demsothich)
{
	n = demsosv(doc);
	for (int i = 0; i < n; i++)
	{
		wprintf(L"\n\n\t************* SINH VIÊN THỨ %d ", i + 1);
		wprintf(L"\n-MSSV: %ls ", SV[i].mssv);
		wprintf(L"\n-Họ tên: %ls  ", SV[i].hoten);
		wprintf(L"\n-Khoa: %ls ", SV[i].khoa);
		wprintf(L"\n-Khóa: %ls  ", SV[i].nienkhoa);
		wprintf(L"\n-Email: %ls  ", SV[i].email);
		wprintf(L"\n-Ngày sinh: %ls  ", SV[i].ngaysinh);
		wprintf(L"\n-Hình ảnh: %ls  ", SV[i].image);
		wprintf(L"\n-Mô tả bản thân:  %ls ", SV[i].mota);
		for (int j = 0; j < demsothich; j++)
			wprintf(L"\n-Sở thích: %ls \n ", *(SV[i].sothich + j));
	}
}
void main()
{
	FILE *doc_csv;
	sv *SV = NULL;
	unsigned int demsothich;
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	_wfopen_s(&doc_csv, L"npvy.csv", L"rt,ccs=UTF-8");
	if (doc_csv != NULL)
	{
		int n = demsosv(doc_csv);
		docdssv(doc_csv, n);
		xuatthongtin(doc_csv, SV, n,demsothich);
		fclose(doc_csv);
	}
	else
		printf("File could not be opened.\n");
	delete[]SV;
	system("pause");
}
