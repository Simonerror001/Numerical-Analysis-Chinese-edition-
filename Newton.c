/*
牛顿插值 : C语言
Created on Mar 11, 2018
@author: Wang Yufei
*/

#include<stdio.h>
#include<stdlib.h>                   //malloc    

int main()
{
	int num;
	printf("请输入插值点的个数：");
	scanf("%d", &num);
	double *x, **y;
	x = (double *)malloc(sizeof(double) * num);         //分配内存
	y = (double **)malloc(sizeof(double*) * num);       //注意是二维数组
	for (int i = 0; i < num; i++)
		y[i] = (double *)malloc(sizeof(double) * num);

	for (int i = 0; i < num; i++) {                     //插值点的输入
		printf("请输入第%d个点的坐标，空格隔开：\n", i + 1);
		scanf("%lf %lf", &x[i], &y[0][i]);
	}
	double x0;
	printf("请输入要计算的x的值：");
	scanf("%lf", &x0);

	double sum = y[0][0];                         //插值计算
	double x_xi = x0 - x[0];
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < num - i; j++) {
			double a1 = x[j];                     //使用递推方法求解插值
			double a2 = x[i + j];                   //i+j获取副对角线元素下标
			y[i][j] = (y[i - 1][j + 1] - y[i - 1][j]) / (a2 - a1);
		}
		sum += y[i][0] * x_xi;
		x_xi *= (x0 - x[i]);
	}
	printf("\n利用牛顿插值法得到的结果是：%lf\n", sum);

	for (int i = 0; i < num; i++)                 //释放内存
		free(y[i]);
	free(y);
	free(x);

	system("pause");
	return 0;
}
