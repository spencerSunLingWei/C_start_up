#include <stdio.h>

int main(){
	int row, count=1, leftBlank, middleBlank;
	printf("Enter the number of rows in the triangle:");
	scanf("%d", &row);
	leftBlank=row-2;
	middleBlank=(row*2-1)-2-(leftBlank)*2;
	
	
	/* the first row*/
	while(count<=row-1){
		printf(" ");
		count++;
	}
	printf("*");
	count++;
	while (count<=(2*row-1)){
		printf(" ");
		count++;
	}
	printf("\n");
	count=1;
	
	
	
	
	
	
	/*body*/
	for(int i=2; i<row; i++){
		while(count<=leftBlank){
			printf(" ");
			count++;
		}
		printf("*");
		count++;
		while(count<=(leftBlank+1+middleBlank)){
			printf(" ");
			count++;
		}
		printf("*");
		count++;
		while(count<=(2*row-1)){
			printf(" ");
			count++;
		}
		printf("\n");
		leftBlank-=1;
		count=1;
		middleBlank=(row*2-1)-2-(leftBlank)*2;
		
	}
	
	

	
	
	
	
	
	/* the last row*/
	while(count<=2*row-1){
		printf("*");
		count++;
	}
	printf("\n");	
	
	
	return 0;
}
