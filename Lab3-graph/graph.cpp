#include <vector>
#include <iostream>
#include "graph.h"
#include "Header.h"

const int INF = 1000000;

Graph::Graph(){
	
}//empty constructor

Graph::Graph(int amountNodes){
	setAmount(amountNodes);
	vector<int> buf(amount);
	for (int i = 0; i < amount; i++){
		matrix.push_back(buf);
	}
}

istream & operator >> (istream &s, Graph &it){
	int start, end, weigth;
	int c;
	do{
		printf("Enter start apex: ");
		get_flow_edge(start, s, it.getAmount() - 1);
		printf("Enter end apex: ");
		get_flow_edge(end, s, it.getAmount() - 1);
		printf("Enter weight of rib: ");
		get_flow(weigth, s);
		it.addRib(start, end, weigth);
		printf("Do you want to add more rib? (yes - 1 / no - 0)  ");
		s >> c;
	}while(c);
	return s;
}//enter ribs of graph

ostream & operator << (ostream &s, Graph &it){
	for(vector<int> c : it.matrix){
		for(int i : c)
			s << i << ' ';
		s << endl;
	}
	return s;
}//output graph

void Graph::deleteApex(int n){
	
}//delete apex with its ribs and all its appearance

void Graph::addApex(){
	amount++;
	vector<int> buf (amount);
	for(int i = 0; i < matrix.size(); i++)
		matrix[i].push_back(0);
	matrix.push_back(buf);
}//add apex

void Graph::deleteRib(int i, int j){
	
}//delete rib between i and j apexes

void Graph::addRib(int i, int j, int weight){
	matrix[i][j] = weight;
}


void Graph::floyd(){
	int i,j,u,v;
	d = new int*[amount];
	next = new int*[amount];
	for (i = 0; i < amount; i++){
		d[i] = new int[amount];
		next[i] = new int[amount];
		for(j = 0; j < amount; j++){
//			if(matrix[i][j])
//				d[i][j] = matrix[i][j];
//			else
//				d[i][j] = INT_MAX;
			if ( matrix[ i ][ j ] || i == j )
							{
								next[ i ][ j ] = j;
								d[ i ][ j ] = matrix[ i ][ j ];
							}
							else
							{
								next[ i ][ j ] = amount;
								d[ i ][ j ] = INF;
							}
			
		}
	}
	
	for(i = 0; i < amount; i++)
		for(u = 0; u < amount; u++)
			for(v = 0; v < amount; v++){
				if(d[u][i] + d[i][v] < d[u][v]){
					d[u][v] = d[u][i] + d[i][v];
					next[u][v] = next[u][i];
				}
			}
	
	for(i = 0; i < amount; i++){
		for(j = 0; j < amount; j++)
			cout << d[i][j] << ' ';
		cout << endl;
	}
	for(i = 0; i < amount; i++){
		for(j = 0; j < amount; j++)
			cout << next[i][j] << ' ';
		cout << endl;
	}
}

//void floid()
//{
//	// инициализация матриц путей и расстояний
//	for ( int u = 0; u < n; ++u )
//		for ( int v = 0; v < n; ++v )
//			if ( adj[ u ][ v ] || u == v )
//			{
//				path[ u ][ v ] = v;
//				dist[ u ][ v ] = adj[ u ][ v ];
//			}
//			else
//			{
//				path[ u ][ v ] = N;
//				dist[ u ][ v ] = INF;
//			}
//
//	// сам алгоритм флойда
//	for ( int k = 0; k < n; ++k )
//		for ( int u = 0; u < n; ++u )
//			if ( dist[ u ][ k ] != INF )
//				for ( int v = 0; v < n; ++v )
//					if ( dist[ u ][ v ] > dist[ u ][ k ] + dist[ k ][ v ] )
//					{
//						dist[ u ][ v ] = dist[ u ][ k ] + dist[ k ][ v ];
//						path[ u ][ v ] = path[ u ][ k ];
//					}
//}


void Graph::getShortestPath(int u, int v){
	if(d[u][v] == INT_MAX)
		printf("No path found");
	int c = u;
	while(c != v){
		printf("%d -> ", c);
		c = next[c][v];
	}
	printf("%d", v);
}
