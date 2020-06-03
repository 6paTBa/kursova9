#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void printPath(int* distance, int* previous, int startVertex, int queryVertex);

int shortestway(int startVertex, int queryVertex){
    // ifstream graph; //input file stream
    // graph.open("ShortestPathAlgorithm_Input.txt");
    //graph.open(argv[1]);

    // if(!graph.is_open()){   //when file is not found
    //     cout << "File name is wrong!\n";
    //     return 0;
    // }

    // graph >> vertexNumber;
//    int **matrix;
//    matrix = new int* [vertexNumber];
//    for(int i=0; i<vertexNumber; i++)
//        matrix[i] = new int [vertexNumber];
    const int vertexNumber = 5;
    int matrix[vertexNumber][vertexNumber] = {
    { 0, 1, 2, 0, 0 },
    { 1, 0, 0, 1, 0 },
    { 2, 0, 0, 1, 0 },
    { 0, 1, 1, 0, 1 },
    { 0, 0, 0, 1, 0 },
};


    // for(int i=0; i<vertexNumber; i++)   //taking the input
    //     for(int j=0; j<vertexNumber; j++)
    //         if(i == j)
    //             matrix[i][j] = 0;
    //         else
    //             matrix[i][j]= 1 + rand() % 10;


    /*/for(int i=0; i<vertexNumber; i++){  //output of the input file
        for(int j=0; j<vertexNumber; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }/**/


    int *previous = new int [vertexNumber],  //the previous vertex
        *distance = new int [vertexNumber];      //distance of the vertex


    for(int i=0; i<vertexNumber; i++){  //initializing the arrays
        previous[i] = -1;   //initializing with a value that won't come after the program is run
        distance[i] = -10;   //initializing with a value that won't come after the program is run
    }

//    int startVertex;    //taking input from the user as [1-5] & making it as [1-4]
//    cout << "# Enter the starting vertex[1-" << vertexNumber << "]: ";
//	cin >> startVertex;
    startVertex = startVertex-1;

    ///Start of SPA
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

    /*/cout << endl;
    for(int i=0; i<vertexNumber; i++)   //output of the SPA
        cout << distance[i] << "\t" << previous[i]+1 << "\n";
    cout << endl;/**/

//    int queryVertex;
//    cout << "# Enter the query vertex[1-" << vertexNumber << "]: ";
//	cin >> queryVertex;
    queryVertex = queryVertex-1;
    int outputDistance = distance[queryVertex];
//    cout << "\n\nThe distance is: " << distance[queryVertex];

//    cout << "\nThe Path is: \n";
//	printPath(distance, previous, startVertex, queryVertex);


    // for(int i=0; i<vertexNumber; i++)   //delete the matrix
    //     delete[] matrix[i];
    // delete[] matrix;

    delete[] distance;
    delete[] previous;

    // graph.close();  //close the file graph

    return outputDistance;
}


//void printPath(int* distance, int* previous, int startVertex, int queryVertex)
//{
//	if(startVertex==queryVertex)
//		cout << "\t\t" << queryVertex+1 << endl;
//	else if (previous[queryVertex]==-1)
//		cout << "There is no path!\n";
//	else{
//		printPath(distance, previous, startVertex, previous[queryVertex]); //recursion
//		cout << "\t\t" << queryVertex+1 << endl; //printing each vertex
//	}
//}

