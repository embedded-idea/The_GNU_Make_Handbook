#include<stdio.h>
int main(int argc,char**argv)
{

	int a=argc;
	int b=2;
	argv++;

	int c=a+b;
	printf("hello everyone %d\n",c);

	return 0;
}
