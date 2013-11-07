/*
Prime Checker:
Creates a random 10x15 matrix and prints the prime numbers within.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int primesieve( int arraya[][15] , int arrayb[150])
{
  int i,k,n,s,c,num,sroot;
	sroot=0;
	num=0;
	s=0;
	for (i=0;i<10;i++)
	{
		for (k=0;k<15;k++)
			{
				n=arraya[i][k];
				sroot=sqrt(n);
				for (c=2;c<(sroot+1);c++)
				{
					if (((n%c) == 0) && (s==0))
						s=1;
				}
				if (s==0)
				{
					arrayb[num]=n;
					num=num+1;
				}
				s=0;
		}
	}

	return num;
}

int arrayprint(int arrayb[], int n)
{
	int i,k,b;
	for (k=0;k<n;k++)
		{
			b = arrayb[k];
			printf("%i  ",b);
			if ((k% 5)==14)
				printf("\n");
				
	}
	return k;
}

int main(void)
{
	int mais[10][15]= {0};
	int primes[150]= {0};
	int i,k,n,u;

	srand(time(NULL));

	for (i=0;i<15;i++)
	{
		for (k=0;k<10;k++)
			mais[k][i]=rand()%401+100;
	}

	printf("The Random 10x15 Array:\n\n");

	for (i=0;i<10;i++)
	{
		for (k=0;k<15;k++)
			{
				n = mais[i][k];
				printf("%i  ",n);
				
		}
		printf("\n");
	}

	u=primesieve(mais,primes);
	printf("\n\nPrime numbers within the array:\n\n",u);
	arrayprint(primes,u);

	scanf ("%i",&k); //So that the program doesn't end instantly in Microsoft Visual C++ Express
	return 0;
}

