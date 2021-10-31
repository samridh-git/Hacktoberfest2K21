#include<stdio.h>
#include<string.h>
void main()
{
    int d,c,i, length, count = 0,n;
    int  s1[100], s2[100];
    printf("length of s1 and s2 \n");
    scanf("%d",&n);
    printf("Enter s1 : ");
    for(i=0;i<n;i++)
    {
    scanf("%d", &s1[i]);
    }
    printf("Enter s2 : ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &s2[i]);
    }
    for(i=0;i<n;i++)
    {
     if(s1[i]!=s2[i])
     {
         count=count+1;
     }
    }

    printf("\nHamming Distance : %d\n", count);
    if(count==0)
    {
     printf("no error ");
    }
    else
    {

    d=count-1;
	c=(count-1)/2;
     printf("error bits that can be detected = %d\n",d);
     printf("error bits that can be corrected= %d",c);
    }

    getch();
}
