#include "main.h"

int main() {
	system("chcp 1251"); //��������� ��������� �������
	system("cls");

	char menu[] = "\n\n\t����\n\n"
		"\t\t�������� ������\n"
		"\t1) ���������\n\n"
		"\t\t����������\n"
		"\t2) ���������� �� �����������\n"
		"\t3) ���������� �� ��������\n\n"
		"\t\t���������\n"
		"\t4) ����� �� ���������\n";

	printf(menu);
	for (;;) {
		switch (getch()) {
		case '1':
			StageGenerate();
			printf(menu);
			break;
		case '2':
			//������� - ���������� �� �����������
			break;
		case '3':
			//������� - ���������� �� ��������
			break;
		case '4':
			return 0;//����� �� ���������
			break;
		}
	}
}