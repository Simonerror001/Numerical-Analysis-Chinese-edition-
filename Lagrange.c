/*
�������ղ�ֵ
Created on Mar 5, 2018
@author: Wang Yufei
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	printf("�������ֵ��ĸ�����");
	scanf_s("%d", &num);
	double *x, *y;
	x = (double *)malloc(sizeof(double) * num);
	y = (double *)malloc(sizeof(double) * num);
	for (int i = 0; i < num; i++) {
		printf("�������%d��������꣬�ո������\n", i + 1);
		scanf_s("%lf %lf", &x[i], &y[i]);         //��ֵ�������
	}
	
	double x0;
	printf("������Ҫ�����x��ֵ��");
	scanf_s("%lf", &x0);

	double sum = 0;                             //��ֵ����
	for (int i = 0; i < num; i++) {
		double temp = 1.0;
		for (int j = 0; j < num; j++) {
			if (j == i)
				continue;
			temp *= (x0 - x[j]) / (x[i] - x[j]);
		}
		sum += y[i] * temp;
	}

	printf("\n�����������ղ�ֵ����ʽ�õ��Ľ���ǣ�%lf\n", sum);
	free(x);
	free(y);


	return 0;
}
