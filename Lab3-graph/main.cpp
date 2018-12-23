// A simple representation of graph using STL 
//#include<bits/stdc++.h> 
#include <vector>
#include <iostream>
#include <cstdlib>
#include "graph.h"
#include "Header.h"
using namespace std;


int main()
{
//	int c = 1;
//	Graph my(6);
	Graph my;
//	while(c){
//		cout << my;
//		cout << "\nADD?  ";
//		get_flow(c, cin);
//		if(c)
//			my.addApex();
//	}
//	cin >> my;
	cout << my;
	int u,v;
	cout << "Enter start and end apex with space: ";
	cin >> u >> v;
	my.floyd();
	cout << "Shortest way: ";
	my.getShortestPath(u, v);
	return 0;
}
