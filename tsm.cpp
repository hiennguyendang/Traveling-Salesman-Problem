#include "tsm.h"

string Traveling(const int graph[20][20], int numVertices, char startVertex){
    TravelingSalesman* outString = new TravelingSalesman(graph, numVertices, startVertex);
    string result = outString->TravelingOutString();
    delete outString;
    return result;
};

TravelingSalesman::TravelingSalesman(const int graph[20][20], int numVertices, char startVertex){
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 0) 
                this->graph[i][j] = INF;
            else 
                this->graph[i][j] = graph[i][j];
        }
    }

    this->numVertices = numVertices;
    this->startVertex = startVertex;

    this->valueCity = new int*[20];
    this->nextCity = new int*[20];

    for(int i = 0; i < 20; i++) {
        this->valueCity[i] = new int[1 << 20];
        this->nextCity[i] = new int[1 << 20];
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < 1 << numVertices; j++) {
            this->valueCity[i][j] = INF;
            this->nextCity[i][j] = -1;
        }
    }

    this->valueCity[startVertex - 'A'][1 << (startVertex - 'A')] = 0;
};

int TravelingSalesman::recursiveCalculate(int pos, int mask) {
    if (mask == (1 << this->numVertices) - 1) 
        return graph[pos][this->startVertex - 'A'];

    if (valueCity[pos][mask] != INF && pos != this->startVertex - 'A')
        return this->valueCity[pos][mask];

    int result = INF;
    for (int i = 0; i < this->numVertices; i++) {
        if ((mask & (1 << i)) == 0) {
            int new_result = graph[pos][i] + recursiveCalculate(i, mask | (1 << i));
            if (new_result < result) {
                result = new_result;
                this->nextCity[pos][mask] = i;
            }
        }
    }

    return this->valueCity[pos][mask] = result;
};

string TravelingSalesman::TravelingOutString(){
    int startIndex = startVertex - 'A';

    int min = recursiveCalculate(startIndex, 1 << startIndex);

    int mask = 1 << startIndex;
    int pos = startIndex;

    string path = "";
    for (int v = pos; v != -1; v = this->nextCity[v][mask]) {
        path = path + static_cast<char>('A' + v) + " ";
        mask |= (1 << v);
        if (this->nextCity[v][mask] == -1) break;
    }
    path = path + startVertex;

    return path;
};

TravelingSalesman::~TravelingSalesman(){
    for(int i = 0; i < 20; i++) {
        delete[] this->valueCity[i];
        delete[] this->nextCity[i];
    }
    delete[] this->valueCity;
    delete[] this->nextCity;
};