/*
---------------------------------------------------------------
IMPORANT NOTE: All of 'main' function is used for testing all methods
               to prove they execute accurately.
---------------------------------------------------------------
*/


#include "stdafx.h"
#include "graphProject.h"
using namespace std;


int main()
{
	AdjacencyMatrixGraph <int> matrixGraph;
	AdjacencyListGraph <int> listGraph;
	AdjacencyListGraph <int> *graph;
	vector <int> vect;
	vector <int>::iterator it;
	int startNode = 5;

// The two graphs directly below are used for 'unit-testing' and
// to show that the methods execute accurately.
	listGraph.generateNewGraph(15, 0.5);
	matrixGraph.generateNewGraph(30, 0.5);

	matrixGraph.generateNewGraph(2, EDGE_PROBABILITY);
	matrixGraph.generateNewGraph(8, EDGE_PROBABILITY);
	matrixGraph.generateNewGraph(64, EDGE_PROBABILITY);
	matrixGraph.generateNewGraph(256, EDGE_PROBABILITY);
	matrixGraph.generateNewGraph(1028, EDGE_PROBABILITY);

	cout << "Starting depth-first-search on Adjacency List...\n";
	cout << "--------------------------------------------------\n";
	//listGraph.dfs(listGraph, startNode);
	cout << "\n\n\n\n";
	startNode = 20;
	cout << "Starting depth-first-search on Adjacency Matrix...\n";
	cout << "--------------------------------------------------\n";
	//matrixGraph.dfs(matrixGraph, startNode);


	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 4: ";
	vect = listGraph.neighbors(4);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}



	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 5: ";
	vect = listGraph.neighbors(5);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}




	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 9: ";
	vect = listGraph.neighbors(9);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}




	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 12: ";
	vect = listGraph.neighbors(12);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}
	


	listGraph.deleteEdge(12,10);
	listGraph.deleteEdge(12, 11);
	listGraph.deleteEdge(12, 12);
	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 12 after deleting edges: ";
	vect = listGraph.neighbors(12);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}




	listGraph.deleteEdge(9, 5);
	listGraph.deleteEdge(9, 6);
	listGraph.deleteEdge(9, 8);
	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 9 after deleting edges: ";
	vect = listGraph.neighbors(9);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}




	listGraph.addEdge(9, 2);
	cout << "\n\n\n";
	cout << "Displaying neighbors of Vertex 9 after adding edge: ";
	vect = listGraph.neighbors(9);
	it = vect.begin();
	++it;
	for (; it != vect.end(); ++it) {
		cout << *it << " ";
	}




	listGraph.deleteNode(9);
	cout << "\n\n\n";
	cout << "Starting breadth-first-search after deleting Vertex 9: \n";
	startNode = 3;
	listGraph.bfs(listGraph,startNode);

    return 0;
}

