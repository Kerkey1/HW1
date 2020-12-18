#define _CRT_SECURE_NO_WARNINGS       
#define _CRT_NONSTDC_NO_DEPRECATE     
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>  
#include <time.h>
#include <queue>
#include <iostream>
void output(int** Array, int N);
int GenWeighedOriented(int** Array, int N);
int BFS(int** Array, int s, int t, int* parent, int N);
int FF(int** Array, int s, int t, int N);
int Save(int** Array,int result,int s,int t, int N);