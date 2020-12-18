#include "Header.h"
int** ArrayM1 = NULL;
int N = 0;
int s = 0, t = 0;
int result = 0;
static int value = 1;
int print_menu(int index) {
	setlocale(LC_ALL, "Rus");
	printf("\n\n\n\n\n\n\n                                                   ___________________\n");
	if (index > 4 || index < 0) return 0;
	(index == 1) ? printf("                                                  |______Создание_____|\n") : printf("                                                  |      Создание     |\n");
	(index == 2) ? printf("                                                  |______Алгоритм_____|\n") : printf("                                                  |      Алгоритм     |\n");
	(index == 3) ? printf("                                                  |_____Сохранение____|\n") : printf("                                                  |     Cохранение    |\n");
	(index == 4) ? printf("                                                  |_______Выход_______|\n") : printf("                                                  |       Выход       |\n");
	printf("                                                  |___________________|\n");
}

void selected(int button) {
	system("cls");
	if (button == 1) {
		system("cls");
		printf("Введите размерность матрицы:");
		scanf("%d", &N);
		ArrayM1 = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			ArrayM1[i] = (int*)malloc(N * sizeof(int));
		}
		GenWeighedOriented(ArrayM1,N);
	}
	else if (button == 2) {
		
		system("cls");
		if (N == 0) {
			printf("Пожалуйста, сгенерируйте матрицу.");
		}
		else {
			output(ArrayM1, N);
			printf("Введите исходную вершину:");
			scanf("%d", &s);
			printf("Введите конечную вершину:");
			scanf("%d", &t);
			if (s == t) {
				printf("Введите другие числа!");
			}
			else {
				result = FF(ArrayM1, s, t, N);
				if (result == 0) {
					printf("Путей нет!");
				}
				else
					printf("Максимальный возможный поток:%d", result);
			}
		}
	}
	else if (button == 3) {
		system("cls");
		Save(ArrayM1,result,s,t,N);

	}
	else if (button == 4) {

		exit(0);
	}
	getch();
}

int button_process() {

	char ch = '0';
	while (!kbhit());
	ch = getch();
	switch (ch) {
	case '1':
		value = ch - 0x30;
		selected(value);

		break;
	case '2':
		value = ch - 0x30;
		selected(value);
		break;
	case '3':
		value = ch - 0x30;
		selected(value);
		break;

	case '4':
		value = ch - 0x30;
		selected(value);
		break;
	}
		if (ch == 72) {
			//Arrow up
			value -= 1;
			if (value == 0) value = 4;
		}
		else if (ch == 80) {
			//Arrow down
			value += 1;
			if (value == 5) value = 1;
		}
		else if (ch == 13) {
			// Enter button
			selected(value);

		}
		return value;
	
}
int menu(){
	int button = 1;
	while (1) {
		print_menu(button);
		button = button_process();
		system("cls");
	}
	system("PAUSE");
}
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	menu();
}
