#ifndef _SUP__M__
#define _SUP__M__

#include <iostream>
using namespace std;

//----------------------------CheckData------------------------//
template <class NUMBER, class STREAM>
int get_flow(NUMBER &num, STREAM &flow) {
	flow >> num;
	while (!flow.good())
	{
		cout << "repeat: ";
		flow.clear();
		flow.ignore(numeric_limits <streamsize>::max(), '\n');
		flow >> num;
	}
	return num;
}

template <class NUMBER, class STREAM>
int get_flow_edge(NUMBER &num, STREAM &flow, int edge) {
	flow >> num;
	while ((num > edge)||(num < 0)||!flow.good())
	{
		cout << "max is " << edge << " min is 0. "<< "repeat: ";
		flow.clear();
		flow.ignore(numeric_limits <streamsize>::max(), '\n');
		flow >> num;
	}
	return num;
}
//----------------------------CheckData------------------------//

#endif // !_SUP__M__
