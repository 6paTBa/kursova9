#include "GraphClass.h"
#include <ctest.h>

CTEST(is_exist_ident_check, unknown_ident)
{
    Graph<string, uint> graph;
    string ident = "city_name";
    ASSERT_FALSE(graph.is_exist(ident));
}

CTEST(is_exist_ident_check, added_ident)
{
    Graph<string, uint> graph;
    string ident_1 = "city_1", ident_2 = "city_2";
    uint route = 1;
    graph.add_oriented(ident_1, ident_2, route);
    ASSERT_TRUE(graph.is_exist(ident_1));
}

CTEST(is_exist_route_check, unknown_route)
{
    Graph<string, uint> graph;
    string ident_1 = "city_1", ident_2 = "city_2";
    uint route = 1;
    graph.add_oriented(ident_1, ident_2, route);
    ASSERT_FALSE(graph.is_exist(ident_2, ident_1));
}

CTEST(is_exist_route_check, added_route)
{
    Graph<string, uint> graph;
    string ident_1 = "city_1", ident_2 = "city_2";
    uint route = 1;
    graph.add_oriented(ident_1, ident_2, route);
    ASSERT_TRUE(graph.is_exist(ident_1, ident_2));
}