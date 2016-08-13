/*
    structures to create a graph (undirected) with adjacency list
*/
#include<iostream>
using namespace std;

//node in a graph
struct GraphNode{
    int data;
    GraphNode* next;
};

struct AdjList{
    GraphNode* head;
};

struct Graph{
    int V;
    AdjList* gArray;
};

//create a new graph
Graph* createGraph(int V){
    Graph* graph=new Graph;
    graph->V=V;
    graph->gArray=new AdjList[V];
    //initialize to NULL
    for(int i=0;i<V;i++){
        graph->gArray[i].head=NULL;
    }
    return graph;
}

//create a new node
GraphNode* createNode(int item){
    GraphNode* nptr=new GraphNode;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

//add edge between two nodes
void addEdge(Graph* graph,int src,int dest){
    GraphNode* nptr=createNode(src);
    //set src node
    nptr->next=graph->gArray[dest].head;
    graph->gArray[dest].head=nptr;
    //set dest node
    nptr=createNode(dest);
    nptr->next=graph->gArray[src].head;
    graph->gArray[src].head=nptr;
}

/*
//test function
int main(){
    Graph *graph=createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,0);

    //priint graph adjacency list
    for(int i=0;i<graph->V;i++){
        cout<<"\nAdjacency List : "<<i<<" : "<<endl;
        GraphNode *root=graph->gArray[i].head;
        while(root!=NULL){
            cout<<root->data<<" - ";
            root=root->next;
        }
        cout<<endl;
    }
}
*/
