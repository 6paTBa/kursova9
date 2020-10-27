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
        //добавить итераторы и переопределить операторы

        bool is_exist(ident_type);
        //существование города
        bool is_exist(ident_type, ident_type);
        //существование пути между городами
        void add_oriented(ident_type, ident_type, price_type);
        //ориентированное добавление узла
        void add_unoriented(ident_type, ident_type, price_type);
        //неориентированное добавление узла
        price_type root_price(/*???*/);
        //возвращает длинну всего маршрута заданного (чем?)

        //переопределить возвращаемые функциями значения
};

//добавить функции поиска кратчайшего, длиннейшего маршрутов
//общего числа маршрутов
//и функцию вывода графа

#endif