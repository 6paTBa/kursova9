#include "GraphClass.h"

template <typename ident_type, typename price_type> 
void print_graph(Graph<ident_type, price_type>& graph, ostream& out) 
{
	for(auto edges : graph)
	{
		out << edges.first << " : ";
		for(auto& prices : edges.second)
			out << prices.first << "," << prices.second << " ";
		out << endl;
	}
}