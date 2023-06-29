#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <memory.h>
#include <time.h>

typedef char byte;
struct PARENT //структура узла
{
	int value;
	struct PARENT* left;
	struct PARENT* right;
};
//вспомогательные функции
byte GenerateFile(FILE* file, int range_from, int range_to, unsigned long long amount) //генерация данных
{
	for (long long i = 0; i != amount; i++) {
		fprintf(file, "%d\n", range_from + rand() % (range_to - range_from + 1)); //запись случайного числа в файл
	}
	return 1;
}
byte FileToTreeInput(FILE* file, struct PARENT* root, unsigned long long* count) //преобразование массива данных из файла в двоичное дерево
{
	struct PARENT* current = root;
	if (fscanf(file, "%i,", &(root->value)) <= 0)
		return 0;
	int tmp = 0;
	* count = 1;
	for (;;) {
		if (fscanf(file, "%i\n", &tmp) <= 0)
			return 1;
		(* count)++;
		for (;;) {
			if (tmp >= current->value) {
				if (!current->right) {
					current->right = (struct PARENT*)malloc(sizeof(struct PARENT));
					current->right->left = NULL; current->right->right = NULL;
					current->right->value = tmp;
					current = root;
					break;
				}
				else
					current = current->right;
			}
			else if (tmp < current->value) {
				if (!current->left) {
					current->left = (struct PARENT*)malloc(sizeof(struct PARENT));
					current->left->left = NULL; current->left->right = NULL;
					current->left->value = tmp;
					current = root;
					break;
				}
				else
					current = current->left;
			}
		}
	}
}
void BinarySortOutput(struct PARENT* root, FILE* file, byte type) //бинарная сортировка, вывод в выходной файл
{
	if (!root)
		return;
	if (type == 1) {
		BinarySortOutput(root->left, file, type);
		fprintf(file, "%d\n", root->value);
		BinarySortOutput(root->right, file, type);
	}
	else {
		BinarySortOutput(root->right, file, type);
		fprintf(file, "%d\n", root->value);
		BinarySortOutput(root->left, file, type);
	}
}

//основные функции
void StageGenerate() //функция меню - генерация массива чисел для входного файла
{
	system("cls");
	char filename[260] = "", *tmp;
	int from = 0, to = 0;
	unsigned long long amount = 0;
	for (;;) {
		printf("Введите название входного файла(ex. input): ");
		tmp = fgets(filename, sizeof(filename), stdin);
		fseek(stdin, 0, SEEK_END);
		if (*tmp != '\n')
			break;
		system("cls");
	}
	tmp = strchr(filename, '\n');
	strcpy(tmp, ".txt");

	printf("\nВведите количество чисел для генерации: ");
	do {
		(void)scanf("%llu", &amount);
	} while (amount == 0);

	printf("\nВведите интервал генерирования чисел\n\tОт: ");
	(void)scanf("%d", &from);
	printf("\n\tДо: ");
	(void)scanf("%d", &to);
	
	FILE* file = fopen(filename, "w");
	if (!file) {
		printf("\nНе удалось создать/открыть файл. Нажмите любую клавишу для продолжения...");
		(void)_getch();
		return;
	}
	time_t start = clock();
	GenerateFile(file, from, to, amount);
	time_t stop = clock();
	double time = (stop - start) / 1000.0;
	fclose(file);

	printf("\nСгенерировано %llu чисел за %0.3f секунд. Нажмите любую клавишу для продолжения...", amount, time);
	(void)_getch();
}
void StageSort(byte type) //пункт меню - сортировка массива чисел входного файла для выходного файла
{
	system("cls");
	char filename_input[260] = "", filename_output[260] = "", * tmp;
	unsigned long long count = 0;

	for (;;) {
		printf("Введите название входного файла(ex. input): ");
		tmp = fgets(filename_input, sizeof(filename_input), stdin);
		fseek(stdin, 0, SEEK_END);
		if (*tmp != '\n')
			break;
		system("cls");
	}
	tmp = strchr(filename_input, '\n');
	strcpy(tmp, ".txt");
	FILE* file_input = fopen(filename_input, "r");
	if (!file_input) {
		printf("\nФайл не найден. Нажмите любую клавишу для продолжения...");
		(void)_getch();
		return;
	}

	for (;;) {
		printf("\nВведите название выходного файла(ex. output): ");
		tmp = fgets(filename_output, sizeof(filename_output), stdin);
		fseek(stdin, 0, SEEK_END);
		if (*tmp != '\n')
			break;
		system("cls");
	}
	tmp = strchr(filename_output, '\n');
	strcpy(tmp, ".txt");
	FILE* file_output = fopen(filename_output, "w");
	if (!file_output) {
		fclose(file_input);
		printf("\nНе удалось создать/открыть файл. Нажмите любую клавишу для продолжения...");
		(void)_getch();
		return;
	}
	
	time_t start = clock();
	
	struct PARENT* root = (struct PARENT*)malloc(sizeof(struct PARENT));
	root->left = NULL; root->right = NULL;
	if (!FileToTreeInput(file_input, root, &count)) {
		_fcloseall();
		printf("\nСлишком мало чисел для сортировки. Нажмите любую клавишу для продолжения...");
		(void)_getch();
	}
	BinarySortOutput(root, file_output, type);
	_fcloseall();
	
	time_t stop = clock();
	double time = (stop - start) / 1000.0;
	printf("\nСортировка по %s: обработано %llu чисел за %0.3f секунд. Нажмите любую клавишу для продолжения...", type == 0 ? "возрастанию" : "убыванию", count, time);
	(void)_getch();
}