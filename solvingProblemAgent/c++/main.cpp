#include "graph/transition.cpp"
#include "graph/state.cpp"
#include "graph/map.cpp"
#include <iostream>
#include <string>
#include <vector>
#include "searchInWidth/no.cpp"
#include "searchInWidth/edge.cpp"
using namespace std;


int main(){
    map _map = map();
    vector<string> cityNames = {"Arad", "Zerind", "Timisoara", "Oradea", "Sibiu", "Lugoj",
                        "Mehadia", "Drobeta", "Craiova", "Rimnicu Vilcea", "Pitesti",
                        "Bucharest", "Giurgiu", "Urziceni", "Fagaras", "Hirsova", "Eforie",
                        "Vaslui", "Iasi", "Neamt"};
    
    _map.initializerMap(cityNames);
    _map.initializerAdjacentList("Arad", {118, 140, 75}, {"Timisoara", "Sibiu", "Zerind"});
    _map.initializerAdjacentList("Timisoara", {118, 111}, {"Arad", "Lugoj"});
    _map.initializerAdjacentList("Zerind", {75, 71}, {"Arad", "Oradea"});
    _map.initializerAdjacentList("Oradea", {71, 151}, {"Zerind", "Sibiu"});
    _map.initializerAdjacentList("Sibiu", {151, 140, 99, 80}, {"Oradea", "Arad", "Fagaras", "Rimnicu Vilcea"});
    _map.initializerAdjacentList("Fagaras", {99, 211}, {"Sibiu", "Bucharest"});
    _map.initializerAdjacentList("Lugoj", {111, 70}, {"Timisoara", "Mehadia"});
    _map.initializerAdjacentList("Mehadia", {70, 75}, {"Lugoj", "Drobeta"});
    _map.initializerAdjacentList("Drobeta", {75, 120}, {"Mehadia", "Craiova"});
    _map.initializerAdjacentList("Craiova", {120, 146, 138,}, {"Drobeta", "Rimnicu Vilcea", "Pitesti"});
    _map.initializerAdjacentList("Rimnicu Vilcea", {80, 146, 97}, {"Sibiu", "Craiova", "Pitesti"});
    _map.initializerAdjacentList("Pitesti", {97, 138, 101}, {"Rimnicu Vilcea", "Craiova", "Bucharest"});
    _map.initializerAdjacentList("Bucharest", {90, 101, 211, 85}, {"Giurgiu", "Pitesti", "Fagaras", "Urziceni"});
    _map.initializerAdjacentList("Giurgiu", {90}, {"Bucharest"});
    _map.initializerAdjacentList("Urziceni", {85, 98, 142}, {"Bucharest", "Hirsova", "Vaslui"});
    _map.initializerAdjacentList("Hirsova", {98, 86}, {"Urziceni", "Eforie"});
    _map.initializerAdjacentList("Eforie", {86}, {"Hirsova"});
    _map.initializerAdjacentList("Vaslui", {142, 92}, {"Urziceni", "Iasi"});
    _map.initializerAdjacentList("Iasi", {92, 87}, {"Vaslui", "Neamt"});
    _map.initializerAdjacentList("Neamt", {87}, {"Iasi"});
    
    cout << _map.toString();
    
    no* N = new no();
    no* M = new no(_map.getStates()[0], N, 100);

    //Desalocando ptrs
    for(int k=0; k<_map.getStates().size(); k++){
        for(int j=0; j<_map.getStates()[k]->getAdjacentList().size(); j++){
            delete(_map.getStates()[k]->getAdjacentList()[j]);
        }
        delete(_map.getStates()[k]);
    }

    


    return 0;
}