#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    public:
        Graph();
        ~Graph();
        void addNode(int start, int end, int weight);
        void printAdjacencyMatrix();
        int* printOddDegrees();
        void printShortestLengthFromOdds(int* values);
        void setSize(int numberNodes, int numberEdges);
        void dijkstra(int source);
        int getSize(int* source);
    private:
        int** matrix;
        int numNodes;
        int numEdges;

};

#endif