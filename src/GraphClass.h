#ifndef GRAPH_CLASS
#define GRAPG_CLASS

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <cassert>

using namespace std;
typedef unsigned int uint;

template <typename ident_type, typename price_type> class Graph
{
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
        Graph():graph(){}

        Graph(Graph& another_Graph) : graph(another_Graph.graph){}

        Graph& operator==(Graph& another_Graph)
		{graph = another_Graph.graph; return *this;}

		price_hash& operator[](ident_type ident)
		{return graph.at(ident);}
        
		const price_hash& operator[](ident_type ident) const
		{return (const price_hash&)graph.at(ident);}

        edge_iterator begin(){
            return graph.begin();
        }
		cedge_iterator begin() const{
            return graph.cbegin();
        }
		edge_iterator end(){
            return graph.end();
        }
		cedge_iterator end() const{
            return graph.cend();
        }

        size_t size(){
            return graph.size();
        }

        bool is_exist(ident_type ident_1){
            auto i_result = graph.find(ident_1);
            if(i_result == graph.end()){
                return false;
            }
            return true;
        }
    
        bool is_exist(ident_type ident_1, ident_type ident_2){
            auto i_result = graph.find(ident_1);
            if(i_result == graph.end()){
                return false;
            }
            auto o_result = i_result->second.find(ident_2);
            if(o_result == i_result->second.end()){
                return false;
            }
            return true;
        }
        
        pair<edge_iterator, pair<price_iterator, bool>> add_oriented(ident_type ident1, ident_type ident2, price_type price){
            pair<edge_iterator, pair<price_iterator, bool>> result;
            result.first = graph.find(ident1);

			if(result.first != graph.end()){
				result.second =
					result.first->second.insert(make_pair(ident2, price));
				if(!result.second.second){
					return result;
                }
			} else {
				auto new_edge = make_pair(ident1, unordered_map<ident_type, price_type>());
				result.first = graph.insert(new_edge).first;
				result.second = result.first->second.insert(make_pair(ident2, price));
			}
			graph.insert(make_pair(ident2, unordered_map<ident_type, price_type>()));

            return result;
        }

        pair<edge_iterator, pair<price_iterator, bool>> add_unoriented(ident_type ident1, ident_type ident2, price_type price){
            auto result = add_oriented(ident1, ident2, price);
            if(!result.second.second){
                return result;
            }
            result = add_oriented(ident2, ident1, price);
            return result;
        }

        price_type root_price(list<ident_type>& route){
            price_type total_price = 0;
            
            for(auto it = route.begin(); it != --route.end(); it++){
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
	ident_type to);

template <typename ident_type, typename price_type> 
vector<list<ident_type>> find_possible_routes(
	Graph<ident_type, price_type>& graph,
	ident_type from, 
	ident_type to);

//и функцию вывода графа

#endif