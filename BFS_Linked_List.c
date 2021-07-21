#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr[100],count=0;

struct node{
    int data;
    struct node* next;
};

struct graph{
    int vertices;
    struct node**adjlist;
    int *visited;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(rear==NULL){
        front =rear=new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }
    printf("The element %d is inserted into the queue :)\n",data);
}

int dequeue(){
        struct node *ptr=front;
        int data=front->data;
    if(front==NULL && rear==NULL) printf("Oops! The queue is empty :(\n");
    else if(front==rear){
        front=rear=NULL;
        printf("The element %d is deleted :)\n",ptr->data);
        free(ptr);
    }
    else{
        printf("The element %d is deleted :)\n",front->data);
        front=front->next;
        free(ptr);
    }
    return data;
}

void print_queue(){
    struct node* ptr=front;
    if(front==rear && rear==NULL) printf("The queue is empty :(\n");
    else{
        printf("queue is:\n");
        while(ptr){
            printf("\t%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

struct node* create_node(int vertex){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=vertex;
    newnode->next=NULL;
    return newnode;
}

struct graph* create_graph(int vert_count){
    struct graph* new_graph=malloc(sizeof(struct graph));
    new_graph->vertices=vert_count;
    new_graph->adjlist=malloc(vert_count*sizeof(struct node*));
    for(int i=0;i<vert_count;i++){
        new_graph->adjlist[i]=NULL;
    }
    return new_graph;
}

void add_edge(struct graph* graph,int source,int dest){
    struct node*newnode=create_node(dest);
    newnode->next=graph->adjlist[source];
    graph->adjlist[source]=newnode;

    newnode=create_node(source);
    newnode->next=graph->adjlist[dest];
    graph->adjlist[dest]=newnode;

}

void print_graph(struct graph* graph){
    for(int i=0;i<graph->vertices;i++){
        printf("vertex: %d ",i);
        struct node*temp=graph->adjlist[i];
        while(temp){
            printf("%d",temp->data);
            if(temp->next) printf(" ==> ");
            temp=temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

void BFS(struct graph*graph,int start){
    graph->visited[start]=1;
    enqueue(start);
    while(front && rear){
        struct node* temp=graph->adjlist[front->data];
        while(temp){
            if(graph->visited[temp->data]) enqueue(temp->data);
            temp=temp->next;
        }
        int present_vert=dequeue();
        printf("visited %d ",present_vert);
        graph->visited[present_vert]=1;
    }
}

int main(){
    srand(time(0));
    int n=5,edges;
    // printf("Enter no.of vertices and edges: ");
    // scanf("%d %d",&n,&edges);
    struct graph* graph=create_graph(n);
    add_edge(graph,0,1);
    add_edge(graph,0,2);
    add_edge(graph,1,2);
    add_edge(graph,1,3);
    add_edge(graph,2,4);
    add_edge(graph,2,3);
    add_edge(graph,3,4);
    print_graph(graph);
    BFS(graph,1);
    printf("The traversed order is: ");
    for(int i=0;i<count;i++) printf("%d ",arr[i]);  
}