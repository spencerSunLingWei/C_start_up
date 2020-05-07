#include <stdio.h>
/*two functions*/
void actualSearching(int DNA[],int searchString[]);
void readString(int size, int *searchString);

/*declare the variables*/
int size,*searchString,x,i,a,num,b=1;
int DNA[] = {1, 2, 4, 2, 2, 2, 1, 4, 4, 2, 3, 4, 4, 4, 2, 1, 4, 1, 3, 3, 2, 1, 3, 2, 1, 1, 2, 2, 2, 3, 4, 1, 3, 1, 2, 1, 4, 4, 4, 1, 1, 3, 1, 4, 2, 4, 4, 1, 4, 4, 1, 4, 4, 4, 4, 1, 1, 2, 3, 3, 3, 3, 4, 4, 3, 2, 3, 2, 3, 4, 3, 3, 4, 4, 1, 3, 3, 2, 1, 2, 3, 1, 2, 1, 3, 3, 2, 1, 4, 1, 4, 3, 4, 4, 4, 1, 2, 1, 3, 2, 0};
int lengthDNA=sizeof(DNA)/sizeof(DNA[0]);

main(){
    /*while loop*/
    while(b)
    {
        /*get the input of size*/
        printf("Enter length of DNA string to match:");
        scanf("%d",&size);
        /*invalid size*/
        if (size<1)
        {
            printf("Goodbye\n");
            break;
        }
        /*get the characters according to the size*/
        printf("Enter %d characters (one of 12345) as a search string:",size);
        /*create and initialize an empty array*/
        searchString=(int*)calloc(size,sizeof(int));
        /*call two functions*/
        readString(size, searchString);
        actualSearching(DNA,searchString);
    }
}
    
/*input with two arrays*/
void actualSearching(int *DNA,int *searchString)
{
    /*check from the first character in DNA to (lengthDNA-size) character*/
    for (int x=0; x<(lengthDNA-size); x++)
    {
        int indexString=0, indexDNA=x;
        /*check from the first character to the second last character of the searchString to see if it match with the DNA */
        while (indexString<size-1)
        {
            /*check if the character of searchString is 5*/
            if (searchString[indexString]==5)
            {
                if (DNA[indexDNA]==1||DNA[indexDNA]==2||DNA[indexDNA]==3||DNA[indexDNA]==4)
                {
                    indexString+=1;
                    indexDNA+=1;
                }
            }
            /*to check if the character of searchString is the same with the DNA for the paricular posiiton*/
            else if (searchString[indexString]==DNA[indexDNA])
            {
                indexString+=1;
                indexDNA+=1;
            }
            else
                break;
        }
    /*check the final last character in two conditions*/
    if (indexString==size-1)
        {
            /*check the last one if it is equal to five and if it is equal to the one in DNA*/
            if (searchString[indexString]==5 || searchString[indexString]==DNA[indexDNA])
            {
                if (DNA[indexDNA]==1||DNA[indexDNA]==2||DNA[indexDNA]==3||DNA[indexDNA]==4)
                {
                    printf("Match of search string found at element %d\n", x);
                    indexString=0;
                    indexDNA=0;
                }
            }
        }
    }
    return;
}

/*input is the size and the array of searchString*/
void readString(int size, int *searchString)
{
    /*store and check the characters one by one to the array*/
    for (int i=0; i<size; i++)
    {
        scanf("%1d",&searchString[i]);
        if (searchString[i]<1 || searchString[i]>5)
        {
            printf("Erroneous character input ‘%d' existing\nGoodbye\n", searchString[i]);
            b=0;
            break;
        }
    }
    return;
}