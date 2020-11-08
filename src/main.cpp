#include <iostream>
#include <sstream>
#include "GraphClass.h"

int main()
{
    Graph<string, uint> graph; 
	cout << "COMMANDS:" << endl;
	cout << "add [u, o] [name1] [name2] [price]" << endl;
	cout << "longest [name1] [name2]" << endl;
	cout << "shortest [name1] [name2]" << endl;
	cout << "all [name1] [name2]" << endl;
	cout << "print" << endl;
	cout << "exit" << endl;

	while(true)
	{
		if(cur_comand == "add") {}
		else if(cur_comand == "longest") {}
		else if(cur_comand == "shortest") {}
		else if(cur_comand == "all") {}
		else if(cur_comand == "print") 
			{
				print_graph(graph, cout); cout << endl;
			}
		else if(cur_comand == "exit")
			{
				break;
			}
		else
			{
				cerr << "Unrecognized command \"" << cur_comand <<"\"" << endl;
				continue;
			}

		continue;

	}

    return 0;
}