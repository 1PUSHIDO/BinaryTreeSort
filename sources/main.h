#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <memory.h>
#include <time.h>

typedef char byte;
struct PARENT //��������� ����
{
	int value;
	struct PARENT* left;
	struct PARENT* right;
};
//��������������� �������
byte GenerateFile(FILE* file, int range_from, int range_to, unsigned long long amount) //��������� ������
{
	for (long long i = 0; i != amount; i++) {
		fprintf(file, "%d\n", range_from + rand() % (range_to - range_from + 1));
	}
	fclose(file);
	return 1;
}
//
//�������� �������
void StageGenerate() //
{
	system("cls");
	char filename[255] = "", *tmp;
	int from = 0, to = 0;
	unsigned long long amount = 0;
	for (;;) {
		printf("������� �������� ����� ��� ���������� ��������������� �����(ex. input): ");
		tmp = fgets(filename, sizeof(filename), stdin);
		fseek(stdin, 0, SEEK_END);
		if (*tmp != '\n')
			break;
		system("cls");
	}
	tmp = strchr(filename, '\n');
	strcpy(tmp, ".txt");

	printf("\n������� ���������� ����� ��� ���������: ");
	do {
		(void)scanf("%llu", &amount);
	} while (amount == 0);

	printf("\n������� �������� ������������� �����\n\t��: ");
	(void)scanf("%d", &from);
	printf("\n\t��: ");
	(void)scanf("%d", &to);
	
	FILE* file = fopen(filename, "w");
	if (!file) {
		printf("\n�� ������� �������/������� ����. ������� ����� ������� ��� �����������...");
		_getch();
		return;
	}
	time_t start = clock();
	GenerateFile(file, from, to, amount);
	time_t stop = clock();
	double time = (stop - start) / 1000.0;

	printf("\n������������� %llu ����� �� %0.3f ������. ������� ����� ������� ��� �����������...", amount, time);
	_getch();
	system("cls");
}
//