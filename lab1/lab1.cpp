#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

int main()
{   
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int sum=0;
	int min=0;
	int max=0;
	int nmax=0;
	int nmin=0;
	const int ROW=5,COL=5;
	int ArrayB[ROW][COL];
	srand(time(NULL));
	int* Array = NULL;
	int SIZE;
	int search = 0;

	/*gen array*/
	printf("������ ���������� ���������:");
	scanf("%d", &SIZE);
	Array = (int*)malloc(sizeof(int)*SIZE);
	for(int i = 0; i < SIZE; i++) 
	{
		Array[i] = rand()%101;
	}
     /*output array*/
	for(int i = 0; i < SIZE; i++) 
	{
		printf("%d ", Array[i]);	
	}
	max = Array[0];
	min = Array[0];

	/*find max and min */
	for (int i=0; i< SIZE; i++){
		if(Array[i]<min){
			min=Array[i];
			nmin=i;
		}
		if(Array[i]>max){
			max=Array[i];
			nmax=i;
		}
	}

	/*search sub*/
	nmax=nmax-nmin;
	max=max-min;
	printf("\n ����������:%d\n ��������:%d\n", abs(nmax),max);

	/*gen arrayB*/
	for(int i = 0;i < ROW;i++){
		for(int j = 0;j < COL;j++){
			ArrayB[i][j] = rand()%101;
		}
	}
	for(int i = 0;i < ROW;i++){
		for(int j = 0; j < COL;j++){
			printf("%d ", ArrayB[i][j]);
			sum=sum+ ArrayB[i][j];
		}
		printf("����� � ������ =%d\n", sum);
		sum = 0;
		printf("\n");
	}
	/*input structure*/
	int i;
	for ( i = 0; i < 3; i++)
	{
		printf(" ������� ������� ��������:");
		scanf("%s", stud[i].famil);
		printf(" ������� ��� ��������:");
		scanf("%s", stud[i].name);
		printf(" ������� �������� ����������:");
		scanf("%s", stud[i].facult);
		printf(" ������� ����� �������� ������:");
		scanf(" %d", &stud[i].Nomzach);
		printf("\n");
	}
	/*ouput structure*/
	for (i = 0; i < 3; i++)
	{
			printf("������� ��������: %s\n", stud[i].famil);
			printf("��� ��������: %s\n", stud[i].name);
			printf("���������: %s\n", stud[i].facult);
			printf("����� �������� ������: %d\n\n", stud[i].Nomzach);
	}
	/*serch student*/
	printf(" ������� ����� �������� ������:");
	scanf("%d", &search);

		for (i = 0; i < 3; i++)
		{
			if(stud[i].Nomzach == search){
				printf("������� ��������: %s\n", stud[i].famil);
				printf("��� ��������: %s\n", stud[i].name);
				printf("���������: %s\n", stud[i].facult);
				printf("����� �������� ������: %d\n", stud[i].Nomzach);
			}

		}
	_getch();
}