#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int numv;
    list<int>* adjLists;
    bool*visited;
    public:
    Graph(int vertices)
    {
        numv=vertices;
        adjLists=new list<int>[vertices];
    }
    void addEdge(int s,int d)
    {
        adjLists[s].push_back(d);
        adjLists[d].push_back(s);
    }
    void BFS(int sv)
    {
        visited= new bool[numv];
        for(int i=0;i<numv;i++)
        {
            visited[i]=false;
            list<int> queue;
            visited[sv]=true;
        }
    }
}
