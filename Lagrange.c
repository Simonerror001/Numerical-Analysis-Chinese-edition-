/*
拉格朗日插值
Created on Mar 5, 2018
@author: Wang Yufei
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	printf("请输入插值点的个数：");
	scanf_s("%d", &num);
	double *x, *y;
	x = (double *)malloc(sizeof(double) * num);
	y = (double *)malloc(sizeof(double) * num);
	for (int i = 0; i < num; i++) {
		printf("请输入第%d个点的坐标，空格隔开：\n", i + 1);
		scanf_s("%lf %lf", &x[i], &y[i]);         //插值点的输入
	}
	
	double x0;
	printf("请输入要计算的x的值：");
	scanf_s("%lf", &x0);

	double sum = 0;                             //插值计算
	for (int i = 0; i < num; i++) {
		double temp = 1.0;
		for (int j = 0; j < num; j++) {
			if (j == i)
				continue;
			temp *= (x0 - x[j]) / (x[i] - x[j]);
		}
		sum += y[i] * temp;
	}

	printf("\n利用拉格朗日插值多项式得到的结果是：%lf\n", sum);
	free(x);
	free(y);


	return 0;
}
