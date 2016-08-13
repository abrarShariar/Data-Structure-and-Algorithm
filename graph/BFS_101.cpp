/*
    Breadth First Search complete (adjacency list)

*/

#include<iostream>
#include "Queue.h"
#include "Graph.h"
using namespace std;

void BFS(Graph*,int);

int main(){

    Graph *graph=createGraph(5);
  /*
    WORKS !!
   addEdge(graph,0,1);
   addEdge(graph,1,2);
   addEdge(graph,2,3);
   addEdge(graph,1,3);
   addEdge(graph,3,4);
    */

    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,0);

    //show adjacency list
    for(int i=0;i<graph->V;i++){
        cout<<"Adjacency List of "<<i<<endl;
        GraphNode* root=graph->gArray[i].head;
        while(root!=NULL){
            cout<<root->data<<endl;
            root=root->next;
        }
        cout<<endl;
    }
    cout<<"\nBreadth First Search: "<<endl;
    BFS(graph,0);
}


void BFS(Graph* graph,int root){
    //mark all nodes as VISITED=FALSE
    bool visited[graph->V]={false};
    //queue for bfs
    Queue<int>que(graph->V);

    //mark current node as visisted=TRUE
    visited[root]=true;
    que.enQueue(root);

    //loop over all adjacent nodes in bfs way
    while(!que.isEmpty()){
        int vertex=que.deQueue();
        cout<<vertex<<endl;

        GraphNode* head=graph->gArray[vertex].head;
        while(head!=NULL){
            if(!visited[head->data]){
                visited[head->data]=true;
                que.enQueue(head->data);
            }
            head=head->next;
        }
    }
}
