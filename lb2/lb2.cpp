#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

double shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	double start_time = clock();
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
	double end_time = clock();
	double search_time = end_time - start_time;
	return(search_time);	
}
double qs(int* items, int left, int right) 
{
int i, j;
int x, y;
i = left; j = right;
x = items[(left + right) / 2+100];
double start_time = clock();
do {
	while ((items[i] < x)&& (i < right)) i++;
	while ((x < items[j]) && (j > left)) j--;
	if (i <= j) {
		y = items[i];
		items[i] = items[j];
		items[j] = y;
		i++; j--;
	}
} while (i <= j);
if (left < j) qs(items, left, j);
if (i < right) qs(items, i, right); 
double end_time = clock();
double search_time = end_time - start_time;
return(search_time);
}
void First_array(int * Array_random, int* Array_increase, int* Array_decrease, int* Array_saw,int count) {

	for (int i = 0; i < count; i++) {
		Array_random[i] = rand() % 100;
	}
	for (int i = 0; i < count; i++) {
		Array_increase[i] = i;
	}
	for (int i = 0; i < count; i++) {
		Array_decrease[i] = count - i;
	}
	for (int i = 0; i < count; i++) {
		if (i <= count / 2) {
			Array_saw[i] = i;
		}
		if (i > count / 2) {
			Array_saw[i] = count - i;
		}
	}
}
void Second_array(int* Array_random, int* Array_increase, int* Array_decrease, int* Array_saw, int count) {


	for (int i = 0; i < count; i++) {
		Array_random[i] = rand() % 100;
	}
	for (int i = 0; i < count; i++) {
		Array_increase[i] = i;
	}
	for (int i = 0; i < count; i++) {
		Array_decrease[i] = count - i;
	}
	for (int i = 0; i < count; i++) {
		if (i <= count / 2) {
			Array_saw[i] = i;
		}
		if (i > count / 2) {
			Array_saw[i] = count - i;
		}
	}
}
void Third_array(int* Array_random, int* Array_increase, int* Array_decrease, int* Array_saw, int count) {


	for (int i = 0; i < count; i++) {
		Array_random[i] = rand() % 100;
	}
	for (int i = 0; i < count; i++) {
		Array_increase[i] = i;
	}
	for (int i = 0; i < count; i++) {
		Array_decrease[i] = count - i;
	}
	for (int i = 0; i < count; i++) {
		if (i <= count / 2) {
			Array_saw[i] = i;
		}
		if (i > count / 2) {
			Array_saw[i] = count - i;
		}
	}
}
int comp(const int* i, const int* j)
{
	return *i - *j;
}

int main(){
	FILE* fp;
	fp = fopen("output.txt", "w");
	double start_time,end_time,search_time;

	srand(time(NULL));
	int count;
	int k10 = 10000;
	int k20 = 20000;
	int k50 = 50000;
	int k100 = 100000;

	//10k//

	int* Array_random = new int[k10];
	int* Array_increase = new int[k10];
	int* Array_decrease = new int[k10];
	int* Array_saw = new int[k10];
	//SHELL//
	fprintf(fp,"SHELL 10k\n");
	First_array(Array_random, Array_increase, Array_decrease, Array_saw, k10);
	search_time = shell(Array_random, k10);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_increase, k10);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_decrease, k10);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_saw, k10);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//QS//
	fprintf(fp, "QS 10k\n");
	Second_array(Array_random, Array_increase,Array_decrease, Array_saw, k10);
	int left = 0;
	int right = k10 - 1;
	search_time=qs(Array_random,left,  right);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_increase, left, right);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_decrease, left, right);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_saw, left, right);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//LQS//
	fprintf(fp, "LQS 10k\n");
	Third_array(Array_random, Array_increase, Array_decrease, Array_saw, k10);
	start_time = clock();
	qsort(Array_random, k10, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_increase, k10, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_decrease, k10, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_saw, k10, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	fprintf(fp,"_____________________\n");
	//20k//

	Array_random = new int[k20];
	Array_increase = new int[k20];
	Array_decrease = new int[k20];
	Array_saw = new int[k20];
	//SHELL//
	fprintf(fp, "SHELL 20k\n");
	First_array(Array_random, Array_increase, Array_decrease, Array_saw, k20);
	search_time = shell(Array_random, k10);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_increase, k20);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_decrease, k20);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_saw, k20);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//QS//
	fprintf(fp, "QS 20k\n");
	Second_array(Array_random, Array_increase, Array_decrease, Array_saw, k20);
	right = k20 - 1;	
	search_time = qs(Array_random, left, right);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_increase, left, right);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_decrease, left, right);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_saw, left, right);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//LQS//
	fprintf(fp, "LQS 20k\n");
	Third_array(Array_random, Array_increase, Array_decrease, Array_saw, k20);
	start_time = clock();
	qsort(Array_random, k20, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_increase, k20, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_decrease, k20, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_saw, k20, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	fprintf(fp, "_____________________\n");
	//50k//

	Array_random = new int[k50];
	Array_increase = new int[k50];
	Array_decrease = new int[k50];
	Array_saw = new int[k50];
	//SHELL//
	fprintf(fp, "SHELL 50k\n");
	First_array(Array_random, Array_increase, Array_decrease, Array_saw, k50);
	search_time = shell(Array_random, k50);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_increase, k50);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_decrease, k50);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_saw, k50);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//QS//
	fprintf(fp, "QS 50k\n");
	Second_array(Array_random, Array_increase, Array_decrease, Array_saw, k50);
	right = k50 - 1;
	search_time = qs(Array_random, left, right);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_increase, left, right);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_decrease, left, right);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_saw, left, right);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//LQS//
	fprintf(fp, "LQS 50k\n");
	Third_array(Array_random, Array_increase, Array_decrease, Array_saw, k50);
	start_time = clock();
	qsort(Array_random, k50, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_increase, k50, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_decrease, k50, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_saw, k50, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	fprintf(fp, "_____________________\n");
	//100k//

	Array_random = new int[k100];
	Array_increase = new int[k100];
	Array_decrease = new int[k100];
	Array_saw = new int[k100];
	//SHELL//
	fprintf(fp, "SHELL 100\n");
	First_array(Array_random, Array_increase, Array_decrease, Array_saw, k100);
	search_time = shell(Array_random, k100);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_increase, k100);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_decrease, k100);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = shell(Array_saw, k100);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//QS//
	fprintf(fp, "QS 100\n");
	Second_array(Array_random, Array_increase, Array_decrease, Array_saw, k100);
	right = k100 - 1;
	search_time = qs(Array_random, left, right);
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_increase, left, right);
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_decrease, left, right);
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	search_time = qs(Array_saw, left, right);
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);
	//LQS//
	fprintf(fp, "LQS 100k\n");
	Third_array(Array_random, Array_increase, Array_decrease, Array_saw, k100);
	start_time = clock();
	qsort(Array_random, k100, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "random: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_increase, k100, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "increase: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_decrease, k100, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "decrease: %lf\n", search_time / CLK_TCK);
	start_time = clock();
	qsort(Array_saw, k100, sizeof(int), (int(*) (const void*, const void*)) comp);
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(fp, "saw: %lf\n\n", search_time / CLK_TCK);


	fclose(fp);
	system("PAUSE");
	_getch();

}