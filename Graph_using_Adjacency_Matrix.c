#include<stdio.h>

#define N 5
void edge(int arr[][N],int source,int dest){
    arr[source][dest]=1;
}

int main(){
    int adjMat[N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            adjMat[i][j]=0;
        }
    }
    edge(adjMat,0,4);
    edge(adjMat,0,2);
    edge(adjMat,0,3);
    edge(adjMat,1,2);
    edge(adjMat,1,4);
    edge(adjMat,2,3);
    edge(adjMat,3,1);
    edge(adjMat,4,2);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
    return 0;
}