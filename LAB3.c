#include <stdio.h>
#define MIDDLE 3

void triangle(int rowNumber);
int choose(int n, int r);
int factorial(int n);

int main(){
	int rowNumber;
	while (1){
	printf("Enter the number of rows: ");
	scanf("%d", &rowNumber);

	if (rowNumber<0 || rowNumber>13)
		return 0;
	else if (rowNumber==0)
		printf("");
	else
		triangle(rowNumber);
	}
	return 0;
}

void triangle(int rowNumber){
	int leftSpace, count=1, rowCount=0,a;
	
	for(leftSpace=2*(rowNumber-1); leftSpace>=0; leftSpace-=2){
		/*left*/
		while(count<=leftSpace){
			printf(" ");
			count++;
		}
		count=1;
	
		/*middle*/
		a=rowCount;

			for(int i=a; i>0;i--){
				printf("%d", choose(a,i));
				if (choose(a,i)>9 && choose(a,i)<=99)
					printf("  ");
				else if (choose(a,i)>99)
					printf(" ");
				else
					printf("   ");
			}

		printf("%d", choose(rowCount,0));

		/*right*/
		while(count<=leftSpace){
			printf(" ");
			count++;
		}
		count=1;
		rowCount++;
		printf("\n");
	}
	return;
}
	








int choose(int n, int r){
	int result;
	result=factorial(n)/(factorial(r)*factorial(n-r));
	return result;
}

int factorial(int n){
	int result=1,i;
	if (n>=1)
		for(i=n; i>=1; i--)
			result=result*i;
	else if (n==0)
		result = 1;
	else
		printf("Wrong input");
	return result;		
}