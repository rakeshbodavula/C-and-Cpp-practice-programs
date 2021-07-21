#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 100
#define N 5
int stack[max],visit[N]={0};
int top=-1;

void push(int data){
    if(top+1==max) printf("Sorry! the stack is full :(\n\n");
    else{
        top++;
        stack[top]=data;
    }
}

int pop(){
    if(top<0){
        printf("Oops! the stack is empty :(\n\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}

int isempty(){
    if(top<0) return 1;
    else return 0;
}

void print_stack(){
    printf("\nThe stack is: \n\n        |     |\n\t-------\n");
    for(int i=top;i>=0;i--){
        printf("\t|  %d  |\n",stack[i]);
        printf("\t-------\n");
    }
    printf("\n");
}

void DFS(int arr[][N],int start){
    push(start);
    while(!isempty()){
        int curr=pop();
        if(visit[curr]==0){
            // print_stack();
            printf("visited vertex--> %d\n",curr);
            visit[curr]=1;
        }
        for(int i=N-1;i>=0;i--){
            if(arr[curr][i] && !visit[i]) push(i);
        }
    }
}

void add_edge(int arr[][N],int source,int dest){
    arr[source][dest]=arr[dest][source]=1;
}

int main(){
    int adjMat[N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            adjMat[i][j]=0;
        }
    }
    add_edge(adjMat,0,1);
    add_edge(adjMat,0,2);
    add_edge(adjMat,0,3);
    add_edge(adjMat,1,2);
    add_edge(adjMat,1,4);
    add_edge(adjMat,2,3);
    add_edge(adjMat,3,1);
    add_edge(adjMat,4,2);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    DFS(adjMat,0);
    for(int i=0;i<N;i++){
        if(visit[i]==0) printf("\nvertex-->%d is not reachable\n",i);
    }
}