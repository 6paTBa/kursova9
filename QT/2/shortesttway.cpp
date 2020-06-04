#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int** createMatrix(int vertexNumber)
{
    int **matrix;

    matrix = new int* [vertexNumber];
    for(int i = 0; i < vertexNumber; i++)
        matrix[i] = new int [vertexNumber];

    for(int i = 0; i < vertexNumber; i++)   //taking the input
        for(int j = 0; j < vertexNumber; j++)
            if(i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = -1;
    int temp;
    for(int i = 0; i < vertexNumber; i++)   //taking the input
        for(int j = 0; j < vertexNumber; j++)
            if(i != j && (matrix[i][j] == -1 || matrix[j][i] == -1)) {
                temp = rand() % 9;
                matrix[i][j] = temp;
                matrix[j][i] = temp;
            }

    return matrix;
}


int shortestway(int **matrix, int vertexNumber, int startVertex, int queryVertex)
{
    int *previous = new int [vertexNumber],  //the previous vertex
        *distance = new int [vertexNumber];      //distance of the vertex


    for(int i=0; i<vertexNumber; i++){  //initializing the arrays
        previous[i] = -1;   //initializing with a value that won't come after the program is run
        distance[i] = -10;   //initializing with a value that won't come after the program is run
    }

    startVertex = startVertex-1;

    queue<int> SPAQueue;
    SPAQueue.push(startVertex);

    distance[startVertex]=0;    //distance is zero
    previous[startVertex]=-2;  //there is no previous

    while(!SPAQueue.empty()){   //finding adjacent vertexes and colouring them
        int i=SPAQueue.front();
        SPAQueue.pop();

        for(int j=0; j<vertexNumber; j++)
            if(matrix[i][j]!=0 && (distance[j]<0 || distance[j]>distance[i]+matrix[i][j])){
                    distance[j]=distance[i]+matrix[i][j];
                    previous[j] =i;
                    SPAQueue.push(j);
                }
    }

    queryVertex = queryVertex-1;
    int outputDistance = distance[queryVertex];

    //    for(int i=0; i<vertexNumber; i++)   //delete the matrix
    //        delete[] matrix[i];
    //    delete[] matrix;

    delete[] distance;
    delete[] previous;

    return outputDistance;
}
