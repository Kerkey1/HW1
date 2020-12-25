#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
void output(int** Array, int N) {
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", Array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void GenWeighed(int** Array, int N) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int z = rand() % 100;
			if (z > 80) {
				Array[i][j] = rand() % N;
			}
			else {
				Array[i][j] = 0;
			}
			Array[j][i] = Array[i][j];
			if (i == j) {
				Array[i][j] = 0;
			}
		}
	}
	output(Array, N);
}
void ClearDistanceWeighed(int* Dist, int N) {
	for (int i = 0; i < N; i++) {
		Dist[i] = 1000;
	}
}
void BFSWeighed(int** Array, int v, int* DIST, int N) {
	std::queue <int> Q;
	Q.push(v);
	DIST[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if (Array[v][i] > 0 && DIST[i] > DIST[v] + Array[v][i]) {
				Q.push(i);
				DIST[i] = DIST[v] + Array[v][i];
			}
		}
	}
	
}
void BFSIN(int** Array, int* DIST, int i, int count, int N) {

	for (int j = 0; j < count; j++) {
		if (Array[i][j] != 0) {
			for (int k = 0; k < N; k++) {
				if ((Array[k][j] != 0) && (DIST[k] == 1000)) {
					DIST[k] = DIST[i] + Array[k][j];
					BFSIN(Array, DIST, i, count, N);
				}
			}
		}
	}

}
void transfer(int **ArrayM1,int **ArrayM2,int N,int count) {
	int index;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < count; j++) {
			ArrayM2[i][j] = 0;
		}
	}

	
	for (int i =index= 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (ArrayM1[i][j] != 0) {	
				ArrayM2[i][index] = ArrayM2[j][index]=ArrayM1[i][j];
				index++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < count; j++) {
			printf("%d\t", ArrayM2[i][j]);
		}
		printf("\n");
	}
}
void operations(int** ArrayM1, int* eks,int N, int* DIST, int R, int D, int count ) {
	printf("Матрица смежности:\n");
	GenWeighed(ArrayM1, N);
	ClearDistanceWeighed(DIST, N);
	for (int i = 0; i < N; i++) {
		eks[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		BFSWeighed(ArrayM1, i, DIST, N);
		for (int j = 0; j < N; j++) {
			if (eks[i] < DIST[j] && DIST[j] != 1000) {
				eks[i] = DIST[j];
			}
		}
		if (eks[i] < R && eks[i] != 0) {
			R = eks[i];
		}
		if (eks[i] > D) {
			D = eks[i];
		}

		ClearDistanceWeighed(DIST, N);
	}
	printf("Вершины:");
	for (int i = 0; i < N; i++) {
		printf("%d ", eks[i]);
	}
	printf("\nРадиус: %d", R);
	printf("\nДиаметр: %d", D);
	printf("\nЦентральные вершины:");
	for (int i = 0; i < N; i++) {
		if (eks[i] == R) {
			printf("%d ", i + 1);
		}
	}
	printf("\nПереферийные вершины:");
	for (int i = 0; i < N; i++) {
		if (eks[i] == D) {
			printf("%d ", i + 1);
		}
	}
	printf("\nИзолированные:");
	for (int i = 0; i < N; i++) {
		if (eks[i] == 0) {
			printf("%d ", i + 1);
		}
	}

	printf("\nКонцевые:");
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < N; j++) {
			if (ArrayM1[i][j] != 0) {
				count++;
			}
		}
		if (count == 1) {
			printf("%d ", i + 1);
		}
	}

	printf("\nДоминирующие:");
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < N; j++) {
			if (ArrayM1[i][j] != 0) {
				count++;
			}
		}
		if (count == N - 1) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");
}
void ioperations(int** ArrayM2, int* eks, int N, int* DIST, int R, int D, int count) {
	ClearDistanceWeighed(DIST, N);
	for (int i = 0; i < N; i++) {
		eks[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		DIST[i] = 0;
		BFSIN(ArrayM2, DIST, i, count, N);
		for (int k = 0; k < N; k++) {
			if ((eks[i] < DIST[k]) && (DIST[k] != 1000)) {
				eks[i] = DIST[k];
			}
		}
		if ((eks[i] < R) && (eks[i] != 0)) {
			R = eks[i];
		}
		if (eks[i] > D) {
			D = eks[i];
		}
		ClearDistanceWeighed(DIST, N);
	}
	printf("Вершины:");
	for (int i = 0; i < N; i++) {
		printf("%d ", eks[i]);
	}
	printf("\nРадиус: %d", R);
	printf("\nДиаметр: %d", D);
	printf("\nЦентральные вершины:");
	for (int i = 0; i < N; i++) {
		if (eks[i] == R) {
			printf("%d ", i + 1);
		}
	}
	printf("\nПереферийные вершины:");
	for (int i = 0; i < N; i++) {
		if (eks[i] == D) {
			printf("%d ", i + 1);
		}
	}
	printf("\nИзолированные:");
	for (int i = 0; i < N; i++) {
		if (eks[i] == 0) {
			printf("%d ", i + 1);
		}
	}

	printf("\nКонцевые:");
	for (int i = 0; i < N; i++) {
		int index = 0;
		for (int j = 0; j < count; j++) {
			if (ArrayM2[i][j] != 0) {
				index++;
			}
		}
		if (index == 1) {
			printf("%d ", i + 1);
		}
	}

	printf("\nДоминирующие:");
	for (int i = 0; i < N; i++) {
		int index = 0;
		for (int j = 0; j < count; j++) {
			if (ArrayM2[i][j] != 0) {
				index++;
			}
		}
		if (index == count) {
			printf("%d ", i + 1);
		}
	}
}
int main()

{

	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	int count=0;
	int N = 0;
	int  D = -1, R = 10000;
	int** ArrayM1 = NULL;
	int** ArrayM2 = NULL;
	int* DIST = NULL;
	int* eks = NULL;
	scanf("%d", &N);
	DIST = (int*)malloc(N * sizeof(int));
	eks = (int*)malloc(N * sizeof(int));
	ArrayM1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		ArrayM1[i] = (int*)malloc(N * sizeof(int));
	}
	//Матрица смежности//
	operations(ArrayM1, eks, N, DIST, R, D, count);
	//Матрица инцидентности//
	D = -1, R = 10000; count = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (ArrayM1[i][j] != 0) {
				count++;
			}
		}
	}

	printf("Количество рёбер=%d\n",count);
	ArrayM2 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		ArrayM2[i] = (int*)malloc(count * sizeof(int));
	}
	transfer(ArrayM1, ArrayM2, N, count);
	ioperations(ArrayM2, eks, N, DIST, R, D, count);

}


