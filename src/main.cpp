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
		if(cur_comand == "add") 
		{
			if(total_args < 3)
			{
				cerr << "Too few arguments for \"add\"" << endl;
				continue;
			}
			string mode; s_strm >> mode; 
			if(mode.size() != 1)
			{
				cerr << "unrecognized mode: \"" << mode << "\"" << endl;
				continue;
			}
			string name_1, name_2;
			s_strm >> name_1; s_strm >> name_2; 
			uint price; s_strm >> price;
			switch(mode[0]) 
			{
				case 'u':
				{
					auto add_result = graph.add_unoriented(name_1, name_2, price);
					if(!add_result.second.second)
					{
						cout << "Route from \"" << add_result.first->first << "\" to \"" <<
							add_result.second.first->first << "\" is alredy added for "
							<< add_result.second.first->second << endl;
						cout << "Change price? y/n" << endl;
						string change;
						while(1)
						{
							cin >> change;
							cin.ignore();
							if(change.size() != 1)
							{
								cerr << "unrecognized answer: \"" << change << "\"" << endl;
								continue;
							}
							switch(change[0])
							{
								case 'y':
									add_result.second.first->second = price;
									break;
								case 'n':
									break;
								default:
									cerr << "unrecognized answer: \"" << change << "\"" << endl;
									continue;
									break;
							}
							break;
						}
					}
					break;
				}
				case 'o':
				{
					auto add_result = graph.add_oriented(name_1, name_2, price);
					if(!add_result.second.second)
					{
						cout << "Route from \"" << add_result.first->first << "\" to \"" <<
							add_result.second.first->first << "\" is alredy added for "
							<< add_result.second.first->second << endl;
						cout << "Change price? y/n" << endl;
						string change;
						while(1)
						{
							cin >> change;
							cin.ignore();
							if(change.size() != 1)
							{
								cerr << "unrecognized answer: \"" << change << "\"" << endl;
								continue;
							}
							switch(change[0])
							{
								case 'y':
									add_result.second.first->second = price;
									break;
								case 'n':
									break;
								default:
									cerr << "unrecognized answer: \"" << change << "\"" << endl;
									continue;
									break;
							}
							break;
						}
					}
					break;
				}
				default:
					cerr << "unrecognized mode: \"" << mode << "\"" << endl;
					continue;
			}
			
			continue;
		}
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