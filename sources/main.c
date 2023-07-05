#include "main.h"

int main() {
	//формат кодировки github
	setlocale(LC_ALL, ".UTF8");
	system("cls");

	char menu[] = "\n\n\tМеню\n\n"
		"\t\tИсходные данные\n"
		"\t1) Генерация\n\n"
		"\t\tСортировка\n"
		"\t2) Сортировка по возрастанию\n"
		"\t3) Сортировка по убыванию\n\n"
		"\t\tПрограмма\n"
		"\t4) Выход из программы\n";

	printf(menu);
	for (;;) {
		switch (getch()) {
		case '1':
			//генерация массива чисел для входного файла
			StageGenerate();
			system("cls");
			printf(menu);
			break;
		case '2':
			//сортировка входного файла по возрастанию для выходного файла
			StageSort(1);
			system("cls");
			printf(menu);
			break;
		case '3':
			//сортировка входного файла по убыванию для выходного файла
			StageSort(2);
			system("cls");
			printf(menu);
			break;
		case '4':
			//выход из программы
			return 0;
			break;
		}
	}
}