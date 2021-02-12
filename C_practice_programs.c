/*                            1. Factorial of a number using recursion.

#include<stdio.h>
int fact(int n){
   if(n==0)
   return 1;
   else   
   return n*fact(n-1);
}
int main(){
   int n;
   printf("enter a number to find factorial: ");
   scanf("%d",&n);
   printf("%d!= %d\n",n,fact(n));
return 0;
}   */


/*                                     2. Pyramid of stars.

          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *    
  
#include<stdio.h>
int main(){
   int n;
   printf("enter no.of rows: ");
   scanf("%d",&n);
   for(int i=1;i<=n;i++){   
      for(int j=0;j<=2*n-1;j++){
         if(j>=n-i+1 && j<=n+i-1)
          printf("* ");
         else 
         printf("  ");
      }
      printf("\n");
   }
   return 0;
}   */


/*                                  3. Inverted pyramid of stars

  * * * * * * * * * 
    * * * * * * *
      * * * * *
        * * *
          *

#include<stdio.h>
int main(){
   int n;
   printf("enter no.of rows: ");
   scanf("%d",&n);
   for(int i=n;i>0;i--){   
      for(int j=0;j<=2*n-1;j++){
          if(j>=n-i+1 && j<=n+i-1)
         printf("* ");
         else
         printf("  ");
      }
      printf("\n");
   }
   return 0;
}   */

/*                                      4. Pyramid of numbers

          1
        2 3 2
      3 4 5 4 3
    4 5 6 7 6 5 4
  5 6 7 8 9 8 7 6 5

#include<stdio.h>
int main(){
    int num;
    printf("enter no.of rows: ");
    scanf("%d",&num);
    int k=0;
    for(int i=1;i<=num;i++){
        for(int j=0;j<=2*num-1;j++){
            if(j>=num-i+1 && j<=num)
            printf("%d ",++k);
            else if(j>num && j<=num+i-1){
            printf("%d ",--k);
            }
            else
            printf("  ");
        }
        printf("\n");
    }
    return 0;
}   */

/*                                     5. Pyramid of Alphabets

A 
B B
C C C
D D D D

#include<stdio.h>
int main(){
   char n;
   printf("enter the uppercase letter u want in the last row: ");
   scanf("%c",&n);
   int k=(int)n-64;
   for(int i=0;i<k;i++){   
      for(int j=0;j<i+1;j++){
         printf("%c ",65+i);
      }
      printf("\n");
   }
   return 0;
}   */

/*                                            6. Floyd's triangle

1 
2 3
4 5 6
7 8 9 10
11 12 13 14 15

#include<stdio.h>
int main(){
   int n;
   printf("enter no.of rows: ");
   scanf("%d",&n);
   int k=0;
   for(int i=0;i<n;i++){   
      for(int j=1;j<=i+1;j++){
         printf("%d ",++k);
      }
      printf("\n");
   }
   return 0;
}   */

/*                                7. Inverted half pyramid of numbers

1 2 3 4 5 
1 2 3 4
1 2 3
1 2
1

#include<stdio.h>
int main(){
   int n;
   printf("enter no.of rows: ");
   scanf("%d",&n);
   for(int i=n;i>0;i--){   
      for(int j=1;j<i+1;j++){
         printf("%d ",j);
      }
      printf("\n");
   }
   return 0;
}   */


/*                            8. Factorial using "tgamma" function

#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    int fact=tgamma(n+1);
    printf("%d!=%d\n",n,fact);
    return 0;
}  */

/*                               9. Printing elements of 1-D array using recursion

#include<stdio.h>
int out(int arr[],int n,int l){
    if(n==l-1) printf("%d\n",arr[l-1]);
    else{
        printf("%d ",arr[n]);
        out(arr,n+1,l);
    }
}
int main(){
    int n;
    printf("enter a no.of elements in array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("the elements of array are: ");
    out(arr,0,n);
    return 0;
}  */

 /*                                 10. permutations of a given string.

#include<stdio.h>
#include<string.h>
void swap(char *a,char *b){
   int tmp=*b;
   *b=*a;
   *a=tmp;
}
void permute(char* set, int begin, int end) {

   int i,range = end - begin;
   if (range == 1)
      printf("set: %s\n", set);
   else {
      for(i = 0; i < range; i++) {
         swap(&set[begin], &set[begin+i]);
         permute(set, begin+1, end);
         swap(&set[begin], &set[begin+i]);
      }
   }
}
int main(){
   char arr[100];
   printf("enter a string without spaces and repeated letters: ");
   scanf("%s",arr);
   int l=0,u=strlen(arr);
   permute(arr,l,u);
   return 0;
}  */


 /*                                 11. CHECK IF ARMSTRONG NUMBER

#include<stdio.h>
#include<math.h>
int main(){
    int n,count=0,sum=0;
    printf("enter a  number: ");
    scanf("%d",&n);
    int num=n;
    while(n!=0){
        n/=10;
        count++;
    }
    n=num;
    for(int i=0;i<count;i++){
        sum+=pow(n%10,count);
        n/=10;
    }
    if(sum==num)
    printf("given number is an armstrong number.\n");
    else printf("given number is not an armstrong number.\n");
    return 0;
}  */