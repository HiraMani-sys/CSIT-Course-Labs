/*objective 
theory 
algo
code/ procedure
result
conclusion*/
#include<stdio.h>
#include<math.h>
double f(double x)
{
	return 3*x*x*x+x*x-3*x-3;
}
int main()
{
	double a,b,c;
	int iteration=0;
	a=1;
	b=2;
	if(f(a)*f(b)>=0){
	printf("Invalid numbers. Needs one postive and one negative functions.");
	return 1;
	}
	printf("Bisection method for f(x)=3x^3+x^2-3*x-3")
	printf(" Initial interval: (%.3f,%.3f)",a,b);
	
	while(b-a>=0.001)
	{
		iteration++;
		c=(a+b)/2;
		
		printf("iteration %d: a=%.3f, b=%.3f, c=%.3f, f(c)=%.3f",iteration,a,b,c,f(c));
		
		if(fabs(f(c)<0.001)
		{
			break;
		}	
	if(f(a)*f(c)<0))
		{
			b=c;
		}
	else
		{
			a=c;
		}
	}
	printf("approximate root after %d iteration=%.3f",iteration, c;
	return 0;
}


