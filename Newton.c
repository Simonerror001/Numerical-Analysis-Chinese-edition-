/*
ţ�ٲ�ֵ : C����
Created on Mar 11, 2018
@author: Wang Yufei
*/

#include<stdio.h>
#include<stdlib.h>                   //malloc    

int main()
{
	int num;
	printf("�������ֵ��ĸ�����");
	scanf("%d", &num);
	double *x, **y;
	x = (double *)malloc(sizeof(double) * num);         //�����ڴ�
	y = (double **)malloc(sizeof(double*) * num);       //ע���Ƕ�ά����
	for (int i = 0; i < num; i++)
		y[i] = (double *)malloc(sizeof(double) * num);

	for (int i = 0; i < num; i++) {                     //��ֵ�������
		printf("�������%d��������꣬�ո������\n", i + 1);
		scanf("%lf %lf", &x[i], &y[0][i]);
	}
	double x0;
	printf("������Ҫ�����x��ֵ��");
	scanf("%lf", &x0);

	double sum = y[0][0];                         //��ֵ����
	double x_xi = x0 - x[0];
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < num - i; j++) {
			double a1 = x[j];                     //ʹ�õ��Ʒ�������ֵ
			double a2 = x[i + j];                   //i+j��ȡ���Խ���Ԫ���±�
			y[i][j] = (y[i - 1][j + 1] - y[i - 1][j]) / (a2 - a1);
		}
		sum += y[i][0] * x_xi;
		x_xi *= (x0 - x[i]);
	}
	printf("\n����ţ�ٲ�ֵ���õ��Ľ���ǣ�%lf\n", sum);

	for (int i = 0; i < num; i++)                 //�ͷ��ڴ�
		free(y[i]);
	free(y);
	free(x);

	system("pause");
	return 0;
}
