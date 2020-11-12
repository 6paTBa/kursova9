#include "GraphClass.h"

template <typename ident_type, typename price_type> list<ident_type> 
find_shortest_route(const Graph<ident_type, price_type>& graph, ident_type from, ident_type to)
{
	for(auto& edges : graph){
		for(auto& prices : edges.second)
			assert(prices.second >= 0 && "Shoud be greater than zero");
	}

    list<ident_type> route;
	if(from == to){
		route.push_front(to);
		return route;
	}

	typename Graph<ident_type, price_type>::price_hash cur_prices = graph[from];
	typename Graph<ident_type, price_type>::price_iterator cur_min = cur_prices.begin();

	unordered_map<ident_type, ident_type> lead_from;
	for(auto it = cur_prices.begin(); it != cur_prices.end(); it++){
		lead_from[it->first] = from;
	}

    unordered_set<ident_type> visited;
	visited.insert(from);

    while(!cur_prices.empty()){
		cur_min = cur_prices.begin();
		for(auto it = cur_prices.begin(); it != cur_prices.end(); it++){
			if(it->second < cur_min->second) cur_min = it;
		}
		
		if(cur_min->first == to){
			while(lead_from.find(to) != lead_from.end())
			{
				route.push_front(to);
				to = lead_from[to];
			}
			break;
		}
		
		auto& cur_min_possible_ways = graph[cur_min->first];
		for(auto it = cur_min_possible_ways.begin(); it != cur_min_possible_ways.end(); it++){
			if(visited.find(it->first) == visited.end()){
				auto already_in_prices = cur_prices.find(it->first);
				if(already_in_prices != cur_prices.end()){
					if(already_in_prices->second > it->second + cur_min->second){
						already_in_prices->second = it->second + cur_min->second;
						lead_from[already_in_prices->first] = cur_min->first;
					}
				} else {
					auto inserted = cur_prices.insert(*it);
					inserted.first->second += cur_min->second;
					lead_from[it->first] = cur_min->first;
				}
			}
		}
		visited.insert(cur_min->first);
		cur_prices.erase(cur_min);
    }

	if(route.empty()){
		return route;
	} else {
		route.push_front(from);
		return route;
	}
}

template <typename ident_type, typename price_type> 
vector<list<ident_type>> find_possible_routes(Graph<ident_type, price_type>& graph, ident_type from, ident_type to)
{
    vector<list<ident_type>> all_routes;
	list<pair<ident_type, typename Graph<ident_type, price_type>::price_iterator>> cur_route(1, make_pair(from, graph[from].begin()));
    while(!cur_route.empty()){
		for(auto& it = cur_route.back().second; it != graph[cur_route.back().first].end(); it++){
			bool already_in_route = false;
			for(auto route_it = cur_route.begin(); route_it != cur_route.end(); route_it++){
				if(route_it->first == it->first){
					already_in_route = true; break;
				}
			}
			if(already_in_route){ 
				continue;
			} else {
				cur_route.push_back(make_pair(it->first, graph[it->first].begin()));
				it++;
				break;
			}
		}
		if(cur_route.back().first == to){
			list<ident_type> new_route;
			for(auto& cur_pair : cur_route)
				new_route.push_back(cur_pair.first);
			all_routes.push_back(new_route);
			cur_route.erase(--cur_route.end());
		} else if(cur_route.back().second == graph[cur_route.back().first].end()){
			cur_route.erase(--cur_route.end());
		}
	}
	return all_routes;
}