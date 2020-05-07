#include <stdio.h>

int main(){
	int totalCents, decision=1, qua, dim, nic, cen;
	
	while (decision){
		printf("Please give an amount in cents less than 100: ");
		scanf("%d", &totalCents);
	
		if (totalCents<=0 || totalCents >=100){
			printf("GoodBye.\n");
			decision=0;
		}
		else{
			qua=totalCents/25;
			dim=(totalCents-qua*25)/10;
			nic=(totalCents-qua*25-dim*10)/5;
			cen=totalCents-qua*25-dim*10-nic*5;
		
		
			if (totalCents==1)
				printf("%d cent:", totalCents);
			else
				printf("%d cents:", totalCents);
		
			if (qua==1)
				if (dim==0 && nic==0 && cen==0)
					printf(" %d quarter.", qua);
				else
					printf(" %d quarter,", qua);
			else if (qua==0)
				printf("");
			else
				if (dim==0 && nic==0 && cen==0)
					printf(" %d quarters.", qua);
				else
					printf(" %d quarters,", qua);
		
			if (dim==1)
				if (nic==0 && cen==0)
					printf(" %d dime.", dim);
				else
					printf(" %d dime,", dim);
			else if (dim==0)
				printf("");
			else
				if (nic==0 && cen==0)
					printf(" %d dimes.", dim);
				else
					printf(" %d dimes,", dim);
			
			if (nic==1)
				if (cen==0)
					printf(" %d nickel.", nic);
				else
					printf(" %d nickel,", nic);
			else if (nic==0)
				printf("");
			else
				if (cen==0)
					printf(" %d nickels.", nic);
				else
					printf(" %d nickels,", nic);
			
			
			if (cen==1)
				printf(" %d cent.\n", cen);
			else if (cen==0)
				printf("\n");
			else
				printf(" %d cents.\n", cen);
		}
	}	
	
	return 0;
}
