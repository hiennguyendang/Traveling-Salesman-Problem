#include "bellman.h"
#include "tsm.h"

void test1(){
    int G[20][20];
    int BFValue[20];
    int BFPrev[20];
    int n = 0;
    char source;
    cout << "Enter the number of vertices and source vertex: ";
    cin >> n >> source;
    

    for(int i = 0; i < n; i++) {
        cout << "Enter the adjacency matrix: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> G[i][j];
            BFValue[i] = -1;
            BFPrev[i] = -1;
        }
        BF(G, n, source, BFValue, BFPrev);
        cout << "step" << i + 1 << ":" << endl;
        for(int j = 0;j < n; j++)
            cout << BFValue[j] << " ";
        cout << endl;
        for(int j = 0; j < n; j++)
            cout << BFPrev[j] << " ";
        cout << endl;
    }
}

void test2(){
    int G[20][20];
    int BFValue[20];
    int BFPrev[20];
    int n = 0;
    char source, goal;
    cout << "Enter the number of vertices, source vertex, and goal vertex: ";
    cin >> n >> source >> goal;
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> G[i][j];
        BFValue[i] = -1;
        BFPrev[i] = -1;
    }
    
    cout << BF_Path(G, n, source, goal) << endl;
}

void test3(){
    int graph[20][20];
    int num;
    char start;
    cout << "Enter the number of vertices, source vertex: ";
    cin >> num >> start;
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            cin >> graph[i][j];
    }
    
    TravelingSalesman* test = new TravelingSalesman(graph, num, start);
    cout << "Shortest length: " << test->recursiveCalculate(start - 'A', 1 << (start - 'A')) << endl;
    cout << "Shortest path: " << Traveling(graph, num, start) << endl;

    delete test;
}

int main(int argc, const char * argv[]) {
    int choice;
    cout << "1. Bellman-Ford algorithm" << endl;
    cout << "2. Bellman-Ford algorithm with path" << endl;
    cout << "3. Traveling Salesman Problem" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    return 0;
}

