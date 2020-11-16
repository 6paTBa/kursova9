#ifndef GRAPH_CLASS
#define GRAPG_CLASS

#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef unsigned int uint;

template <typename ident_type, typename price_type>
class Graph {
public:
    typedef unordered_map<ident_type, price_type> price_hash;
    typedef typename price_hash::iterator price_iterator;
    typedef typename price_hash::const_iterator cprice_iterator;

    typedef unordered_map<ident_type, price_hash> edges_hash;
    typedef typename edges_hash::iterator edge_iterator;
    typedef typename edges_hash::const_iterator cedge_iterator;

private:
    edges_hash graph;

public:
    Graph() : graph()
    {
    }

    Graph(Graph& another_Graph) : graph(another_Graph.graph)
    {
    }

    Graph& operator==(Graph& another_Graph)
    {
        graph = another_Graph.graph;
        return *this;
    }

    price_hash& operator[](ident_type ident)
    {
        return graph.at(ident);
    }

    const price_hash& operator[](ident_type ident) const
    {
        return (const price_hash&)graph.at(ident);
    }

    edge_iterator begin()
    {
        return graph.begin();
    }
    cedge_iterator begin() const
    {
        return graph.cbegin();
    }
    edge_iterator end()
    {
        return graph.end();
    }
    cedge_iterator end() const
    {
        return graph.cend();
    }

    size_t size()
    {
        return graph.size();
    }

    bool is_exist(ident_type ident_1)
    {
        auto i_result = graph.find(ident_1);
        if (i_result == graph.end()) {
            return false;
        }
        return true;
    }

    bool is_exist(ident_type ident_1, ident_type ident_2)
    {
        auto i_result = graph.find(ident_1);
        if (i_result == graph.end()) {
            return false;
        }
        auto o_result = i_result->second.find(ident_2);
        if (o_result == i_result->second.end()) {
            return false;
        }
        return true;
    }

    pair<edge_iterator, pair<price_iterator, bool>>
    add_oriented(ident_type ident1, ident_type ident2, price_type price)
    {
        pair<edge_iterator, pair<price_iterator, bool>> result;
        result.first = graph.find(ident1);

        // clang-format off
        if (result.first != graph.end()) {
            result.second = result.first->second.insert(make_pair(ident2, price));
            if (!result.second.second) {
                return result;
            }
        } else {
            auto new_edge = make_pair(ident1, unordered_map<ident_type, price_type>());
            result.first = graph.insert(new_edge).first;
            result.second = result.first->second.insert(make_pair(ident2, price));
        }
        graph.insert(make_pair(ident2, unordered_map<ident_type, price_type>()));

        // clang-format on
        return result;
    }

    pair<edge_iterator, pair<price_iterator, bool>>
    add_unoriented(ident_type ident1, ident_type ident2, price_type price)
    {
        auto result = add_oriented(ident1, ident2, price);
        if (!result.second.second) {
            return result;
        }
        result = add_oriented(ident2, ident1, price);
        return result;
    }

    price_type route_price(list<ident_type>& route)
    {
        price_type total_price = 0;

        for (auto it = route.begin(); it != --route.end(); it++) {
            auto to_it = it;
            to_it++;
            assert(is_exist(*it, *to_it) && "EDGE DOES NOT EXIST IN GRAPH");
            total_price += graph[*it][*to_it];
        }

        return total_price;
    }
};

template <typename ident_type, typename price_type>
list<ident_type> find_shortest_route(
        const Graph<ident_type, price_type>& graph,
        ident_type from,
        ident_type to)
{
    for (auto& edges : graph) {
        for (auto& prices : edges.second) {
            assert(prices.second >= 0 && "Shoud be greater than zero");
        }
    }

    list<ident_type> route;
    if (from == to) {
        route.push_front(to);
        return route;
    }

    // clang-format off
    typename Graph<ident_type, price_type>::price_hash cur_prices = graph[from];
    typename Graph<ident_type, price_type>::price_iterator cur_min = cur_prices.begin();
    // clang-format on

    unordered_map<ident_type, ident_type> lead_from;
    for (auto it = cur_prices.begin(); it != cur_prices.end(); it++) {
        lead_from[it->first] = from;
    }

    unordered_set<ident_type> visited;
    visited.insert(from);

    while (!cur_prices.empty()) {
        cur_min = cur_prices.begin();
        for (auto it = cur_prices.begin(); it != cur_prices.end(); it++) {
            if (it->second < cur_min->second) {
                cur_min = it;
            }
        }

        if (cur_min->first == to) {
            while (lead_from.find(to) != lead_from.end()) {
                route.push_front(to);
                to = lead_from[to];
            }
            break;
        }

        auto& cur_min_possible_ways = graph[cur_min->first];
        // clang-format off
        for (auto it = cur_min_possible_ways.begin(); it != cur_min_possible_ways.end(); it++) {
            if (visited.find(it->first) == visited.end()) {
                auto already_in_prices = cur_prices.find(it->first);
                if (already_in_prices != cur_prices.end()) {
                    if (already_in_prices->second > it->second + cur_min->second) {
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
        // clang-format on
        visited.insert(cur_min->first);
        cur_prices.erase(cur_min);
    }

    if (route.empty()) {
        return route;
    } else {
        route.push_front(from);
        return route;
    }
}

template <typename ident_type, typename price_type>
vector<list<ident_type>> find_possible_routes(
        Graph<ident_type, price_type>& graph, ident_type from, ident_type to)
{
    vector<list<ident_type>> all_routes;
    // clang-format off
    list<pair<ident_type,typename Graph<ident_type, price_type>::price_iterator>> cur_route(1, make_pair(from, graph[from].begin()));

    while (!cur_route.empty()) {
        for (auto& it = cur_route.back().second;it != graph[cur_route.back().first].end();it++) {
            bool already_in_route = false;
            for (auto route_it = cur_route.begin(); route_it != cur_route.end(); route_it++) {
                if (route_it->first == it->first) {
                    already_in_route = true;
                    break;
                }
            }
            if (already_in_route) {
                continue;
            } else {
                cur_route.push_back(make_pair(it->first, graph[it->first].begin()));
                it++;
                break;
            }
        }
        if (cur_route.back().first == to) {
            list<ident_type> new_route;
            for (auto& cur_pair : cur_route) {
                new_route.push_back(cur_pair.first);
            }
            all_routes.push_back(new_route);
            cur_route.erase(--cur_route.end());
        } else if (
                cur_route.back().second == graph[cur_route.back().first].end()) {
            cur_route.erase(--cur_route.end());
        }
    }
    return all_routes;
    // clang-format on
}

template <typename ident_type, typename price_type>
void print_graph(Graph<ident_type, price_type>& graph, ostream& out)
{
    for (auto edges : graph) {
        out << edges.first << " : ";
        for (auto& prices : edges.second) {
            out << prices.first << "," << prices.second << " ";
        }
        out << endl;
    }
}

#endif