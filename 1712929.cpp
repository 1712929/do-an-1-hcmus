#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#pragma warning(disable: 4996 )
struct sv
{
	wchar_t mssv[11];
	wchar_t hoten[31];
	wchar_t khoa[31];
	int nienkhoa;
	wchar_t ngaysinh[11];
	wchar_t image[100];
	wchar_t motabanthan[1001];
	wchar_t sothich1[101];
	wchar_t sothich2[101];
};
int demsosv(FILE *&doc)
{
	int dem = 0;
	wchar_t *a = new wchar_t[256];
	if (a == NULL) {
		printf("No memory\n");
		return 1;
	}
	if ((doc = _wfopen(L"npvy.csv", L"r")) == NULL) //Đọc file
	{
		printf("File could not be opened.\n");
	}
	while (!feof(doc))
	{
		fgetws(a, 255, doc);
		if (!feof(doc))
		{
			fgetws(a, 255, doc);
			dem++;
		}
		else break;
	}
	return dem;
}
void doctungthongtin(FILE *&p, wchar_t *arvg[])
{
	unsigned int nskiplines, currentline, lenlongestvalue;
	wchar_t *temp = new wchar_t[255];
	int c;
	unsigned int x; // danh dau ki tu gia tri
	int QuotationOnOff; //0 - off, 1 - on
	nskiplines = _wtoi(arvg[2]);
	lenlongestvalue = _wtoi(arvg[3]);
	if (p = _wfopen(L"npvy.csv", L"r"))
	{
		rewind(p);
		currentline = 1;
		x = 0;
		QuotationOnOff = 0;
		while (c = fgetwc(p) != EOF)
		{
			switch (c)
			{
			case ',':
				if (!QuotationOnOff&& currentline > nskiplines)
				{
					temp[x] = '\0';
					x = 0;
				}
				break;
			case '\n':
				if (currentline > nskiplines)
				{
					temp[x] = '\0';
					x = 0;
				}
				currentline++;
				break;
			case'\"':
				if (currentline > nskiplines)
				{
					if (!QuotationOnOff)
					{
						QuotationOnOff = 1;
						temp[x] = c;
						x++;
					}
				}
				break;
			default:
				if (currentline > nskiplines)
				{
					temp[x] = c;
					x++;
				}
				break;
			}
		}
	}
}
void docfile(sv *p,FILE *&doc)
{
	int i = 0;
	wchar_t ch;
	_setmode(_fileno(stdout), _O_WTEXT); //xuat
	_setmode(_fileno(stdin), _O_WTEXT);  //vao
	int vtten1 = ftell(doc);

}
void main()
{
	FILE *a;
	int dem;
	dem = demsosv(a);
	printf("%d\n", dem);
	system("pause");
}