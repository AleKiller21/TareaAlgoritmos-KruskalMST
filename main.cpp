#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

int** init(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

bool checkCycle(int** graph, int destination, int source, int cycleTarget, int size)
{
    int currentVertex = destination;
    if(currentVertex == cycleTarget) return true;
    
    for(int i = 0; i < size; i++)
    {
        if(i == source || graph[currentVertex][i] == -1) continue;
        bool flag = checkCycle(graph, i, currentVertex, cycleTarget, size);
        if(flag) return flag;
    }

    return false;
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    int** mst = init(size);
    Edge* currentEdge = edges[0];
    mst[currentEdge->source][currentEdge->destination] = currentEdge->weight;
    mst[currentEdge->destination][currentEdge->source] = currentEdge->weight;
    for(int i = 1; i < edges.size(); i++)
    {
       currentEdge = edges[i];
       if(!checkCycle(mst, currentEdge->destination, currentEdge->source, currentEdge->source, size))
       {
           mst[currentEdge->source][currentEdge->destination] = currentEdge->weight;
           mst[currentEdge->destination][currentEdge->source] = currentEdge->weight;
       }
    }

    return mst;
}

int main ()
{
    test();
    return 0;
}
