#include "GraphClass.h"
#include <sstream>

int main()
{
    Graph<string, uint> graph;
    cout << "COMMANDS:" << endl;
    cout << "add [u, o] [name1] [name2] [price]" << endl;
    cout << "longest [name1] [name2]" << endl;
    cout << "shortest [name1] [name2]" << endl;
    cout << "all [name1] [name2]" << endl;
    cout << "commands" << endl;
    cout << "print" << endl;
    cout << "exit" << endl;

    while (true) {
        cout << "ENTER THE COMMAND:" << endl;
        string cur_comand;
        getline(cin, cur_comand, '\n');
        if (cur_comand.size() == 0)
            continue;
        size_t pos = 0;
        size_t total_args = 0;
        while ((pos = cur_comand.find(' ', pos)) != string::npos) {
            total_args++;
            pos++;
        }
        stringstream s_strm(cur_comand);
        s_strm >> cur_comand;
        if (cur_comand == "add") {
            if (total_args < 3) {
                cerr << "Too few arguments for \"add\"" << endl;
                continue;
            }
            string mode;
            s_strm >> mode;
            if (mode.size() != 1) {
                cerr << "unrecognized mode: \"" << mode << "\"" << endl;
                continue;
            }
            string name_1, name_2;
            s_strm >> name_1;
            s_strm >> name_2;
            uint price;
            s_strm >> price;
            switch (mode[0]) {
            case 'u': {
                auto add_result = graph.add_unoriented(name_1, name_2, price);
                if (!add_result.second.second) {
                    cout << "Route from \"" << add_result.first->first
                         << "\" to \"" << add_result.second.first->first
                         << "\" is alredy added for "
                         << add_result.second.first->second << endl;
                    cout << "Change price? y/n" << endl;
                    string change;
                    while (1) {
                        cin >> change;
                        cin.ignore();
                        if (change.size() != 1) {
                            cerr << "unrecognized answer: \"" << change << "\""
                                 << endl;
                            continue;
                        }
                        switch (change[0]) {
                        case 'y':
                            add_result.second.first->second = price;
                            break;
                        case 'n':
                            break;
                        default:
                            cerr << "unrecognized answer: \"" << change << "\""
                                 << endl;
                            continue;
                            break;
                        }
                        break;
                    }
                }
                break;
            }
            case 'o': {
                auto add_result = graph.add_oriented(name_1, name_2, price);
                if (!add_result.second.second) {
                    cout << "Route from \"" << add_result.first->first
                         << "\" to \"" << add_result.second.first->first
                         << "\" is alredy added for "
                         << add_result.second.first->second << endl;
                    cout << "Change price? y/n" << endl;
                    string change;
                    while (1) {
                        cin >> change;
                        cin.ignore();
                        if (change.size() != 1) {
                            cerr << "unrecognized answer: \"" << change << "\""
                                 << endl;
                            continue;
                        }
                        switch (change[0]) {
                        case 'y':
                            add_result.second.first->second = price;
                            break;
                        case 'n':
                            break;
                        default:
                            cerr << "unrecognized answer: \"" << change << "\""
                                 << endl;
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
        } else if (cur_comand == "longest") {
            if (total_args < 2) {
                cerr << "Too few arguments for \"longest\"" << endl;
                continue;
            }
            string name_1, name_2;
            s_strm >> name_1 >> name_2;
            if (!graph.is_exist(name_1) | !graph.is_exist(name_2)) {
                cerr << "No such nodes: ";
                if (!graph.is_exist(name_1))
                    cerr << name_1 << " ";
                if (!graph.is_exist(name_2))
                    cerr << name_2 << " ";
                cerr << endl;
                continue;
            }
            auto all = find_possible_routes(graph, name_1, name_2);
            size_t max_route = 0;
            uint max_price = 0;
            for (size_t i = 0; i < all.size(); i++) {
                uint cur_price = graph.route_price(all[i]);
                if (cur_price > max_price) {
                    max_price = cur_price;
                    max_route = i;
                }
            }
            cout << "Longest route price = " << max_price << endl;
            // clang-format off
            for (auto it = all[max_route].begin(); it != all[max_route].end(); it++)
                cout << *it << "->";
            cout << endl;
            // clang-format on

            continue;
        } else if (cur_comand == "shortest") {
            if (total_args < 2) {
                cerr << "Too few arguments for \"shortest\"" << endl;
                continue;
            }
            string name_1, name_2;
            s_strm >> name_1 >> name_2;
            if (!graph.is_exist(name_1) | !graph.is_exist(name_2)) {
                cerr << "No such nodes: ";
                if (!graph.is_exist(name_1))
                    cerr << name_1 << "; ";
                if (!graph.is_exist(name_2))
                    cerr << name_2 << ";";
                cerr << endl;
                continue;
            }
            auto shortest = find_shortest_route(graph, name_1, name_2);
            // clang-format off
            cout << "Shortest route price = " << graph.route_price(shortest) << endl;
            // clang-format on
            for (auto it = shortest.begin(); it != shortest.end(); it++)
                cout << *it << "->";
            cout << endl;

            continue;
        } else if (cur_comand == "all") {
            if (total_args < 2) {
                cerr << "Too few arguments for \"all\"" << endl;
                continue;
            }
            string name_1, name_2;
            s_strm >> name_1 >> name_2;
            if (!graph.is_exist(name_1) | !graph.is_exist(name_2)) {
                cerr << "No such nodes: ";
                if (!graph.is_exist(name_1))
                    cerr << name_1 << " ";
                if (!graph.is_exist(name_2))
                    cerr << name_2 << " ";
                cerr << endl;
                continue;
            }
            auto all = find_possible_routes(graph, name_1, name_2);
            cout << "There are " << all.size() << " possible routes:" << endl;
            for (auto& route : all) {
                for (auto it = route.begin(); it != route.end(); it++)
                    cout << *it << "->";
                cout << endl;
            }

            continue;
        } else if (cur_comand == "print") {
            print_graph(graph, cout);
            cout << endl;
        } else if (cur_comand == "commands") {
            cout << "COMMANDS:" << endl;
            cout << "add [u, o] [name1] [name2] [price]" << endl;
            cout << "longest [name1] [name2]" << endl;
            cout << "shortest [name1] [name2]" << endl;
            cout << "all [name1] [name2]" << endl;
            cout << "commands" << endl;
            cout << "print" << endl;
            cout << "exit" << endl;

        } else if (cur_comand == "exit") {
            break;
        } else {
            cerr << "Unrecognized command \"" << cur_comand << "\"" << endl;
            continue;
        }

        continue;
    }

    return 0;
}