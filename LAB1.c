#include <stdio.h>
main(){
	int encr, real, real1, real2, real3;
	printf("Enter an encrypted 3-digit code:");
	scanf("%d",&encr);
	real3 = encr/100;
	real2 = 9-(encr-real3*100)/10;
	real1 = encr-real3*100-(9-real2)*10;
	real = real1*100+real2*10+real3;
	if (real<100 && real>9)
		printf("The real 3-digit code is:0%d\n",real);
	else if (real<10)
		printf("The real 3-digit code is:00%d\n",real);
	else
		printf("The real 3-digit code is:%d\n",real);
	

}