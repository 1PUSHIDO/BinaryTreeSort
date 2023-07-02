#include "main.h"

int main() {
	setlocale(LC_ALL, ".UTF8");//формат кодировки github
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
			StageGenerate();//генерация массива чисел для входного файла
			system("cls");
			printf(menu);
			break;
		case '2':
			StageSort(1);//сортировка входного файла по возрастанию для выходного файла
			system("cls");
			printf(menu);
			break;
		case '3':
			StageSort(2);//сортировка входного файла по убыванию для выходного файла
			system("cls");
			printf(menu);
			break;
		case '4':
			return 0;//выход из программы
			break;
		}
	}
}