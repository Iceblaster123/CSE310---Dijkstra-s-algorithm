#include <iostream>
#include "Graph.h"

Graph::Graph(){
    matrix = NULL;
    numNodes = 0;
    numEdges = 0;
};

Graph::~Graph(){
    for(int i = 0; i <= numNodes; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

}

void Graph::setSize(int numOfVertices, int numOfEdges){
    std::cout << "setSize called: " << numOfVertices << " " << numOfEdges << std::endl;
    numNodes = numOfVertices;
    numEdges = numOfEdges;
    matrix = new int*[numNodes+1];
    std::cout << "matrix allocated" << std::endl;
    for(int i = 0; i <= numNodes; i++){
        matrix[i] = new int[numNodes+1];
        for(int j = 0; j <= numNodes; j++){
            matrix[i][j] = 0;
        }
    }
    std::cout << "matrix initialized" << std::endl;
}

void Graph::addNode(int start, int end, int weight){
    matrix[start][end] = weight;
    matrix[end][start] = weight;
};

void Graph::printAdjacencyMatrix(){
    std::cout << "The adjacency matrix of G is:" << std::endl;
    for(int i = 1; i <= numNodes; i++){
        for(int j = 1; j <= numNodes; j++){
            std::cout << matrix[i][j];
            if(j < numNodes) std::cout << " ";
        }
        std::cout << std::endl;
    }
};

int* Graph::printOddDegrees(){
    int* oddNodes = new int[numNodes];
    int bucket = 0;
    std::cout << "The nodes with odd degrees in G are:\n";
    std::cout << "O = { ";

    for(int i = 1; i <= numNodes; i++){
        int degree = 0;

        for(int j = 1; j <= numNodes; j++){
            if(matrix[i][j] != 0){
                degree++;
            }
        }

        if(degree % 2 != 0){
            oddNodes[bucket] = i;
            std::cout << i << " ";
            bucket++;
        }
    }
    std::cout << "}\n";
    return oddNodes;
};

void Graph::dijkstra(int source){
    int* dist = new int[numNodes+1];
    bool* visited = new bool[numNodes+1];

    for(int i = 1; i <= numNodes; i++){
        dist[i] = 9999999999;
        visited[i] = false;
    }
    dist[source] = 0;

    for(int count = 0; count < numNodes; count++){
        // pick unvisited node with smallest distance
        int u = -1;
        for(int i = 1; i <= numNodes; i++){
            if(!visited[i] && (u == -1 || dist[i] < dist[u])){
                u = i;
            }
        }

        visited[u] = true;

        // relax all neighbors
        for(int v = 1; v <= numNodes; v++){
            if(matrix[u][v] != 0 && !visited[v]){
                if(dist[u] + matrix[u][v] < dist[v]){
                    dist[v] = dist[u] + matrix[u][v];
                }
            }
        }
    }

    std::cout << "The shortest path lengths from Node " << source
              << " to all other nodes are:" << std::endl;
    for(int i = 1; i <= numNodes; i++){
        std::cout << i << ": " << dist[i] << std::endl;
    }

    delete[] dist;
    delete[] visited;
}

void Graph::printShortestLengthFromOdds(int* oddValues){
    for(int i = 0; i < getSize(oddValues); i++){
        dijkstra(oddValues[i]);
    }
};

int Graph::getSize(int* source){
    int i = 0;
    while(source[i] != 0){
        i++;
    }
    return i;
};