#ifndef _GRAF__G
#define _GRAF__G

#include <vector>
#include <iostream>

using namespace std;

class Graph {
	int amount;
	vector<vector<int>> matrix;
	int ** d;
	int ** next;
public :
	Graph();//empty constructor
	Graph(int amountNodes);//create graph with amountNodes apexes
	
	int getAmount(){return amount;}
	void setAmount(int a){amount = a;}
	
	friend istream & operator >> (istream &, Graph &);//enter ribs of graph
	friend ostream & operator << (ostream &, Graph &);//output graph
	
	void deleteApex(int n);//delete apex with its ribs and all its appearance
	void addApex();//add apex
	void deleteRib(int i, int j);//delete rib between i and j apexes
	void addRib(int i, int j, int weight);//add rib between i and j apexes
	
	void floyd();
	void getShortestPath(int u, int v);
};
#endif // !_GRAF__G
