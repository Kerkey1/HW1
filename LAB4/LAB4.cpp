#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

void output(int** Array, int N) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", Array[i][j]);
		}
		printf("\n");
	}
}

void Gen(int** Array, int N) {
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Array[i][j] = rand() % 2;
			Array[j][i] = Array[i][j];
			if (i == j) {
				Array[i][j] = 0;
			}
		}

	}

	output(Array, N);
}
void DFS(int u, int** Array, int* visitedArray, int N) {
	printf("%d ", u+1);

	visitedArray[u] = 1;
	for (int uNext = 0; uNext < N; uNext++) {
		if (Array[u][uNext] && visitedArray[uNext] != 1) {
			DFS(uNext, Array, visitedArray,N);
		}
	}
}
void DFSN(int v, int **Array,int* visitedArray, int N)
{
	
	std::stack<int>S;
	S.push(v);
	visitedArray[v] = 1;
	while (!S.empty()) {
		v = S.top();
		printf("%d ", v + 1);
		S.pop();
		
		int i = N - 1;
		while (i!=0) {
			if (Array[v][i] == 1 && visitedArray[i] != 1) {
				visitedArray[i] = 1;
				S.push(i);
			}
			i--;
		}
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	int M = 0;
	int N = 0;
	int u= 0;
	int** ArrayM1 = NULL;
	int** ArrayM2 = NULL;
	int* Visitedarray = NULL;
	
	printf("Введите размерность матрицы:");
	scanf("%d", &N);

	ArrayM1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		ArrayM1[i] = (int*)malloc(N * sizeof(int));
	}
	Gen(ArrayM1, N);

	Visitedarray = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N;i++) {
		Visitedarray[i] = 0;
	}

	printf("Введите размерность матрицы:");
	scanf("%d", &M);
	ArrayM2 = (int**)malloc(M * sizeof(int*));
	for (int i = 0; i < M; i++)
	{
		ArrayM2[i] = (int*)malloc(M * sizeof(int));
	}
	Gen(ArrayM2, M);

	printf("\n");
	for (int i = 0; i < N; i++) {
		if ( Visitedarray[i] == 0) {
			
			DFS(i, ArrayM1, Visitedarray,N);
		}
	}

	printf("\n");
	for (int i = 0; i < N; i++) {
		Visitedarray[i] = 0;
	}
	printf("\n");
	

		for (int i = 0; i < N; i++) {
			if (Visitedarray[i] == 0) {

				DFSN(i, ArrayM1, Visitedarray, N);
			}
		}
	
	
}


