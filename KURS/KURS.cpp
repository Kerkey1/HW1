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
int GenWeighedOriented(int** Array, int N) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int z = rand() % 100;
			if (z > 40) {
				Array[i][j] = rand() % N;
			}
			else {
				Array[i][j] = 0;
			}
			if (i == j) {
				Array[i][j] = 0;
			}
		}
	}
	output(Array, N);
	return **Array;
}

int BFS(int** Array, int s, int t, int* parent, int N) {
	int* visited = NULL;
	visited = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N;i++) {
		visited[i] = 0;
	}
	std::queue <int> Q;
	Q.push(s);
	visited[s] = 1;
	parent[s] = -1;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if (visited[i]==0 && Array[u][i]>0) {
				Q.push(i);
				parent[i] = u;
				visited[i] = 1;
			}
		}
	}
	printf("\n");
	return (visited[t] == 1);
}
int FF(int **Array,int s,int t,int N) {
	int** rArray = NULL;
	int u, v;
	int max_flow = 0;
	rArray = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		rArray[i] = (int*)malloc(N * sizeof(int));
	}

	for (u = 0; u < N; u++) {
		for (v = 0; v < N; v++) {
			rArray[u][v] = Array[u][v];
		}
	}
	int* parent = NULL;
	parent = (int*)malloc(N * sizeof(int));
	while (BFS(rArray, s, t, parent,N)) {

		int path_flow = INT_MAX;
		
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			printf("%d<-", v);
			path_flow = fmin(path_flow, rArray[u][v]);
			
		}
		printf("%d", s);
		printf("\nПоток:%d", path_flow);
		for (v = t; v != s; v = parent[v]){
			u = parent[v];
			rArray[u][v] -= path_flow;
			rArray[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
		return max_flow;
}
int Save(int **Array,int result, int s, int t,int N) {
	FILE* fp;
	char name[] = "result.txt";
	if ((fp = fopen(name, "w+")) == NULL)
	{
		printf("Не удалось открыть файл");
		getchar();
		return 0;
	}
	else {
		printf("Файл успешно сохранён");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fprintf(fp, "%d\t", Array[i][j]);
			}
			fprintf(fp,"\n");
		}
		if (result == 0) {
			fprintf(fp,"Путей нет!");
		}
		else
		fprintf(fp,"Максимальный возможный поток из %d в %d:%d", s,t, result);
	}
	return 0;
}