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

        edge_iterator begin(){
            return graph.begin();
        }
		cedge_iterator begin(){
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
        //добавить итераторы и переопределить операторы

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
        
        pair<edge_iterator, pair<price_iterator, bool>> add_oriented(ident_type, ident_type, price_type);
        //ориентированное добавление узла
        pair<edge_iterator, pair<price_iterator, bool>> add_unoriented(ident_type, ident_type, price_type);
        //неориентированное добавление узла
        price_type root_price(list<ident_type>&);
        //возвращает длинну всего маршрута заданного списком 

        //переопределить возвращаемые функциями значения
};

template <typename ident_type, typename price_type> 
list<ident_type> find_shortest_route(
	const Graph<ident_type, price_type>& graph,
	ident_type from, 
	ident_type to); //будем находить кратчайший путь между точками

template <typename ident_type, typename price_type> 
vector<list<ident_type>> find_possible_routes(
	Graph<ident_type, price_type>& graph,
	ident_type from, 
	ident_type to); // поиск всех путей

//и функцию вывода графа

#endif