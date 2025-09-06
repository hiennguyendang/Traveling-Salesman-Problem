#ifndef BELLMAN_H
#define BELLMAN_H

#include <iostream>
#include <cstring>


using namespace std;

void BF(const int graph[20][20], int numVertices, char startVerticle, int* BFValue, int* BFPrev);

string BF_Path(const int graph[20][20], int numVertices, char startVertex, char goalVertex);

#endif  // BELLMAN_H