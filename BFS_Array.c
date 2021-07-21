#include<stdio.h>
#include<stdlib.h>

#define max 100
#define N 5
int queue[max],visit[max]={0};
int front=0,rear=-1;

int isfull(){
    if(rear==max-1) return 1;
    else return 0;
}


int isempty(){
    if(front<0 || front>rear) return 1;
    else return 0;
}

void enqueue(int data){
    if(isfull()) printf("Sorry! The queue is full can't add :(\n\n");
    else{
        rear++;
        queue[rear]=data;
    }
}

int dequeue(){
    if(isempty()){
        printf("Ooops! The queue is empty can't delete :(\n\n");
        return -1;
    }
    else{
        return queue[front++];
    }
}

void peek(){
    printf("The front element is: %d\n\n",queue[front]);
}

void print_queue(){
    printf("\nThe queue is: \n\nfront-->|  %d  |\n\t-------\n",queue[front]);
    for(int i=front+1;i<=rear;i++){
        if(i==rear) printf("rear-->");
        printf("\t|  %d  |\n",queue[i]);
        if(i<rear) printf("\t-------\n");
    }
    printf("\n");
}

void add_edge(int arr[][N],int source,int dest){
    arr[source][dest]=arr[dest][source]=1;
}

void BFS(int arr[][N],int start){
    visit[start]=1;
    enqueue(start);
    while(!isempty()){
        int curr=dequeue();
        printf("Visted %d\n",curr);
        for(int i=0;i<N;i++){
            if(arr[curr][i]){
                if(visit[i]==0) enqueue(i);
                visit[i]=1;
            }
        }
    }
}

int main(){
    int adjMat[N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            adjMat[i][j]=0;
        }
    }
    // add_edge(adjMat,0,4);
    add_edge(adjMat,0,3);
    add_edge(adjMat,1,2);
    // add_edge(adjMat,1,4);
    add_edge(adjMat,3,1);
    // add_edge(adjMat,4,2);
    printf("The adjacency matrix is \n");
    for(i=0;i<N;i++){
        printf("\t");
        for(j=0;j<N;j++){
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    BFS(adjMat,0);
    for(int i=0;i<N;i++){
        if(visit[i]==0) printf("%d is not reachable\n",i);
    }
}