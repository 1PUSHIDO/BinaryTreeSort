#include "main.h"

int main() {
	system("chcp 1251"); //изменение кодировки консоли
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
			StageGenerate();
			printf(menu);
			break;
		case '2':
			//функция - сортировка по возрастанию
			break;
		case '3':
			//функция - сортировка по убыванию
			break;
		case '4':
			return 0;//выход из программы
			break;
		}
	}
}