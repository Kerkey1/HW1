#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <random>


int main()

{   
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
	/*генерация массива*/
	scanf("%d", &SIZE);
	Array = (int*)malloc(sizeof(int)*SIZE);
	for(int i = 0; i < SIZE; i++) 
	{
		Array[i] = rand()%101;
	}
     /*Вывод массива*/
	for(int i = 0; i < SIZE; i++) 
	{
		printf("%d ", Array[i]);	
	}

	max = Array[0];
	min = Array[0];
	/*Поиск max и min */
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
	/*Поиск разницы*/
	nmax=nmax-nmin;
	max=max-min;
	printf("\n rad:%d\n raz:%d\n", abs(nmax),max);
	/**/
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
		printf("summ in a row=%d\n", sum);
		sum = 0;
		printf("\n");
	}
	
	_getch();
}