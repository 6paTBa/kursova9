#include "GraphClass.h"

template <typename ident_type, typename price_type> list<ident_type> find_shortest_route(const Graph<ident_type, price_type>& graph, ident_type from, ident_type to)
{
    list<ident_type> route;
	if(from == to)
	{
		route.push_front(to);
		return route;
	}

    typename Graph<ident_type, price_type>::price_hash cur_prices = graph[from];
	typename Graph<ident_type, price_type>::price_iterator cur_min = cur_prices.begin();

    unordered_set<ident_type> visited;
	visited.insert(from);

    while(!cur_prices.empty())
    {  
    }
}

template <typename ident_type, typename price_type> 
vector<list<ident_type>> find_possible_routes(Graph<ident_type, price_type>& graph, ident_type from, ident_type to)
{
    vector<list<ident_type>> all_routes;
	list<pair<ident_type, typename Graph<ident_type, price_type>::price_iterator>> cur_route(1, make_pair(from, graph[from].begin()));
    while(!cur_route.empty())
	{
		for(auto& it = cur_route.back().second; it != graph[cur_route.back().first].end(); it++)
		{
			bool already_in_route = false;
			for(auto route_it = cur_route.begin(); route_it != cur_route.end(); route_it++)
			{
				if(route_it->first == it->first)
					{already_in_route = true; break;}
			}
			if(already_in_route) continue;
			else
			{
				cur_route.push_back(make_pair(it->first, graph[it->first].begin()));
				it++;
				break;
			}
		}
		if(cur_route.back().first == to)
		{
			list<ident_type> new_route;
			for(auto& cur_pair : cur_route)
				new_route.push_back(cur_pair.first);
			all_routes.push_back(new_route);
			cur_route.erase(--cur_route.end());
		}
		else if(cur_route.back().second == graph[cur_route.back().first].end())
			cur_route.erase(--cur_route.end());
	}
	return all_routes;
}