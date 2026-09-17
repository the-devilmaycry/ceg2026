#include <stdio.h>

void main()
	{       
		char t;
		int arr[25]= {23,22,60,100,90};
		printf("\n\tTHE INITIAL ARRAY \t\n\t[");
		for(int i=0;i<5;i++)
				printf(" %d ",arr[i]);
		printf("]\n\n");
	




printf("\t\tINSERTING ELEMENT AT SPECIFIC POSITION\n\n");

int el,p;
printf("Enter element to insert:");
scanf("%d",&el);

printf("\n\nEnter position to insert (within 5) :");
scanf("%d",&p);

int n=5;

for (int i=n;i>p;i--)
{
	arr[i]= arr[i-1];

}

arr[p]=el;


n++;

printf("\n\tTHE ARRAY AFTER INSERTION AT SPECIFIC POSITION \t\n\t[");
                for(int i=0;i<n;i++)
                                printf(" %d ",arr[i]);
                printf("]\n\n");


printf("\t\tINSERTING ELEMENT AT END\n\n");

printf("Enter element to insert at end:");
scanf("%d",&el);
arr[n]=el;
n++;



printf("\n\tTHE ARRAY AFTER INSERTION AT END \t\n\t[");
                for(int i=0;i<n;i++)
                                printf(" %d ",arr[i]);
                printf("]\n\n");






printf("\t\tINSERTING ELEMENT AT BEGGINNING\n\n");

printf("Enter element to insert at Begginning: ");
scanf("%d",&el);
for (int i=n;i>0;i--)
{
        arr[i]= arr[i-1];

}

arr[0]=el;

n++;


printf("\n\tTHE ARRAY AFTER INSERTION AT BEGGINNING \t\n\t[");
                for(int i=0;i<n;i++)
                                printf(" %d ",arr[i]);
                printf("]\n\n");

scanf("%c",&t);

printf("\t\tDELETING AN ELEMENT FROM SPECIFIC POSITION\n\n");

printf("Enter position to delete the element:");
scanf("%d",&p);

for(int i=p;i<n;i++){
  	arr[i]=arr[i+1];
}

n--;
printf("\n\tTHE ARRAY AFTER DELETION AT SPECIFIC POSITION \t\n\t[");
                for(int i=0;i<n;i++)
                                printf(" %d ",arr[i]);
                printf("]\n\n");
scanf("%c",&t);
scanf("%c",&t);
printf("\t\tDELETING AN ELEMENT FROM BEGGINNING\n\n");

for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
}

n--;

printf("\n\tTHE ARRAY AFTER DELETION AT BEGGINING \t\n\t[");
                for(int i=0;i<n;i++)
                                printf(" %d ",arr[i]);
                printf("]\n\n");

scanf("%c",&t);
scanf("%c",&t);
printf("\t\tDELETING AN ELEMENT AT THE END\n\n");

n--;

printf("\n\tTHE ARRAY AFTER DELETION AT END \t\n\t[");
                for(int i=0;i<n;i++)
                                printf(" %d ",arr[i]);
                printf("]\n\n");

n--;
scanf("%c",&t);
scanf("%c",&t);
printf("\t\tSEARCHING IN ARRAY\n\n");
int sk=-1,s;
printf("Enter element to search:");
scanf("%d",&s);
for(int i=0; i<n ;i++) 
{
if(s==arr[i]) sk=i;

}


if(sk!=-1)
 printf("\n\nSEARCH ELEMENT %d FOUND AT POSITION %d\n\n",s,sk);

else  printf("\t\tSEARCH ELEMENT NOT FOUND!!!\n\n");

scanf("%c",&t);
scanf("%c",&t);
printf("\t\tREVERSING THE ARRAY \n\n\t\t[");
for(int i=n;i>=0;i--){

        printf(" %d ",arr[i]);
}

                printf("]\n\n");




}
