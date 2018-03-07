#include <stdio.h>

void decomposicaoLU(float A[3][3], float L[3][3], float U[3][3]);
void triangulartSuperior(float U[3][3], float *x, float *y);
void triangularInferior(float L[3][3], float *y, float *b);
int main()
{
	float A[3][3] = {3, 2, 4, 1, 1, 2, 4, 3, -2},
	      x[3], y[3],
	      b[3] = {1, 2, 3},
	      L[3][3], U[3][3];
	int i;

	decomposicaoLU(A, L, U);
	triangularInferior(L, y, b);
	triangulartSuperior(U, x, y);

	printf("\nResultado do sistema: ");
	for (i = 0; i < 3; i++)
	{
		printf("%.2f ",x[i]);
	}
}


void decomposicaoLU(float A[3][3], float L[3][3], float U[3][3])
{
	int i, j, p, k;;
	float somatorio;
    L[0][1] = L[0][2] = L[1][2] = U[1][0] = U[2][0] = U[2][1] = 0;
	for (p = 0; p < 3; p++)
	{
		L[p][p] = 1;
		for (j = p; j < 3; j++)
		{
				somatorio = 0;
				for (k = 0; k < p; k++)
				{
					somatorio += L[p][k] * U[k][j];
				}
				U[p][j] = A[p][j] - somatorio;

			}
			for(i=p+1;i<3;i++)
			{
				somatorio = 0;
				for(k = 0; k < p; k++)
				{
					somatorio += L[i][k] * U[k][p];
				}
				L[i][p] = (1.0/U[p][p]) * (A[i][p] - somatorio);
			}

	}
}

void triangularInferior(float L[3][3], float *y, float *b)
{
	int i, j;
	float somatorio;
	for (i = 0; i < 3; i++)
	{
		somatorio = 0.0;
		for (j = 0; j < i; j++)
		{
			somatorio +=(L[i][j] * y[j]);
		}
		y[i] = (b[i] - somatorio)/L[i][i];
	}
}

void triangulartSuperior(float U[3][3], float *x, float *y)
{
	int i, j;
	float somatorio;

	for (i = 3-1; i >= 0; i--)
	{
		somatorio = 0.0;
		for (j = i+1; j < 3; j++)
		{
			somatorio +=(U[i][j] * x[j]);
		}
		x[i] = (y[i] - somatorio)/U[i][i];
	}
}
