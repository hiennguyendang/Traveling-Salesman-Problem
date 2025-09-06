#ifndef TRAVELINGSALEMAN_H  
#define TRAVELINGSALEMAN_H

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int pathlength(int graph[20][20], int num_vertices, std::string path) ;
string Traveling(const int graph[20][20], int numVertices, char startVertex);

class TravelingSalesman {
private:
    int graph[20][20];
    int numVertices;
    char startVertex;
    int** valueCity;
    int** nextCity;
public:
    static const int INF = 999999999;
    TravelingSalesman(const int graph[20][20], int numVertices, char startVertex);
    int recursiveCalculate(int pos, int mask);
    string TravelingOutString();
    ~TravelingSalesman();
};

#endif  // TRAVELINGSALEMAN_H


