#include "bellman.h"

void BF(const int graph[20][20], int numVertices, char startVerticle, int* BFValue, int* BFPrev){
    int INF = 999999999;
    int BFValue_current[20] = {INF};
    int startIndex = startVerticle - 'A';
    
    if (BFValue[startIndex] == -1)
        BFValue[startIndex] = 0;

    for(int i = 0; i < numVertices; i++)
        if (BFValue[i] == -1)
            BFValue[i] = INF;

    for (int i = 0; i < numVertices; i++)
        BFValue_current[i] = BFValue[i];

    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++){
            if (graph[u][v] != 0  && BFValue_current[u] != INF) {
                if (graph[u][v] + BFValue_current[u] < BFValue[v]){
                    BFValue[v] = graph[u][v] + BFValue_current[u];
                    BFPrev[v] = u;
                }
            }
        }
    }
    
    for(int i = 0; i < numVertices; i++)
        if (BFValue[i] == INF)
            BFValue[i] = -1;
};



string BF_Path(const int graph[20][20], int numVertices, char startVertex, char goalVertex) {
    int BFValue[20];
    int BFPrev[20];

    for(int i = 0; i < numVertices; i++) {
        BFValue[i] = -1;
        BFPrev[i] = -1;
    }

    for (int i = 0; i < numVertices; ++i)
        BF(graph, numVertices, startVertex, BFValue, BFPrev);
    
    int goalIndex = goalVertex - 'A';
    int startIndex = startVertex - 'A';

    string path = "";
    for (int v = goalIndex; v != -1; v = BFPrev[v]) {
        if (!path.empty()) path = " " + path;
        path = static_cast<char>('A' + v) + path;
    }

    return path;
};