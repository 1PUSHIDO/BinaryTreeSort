#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
//
//
//основные функции
//
//