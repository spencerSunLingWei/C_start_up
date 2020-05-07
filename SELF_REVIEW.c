#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>








/*
int a[10]={6,5,9,20,3,8,3,7,1,2};
void quickSort(int values[], int low, int high){
	int left=low;
	int right=high;
	if(left>=right)
		return;
	int pivot=values[(low+high)/2];
	while(left<=right){
		while(values[left]<pivot)
			left++;
		while(values[right]>pivot)
			right--;
		if (left<=right){
			int temp;
			temp=values[right];
			values[right]=values[left];
			values[left]=temp;
			left++;
			right--;
		}
	}
	quickSort(values,low,right);
	quickSort(values,left,high);
	
	
}
int main(){
	int j;
	printf("the original sequence is:");
	for(j=0;j<10;j++)
		printf("%d      ",a[j]);
	quickSort(a,1,9);
	printf("\nThe sorted sequence is:");
	for (int i=0; i<10;i++)
		printf("%d    ",a[i]);
	return 0;
}
*/




/*
int main(){
	int i,j,n=1;
	double sum=1;
	for (i=1;i>0;i++){
		int fac=1;
		for (j=i;j>0;j--)
			fac*=j;
		sum+=1.0/fac;
		n+=1;
		if(sum==sum+1.0/(fac*(i+1)))
			break;
	}

	printf("The value of e is approximately %lf.\n", sum);
	printf("The number of terms it took is %d. \n\n",n);
	
	return 0;
}
*/
	


/*
double bestRally(double price[], int listLength){
	double max = price[1]-price[0];
	for (int i=0, i<listLength-2, i++){
		if (max<price[i+1]-price[i])
			max=price[i+1]-price[i];
	}
	return max;
}
*/


/*
bool checkIfDivisible(int m, int n){
	if(m%n==0)
		return true;
	else
		return false;
}

int main(){
	int m,n;
	printf("enter twoejfskl");
	scanf("%d %d",&m,&n);
	bool a;
	a=checkIfDivisible(m,n);
	printf("%d",a);
	return 0;
}
*/


/*
int someOp(int n){
	if (n==0){
		return 1;
	}
	return someOp(n-1)*n;
}
 int main(){
	 int a,n;
	 printf("Input an intefer number between 1 and 10:");
	 scanf("%d",&n);
	 a=someOp(n);
	 printf("the result is%d",a);
	 return 0;
 }
*/


/*
typedef struct node{
	int data;
	struct node *link;
}Node;

Node *buildJoinedList(Node *firstList, Node *secondList){
	if (secondList==NULL){
		return firstList;
	}
	else{
		Node *cur;
		cur=secondList;
		while(cur->link!=NULL)
			cur=cur->link;
		cur->link=firstList;
		return secondList;
	}
}
*/


/*
char *deletSubString(char *source, char *substring){
	int len=strlen(substring);
	int j;
	for (j=0; j<strlen(source)-len; j++){
		int indexsub=0, indexsource=j;
		while (indexsub<len){
			if (source[indexsource]==substring[indexsub]){
				indexsource++;
				indexsub++;
			}
			else
				break;
		}
		if (indexsub==len){
			for (int i=indexsource-len; i<strlen(source)-len;i++)
				source[i]=source[i+len];
			return source;
		}
	}
}

int main(){
	char *source="my toronto", *substring="to";
	printf("%s",deletSubString(source, substring));
	return 0;
}
*/


/*
int rotateAndFindLongest(int *input){
	int temp[4];
	int max;
	for (int i=0;i<3;i++)
		temp[i+1]=input[i];
	temp[0]=input[3];
	max=temp[0];
	for(int i=1;i<4;i++)
		if (temp[i]>max)
			max=temp[i];
	for(int i=0; i<4; i++)
		input[i]=temp[i];
	return max;
}

int main(){
	int input[4]={13,25,33,79};
	int a=rotateAndFindLongest(input);
	printf("%d\n", a);
	printf("%d%d%d%d",input[0],input[1],input[2],input[3]);
}
*/


/*
int main(void){
	int j,k;
	int *i=&j;
	for(*i=0; *i<10; *i=*i+1){
		printf("%d", (*i)*(*i)*(*i));
		scanf("%d", &k);
		
	}
	return 0;
}
*/


/*
int firstMirrorInE(void){
	const double E=2.718281828459045;
	int digits[16]; 
	double EE=E;
	for(int i=0; i<16; i++ ){
		int digit = (int)EE;
		digits[i]=digit;
		EE=(EE-digit)*10;
	}
	for (int k=1; k<15; k++){
		int digit1=digits[k];
		int digit2 = digits[k+1];
		for (int j=0; j<1; j++)
			if (digits[j]== digit2 && digits[j+1]==digit1)
				return digit1*10+digit2;
	}
	return 0;
}

int main(){
	int a=firstMirrorInE();
	printf("%d",a);
}
*/


/*
void sortOddEven(int input[], int size){
	int i, j=size-1,temp;
	for(i=0; i<j;i++){
		for(j; input[j]%2==0; j--){
			;
		}
		if(input[i]%2==0){
			temp=input[i];
			input[i]=input[j];
			input[j]=temp;
		}
	}
}

int main(){
	int input[]={1,4,6,5,9,3,8,7};
	sortOddEven(input,8);
	printf("%d%d%d%d%d%d%d%d",input[0],input[1],input[2],input[3],input[4],input[5],input[6],input[7]);
}
*/


/*
typedef struct node{
	int data;
	struct node *link;
}Node;

void printDuplicates(Node *head){
	int *cur,*pre, a=1;
	pre=NULL;
	cur=head;
	if(cur==NULL)
		return NULL;
	else{
		pre= head;
		cur=pre->next;
	}
	while(a){
		if (pre->data != cur->data)
			cur=cur->next;
		else if(cur==NULL);
			return NULL;
		else 
			printf("%d\n", pre->data);
		pre=head->next;
		cur=pre->next;
	}
}
*/


/*
char *preamble(char *str, int n){
	char *temp;
	int i;
	temp=(char*)malloc(n+1*sizeof(char));
	if(str==NULL)
		return NULL;
	else{
		for (i=0;i<n;i++)
			temp[i]=str[i];
		if (strlen(str)<=n)
			return temp;
		else
			temp[i]='\0';
			return temp;
	}
}
*/


/*
#define ROWS 10
#define COLUMNS 10
#define LIMIT 4
void celFahrn(float,char);

int main(){
	char unit;
	float value;
	puts("Enter a temperature and its unit.");
	scanf("%f",&value);
	scanf(" %c",&unit);
	celFahrn(value,unit);
	return 0;
}

void celFahrn(float v, char u){
	if(u=='c'|| u=='C'){
		v=9/5*v+32;
		
		printf("%.2f F\n",v);
	}
	else if (u=='f' || u=='F'){
		v=5/9*(v-32);
		printf("%.2f C\n",v);
	}
	else
		printf("\t Invalid input!\n");
}
*/


/*
int main(){
	double max, min, *ptr;
	int size;
	printf("Enter an integer number\n");
	scanf("%d",&size);
	ptr=(double*)malloc(size*sizeof(double));
	for (int i=0;i<size;i++){
		printf("Enter a real number\n");
		scanf("%lf",&ptr[i]);
	}
	max=ptr[0];
	min=ptr[size-1];
	for(int j=0;j<size;j++){
		if(max<ptr[j])
			max=ptr[j];
		if(min>ptr[j])
			min=ptr[j];
	}
	printf("%d numbers are entered with a maximum of %lf and a minimun of %lf.", size, max, min);
}
*/


/*
int main(){
	int i,j=LIMIT;
	double x,y;
	for (i=0; i<LIMIT;i++){
		printf("%d\n",i);
		for(j=LIMIT;j>0;j--){
			if(i==j)
				printf("same");
			else
				printf("%d",j);
		}
		puts("\n");
	}
}
*/


/*
int main()
{
	int counter = 0;
	int i,j;
	for(i=1;i<=ROWS;i++){
		for (j=1;j<=COLUMNS; j++){
			printf("%5d",i*j);
			counter++;
		}
		printf("\n");
	}
}
*/