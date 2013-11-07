/*
Department Checker:
Takes, as input, a list of departments, department worker names and their respective salaries.
As output, writes into a file the average salaries for each department.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
FILE *fp;
FILE *fps;
int main(void)
{
    float deparment_salaries[4]= {0.0 };
	int deparment_employeenumbers[4]= {0 }; 
	float c;
	char a[] = "EPART9";
	char b[] = "NAME7";
	int k,d,ind;
	char *ptr1 = "EPART1";
    char *ptr2 = "EPART2";
    char *ptr3 = "EPART3"; 
	char *ptr4 = "EPART4"; 
	//The Real Department Names used are DEPART1, DEPART 2 etc.! the use of EOF in the while loop removes the first char of the string!
	const char *deparment_names[] = {"EPART1","EPART2","EPART3","EPART4"};
	int ch;
	d=1;
	k=0;
	fp=fopen("emp.txt", "r");
	while( (ch = fgetc(fp)) != EOF)
	{
		fscanf(fp,"%s		%s	%f\n",&a,&b,&c);
		printf("Reading emp.txt!\n");
		if (c>0)
		{
			//The names and the loops are not used in the average salary computation!
			//In any case, these can be replaced with a for or while loop if desired!
			if ((strncmp(a, deparment_names[0], 6))==0)
				ind=0;
			else if ((strncmp(a, deparment_names[1], 6))==0)
				ind=1;
			else if ((strncmp(a, deparment_names[2], 6))==0)
				ind=2;
			else if ((strncmp(a, deparment_names[3], 6))==0)
				ind=3;
			deparment_salaries[ind] += c;
			deparment_employeenumbers[ind] +=1; 
			k=k+1;
		}
		else
			d=0;
	}
	deparment_salaries[0]=deparment_salaries[0]/deparment_employeenumbers[0];
	deparment_salaries[1]=deparment_salaries[1]/deparment_employeenumbers[1];
	deparment_salaries[2]=deparment_salaries[2]/deparment_employeenumbers[2];
	deparment_salaries[3]=deparment_salaries[3]/deparment_employeenumbers[3];
	fps=fopen("average.txt", "w+");
	fprintf(fps,"Department Names		Salaries \n");
	fprintf(fps,"%s			%.2f \n","DEPART1",deparment_salaries[0]);
	fprintf(fps,"%s			%.2f \n","DEPART2",deparment_salaries[1]);
	fprintf(fps,"%s			%.2f \n","DEPART3",deparment_salaries[2]);
	fprintf(fps,"%s			%.2f \n","DEPART4",deparment_salaries[3]);
	fclose(fps);
	printf("Completed writing to average.txt!");
	scanf ("%i",&k); //So that the program doesn't end instantly in Microsoft Visual C++ Express
	return 0;
}
