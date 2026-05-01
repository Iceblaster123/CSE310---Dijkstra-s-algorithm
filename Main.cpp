#include <iostream>
#include "Edge.h"
#include "Graph.h"


int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin
    std::cout << "we can start\n";
    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return NULL;
    }

    Graph dijkstra;
    dijkstra.setSize(numOfVertices, numOfEdges);

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);
        dijkstra.addNode(startVertice, endVertice, weight);
    }

    dijkstra.printAdjacencyMatrix();
    int* oddValues = dijkstra.printOddDegrees();
    dijkstra.printShortestLengthFromOdds(oddValues);
    return 0;
}