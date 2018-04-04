#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

struct date
{
	int year;
	int m;
	int d;
};

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	printf("Kakoe zadanie?\n");
	int n;
	scanf("%d", &n);
	FILE *file;
	if (n == 1)
	{
		FILE * fp;

		if ((fp = fopen("file", "r")) == NULL)
		{
			printf("Good bye!\n");
			exit(1);
		}
		else
		{
			printf("GOOD!\n");

			//system("chcp 1251");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			/*	for (int i = -128; i < 120; i++)
				{
					fputc(i, fp);
				}*/

			int ch = getc(fp);
			//while (ch != EOF)
			while (feof(fp) == 0)
			{
				printf("- %c\n", ch);
				ch = getc(fp);
			}

		}

		//fclose(fp);
		if (fclose(fp) == 0)
		{
			printf("Файл упешно закрыт!\n");
		}
		else
		{
			printf("Ошибка закрытия потока\n");
			exit(1);
		}
	}
	else if (n == 2)
	{
		FILE * file;
		char words[40];
		if ((file = fopen("file", "a+")) == NULL)
		{
			printf("Good bye!\n");
			exit(1);
		}
		else
		{
			puts("Vvedite slova. Najmite enter");
			puts("v nachale stroki dlya zavershwniya programmy");
			cin.get();
			while (gets_s(words) != NULL&&words[0] != '\0')
			{
				fprintf(file, "%s", words);
			}
			puts("Soderjimoe faila: ");
			//vernet ukazatel' v nachalo faila
			rewind(file);

			while (fscanf(file, "%s", words) == 1)
			{
				puts(words);
			}

			if (fclose(file) == 0)
			{
				printf("Файл упешно закрыт!\n");
			}
			else
			{
				printf("Ошибка закрытия потока\n");
				exit(1);
			}
		}
	}
	else if (n == 3)
	{
		FILE *file;

		char buffer[10];
		char *input = NULL;
		size_t curLen = 0;
		int t = 0;

		while (fgets(buffer, sizeof(buffer), stdin) != 0)
		{
			size_t bufLen = strlen(buffer);
			char * extra = (char*)realloc(input, bufLen + curLen + 1);

			if (extra == NULL)
				break;

			input = extra;
			strcpy(input + curLen, buffer);
			curLen += bufLen;

			t++;
			if (t > 3)
				break;
		}
		printf("%s [%d]", input, (int)strlen(input));
		free(input);
	}
	else if (n == 4)
	{
		FILE * file;
		double d = 12.23, newD;
		int i = 101, newI;
		long l = 123023L, newL;

		if ((file = fopen("fReadFile", "wb+")) == NULL)
		{
			printf("ERROR");
			exit(0);
		}
		else
		{
			fwrite(&d, sizeof(double), 1, file);
			fwrite(&i, sizeof(int), 1, file);
			fwrite(&l, sizeof(long), 1, file);

			rewind(file);

			fread(&newD, sizeof(double), 1, file);
			fread(&newI, sizeof(int), 1, file);
			fread(&newL, sizeof(long), 1, file);

			printf("%lf - %ld - %d", newD, newL, newI);

			fclose(file);
		}
	}
	else if (n == 5)
	{
		//1.	Дан файл, содержащий различные даты.Каждая дата - это число, месяц и год.Найти самую раннюю дату.
		unsigned int year;
		unsigned int m;
		unsigned d;
		if ((file = fopen("time", "w")) != NULL)
		{
			for (int i = 0; i < 10; i++)
			{
				year = 1950 + rand() % 100;
				m = 1 + rand() % 11;
				d = 1 + rand() % 30;
				fprintf(file, "%2d.%2d.%4d\n", d, m, year);
			}
			fclose(file);
		}
		if ((file = fopen("time", "r")) != NULL)
		{
			date dates[10];
			for (int i = 0; i < 10; i++)
			{
				fscanf(file, "%2d.%2d.%4d", &dates[i].d, &dates[i].m, &dates[i].year);
			}
			for (int i = 0; i < 10; i++)
			{
				printf("%2d.%2d.%4d\n", dates[i].d, dates[i].m, dates[i].year);
			}
			int min_y = 5000;
			int ind_i = 0;
			for (int i = 0; i < 10; i++)
			{
				if (dates[i].year < min_y)
				{
					min_y = dates[i].year;
					ind_i = i;
				}
			}
			int b = 0;
			for (int i = 0; i < 10; i++)
			{
				if (i != ind_i)
				{
					if (dates[i].year == min_y)b = 1;
				}
			}
			if (b == 0)
			{
				printf("Rannyaay data : %2d.%2d.%4d\n", dates[ind_i].d, dates[ind_i].m, dates[ind_i].year);
			}

			fclose(file);
		}
	}
	else if (n == 6)
	{
		//2.	Дан символьный файл f.Записать в файл g компоненты файла f в обратном порядке.
		FILE * nfile;
		if ((file = fopen("time", "r")) != NULL)
		{
			char r = fgetc(file);
			while ( r != '\n')
			{
				r=fgetc(file);
			}
			if ((nfile = fopen("time1", "w")) != NULL)
			{
				fputc(r, nfile);
			}
			fclose(file);
			fclose(nfile);
		}
	}
}



