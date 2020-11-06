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
        
        pair<edge_iterator, pair<price_iterator, bool>> add_oriented(ident_type ident1, ident_type ident2, price_type price){
            pair<edge_iterator, pair<price_iterator, bool>> result;

            /* дополнить */

            return result;
        }
        //ориентированное добавление узла
        pair<edge_iterator, pair<price_iterator, bool>> add_unoriented(ident_type ident1, ident_type ident2, price_type price){
            auto result = add_oriented(ident1, ident2, price);
            if(!result.second.second)
                return result;
            result = add_oriented(ident2, ident1, price);
            return result;
        }
        //неориентированное добавление узла
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
        //возвращает длинну всего маршрута заданного списком 

        //переопределить возвращаемые функциями значения
};

//добавить функции поиска кратчайшего, длиннейшего маршрутов
//общего числа маршрутов
//и функцию вывода графа

#endif