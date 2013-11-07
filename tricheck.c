/*
Triangle Checker:
Takes three coordinates as float values, then checks if they form a triangle and if they do, calculates the area and the coordinates of the center of gravity of the triangle formed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float x1,x2,x3,y1,y2,y3,s,area,cogx,cogy;
	float a,b,c;
	printf("Welcome to the Triangle Checker! \n\nNow write your coordinates with a space in between; that is, in the form \n \n3.14 4.18 \n\nWhere 3.14 is thepico  x position and 4.18 is the y position.\n \nEnter the coordinates of the first point:\n"); //Begin to take the coordinates
	scanf("%f %f",&x1,&y1);
	printf("\nNow enter the coordinates of the second point:\n");
	scanf("%f %f",&x2,&y2);
	printf("\nNow enter the coordinates of the third point:\n");
	scanf("%f %f",&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); //Simple Pythagorean Theorem
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	s=(a+b+c)/2; //For Heron's
	area=sqrt(s*(s-a)*(s-b)*(s-c)); //We use Heron's Formula To Calculate the Triangle's Area!
	//Since we are given three points instead of side lengths, there is no need to check the triangle inequality! Just check if the points are colinear or if two of them are the same!
	if ((((y3 - y2) / (x3 - x2)) == ((y2 - y1) / (x2 - x1))) || (a == 0) || (b == 0) || (c == 0) || (area == 0)) //Check for all kinds of possible failures
	{
		printf("\nThese points don't form a triangle!");
		scanf ("%f",&s); //So that the program doesn't end instantly in Microsoft Visual C++ Express
		return 0;
	}
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	cogx=(x1+x2+x3)/3;
	cogy=(y1+y2+y3)/3;
	printf("\nArea of the Triangle: %.2f",area); //Print Results
	printf("\n\nCenter of Gravity X Coordinate: %.2f",cogx);
	printf("\nCenter of Gravity Y Coordinate: %.2f",cogy);
	scanf ("%f",&s); //So that the program doesn't end instantly in Microsoft Visual C++ Express
	return 0;
}
