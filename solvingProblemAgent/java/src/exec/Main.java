package src.exec;

import src.model.graph.*;

public class Main {
    public static void main(String[] args){
        String[] cityNames = {"Arad", "Zerind", "Timisoara", "Oradea", "Sibiu", "Lugoj",
        "Mehadia", "Drobeta", "Craiova", "Rimnicu Vilcea", "Pitesti",
        "Bucharest", "Giurgiu", "Urziceni", "Fagaras", "Hirsova", "Eforie",
        "Vaslui", "Iasi", "Neamt"};

        //Starting graph construction
        Map map = new Map(cityNames);
        map.initializeAdjacentList("Arad", new int[]{118, 140, 75}, new String[]{"Timisoara", "Sibiu", "Zerind"});
        map.initializeAdjacentList("Timisoara", new int[]{118, 111}, new String[]{"Arad", "Lugoj"});
        map.initializeAdjacentList("Zerind", new int[]{75, 71}, new String[]{"Arad", "Oradea"});
        map.initializeAdjacentList("Oradea", new int[]{71, 151}, new String[]{"Zerind", "Sibiu"});
        map.initializeAdjacentList("Sibiu", new int[]{151, 140, 99, 80}, new String[]{"Oradea", "Arad", "Fagaras", "Rimnicu Vilcea"});
        map.initializeAdjacentList("Fagaras", new int[]{99, 211}, new String[]{"Sibiu", "Bucharest"});
        map.initializeAdjacentList("Lugoj", new int[]{111, 70}, new String[]{"Timisoara", "Mehadia"});
        map.initializeAdjacentList("Mehadia", new int[]{70, 75}, new String[]{"Lugoj", "Drobeta"});
        map.initializeAdjacentList("Drobeta", new int[]{75, 120}, new String[]{"Mehadia", "Craiova"});
        map.initializeAdjacentList("Craiova", new int[]{120, 146, 138,}, new String[]{"Drobeta", "Rimnicu Vilcea", "Pitesti"});
        map.initializeAdjacentList("Rimnicu Vilcea", new int[]{80, 146, 97}, new String[]{"Sibiu", "Craiova", "Pitesti"});
        map.initializeAdjacentList("Pitesti", new int[]{97, 138, 101}, new String[]{"Rimnicu Vilcea", "Craiova", "Bucharest"});
        map.initializeAdjacentList("Bucharest",new int[]{90, 101, 211, 85}, new String[]{"Giurgiu", "Pitesti", "Fagaras", "Urziceni"});
        map.initializeAdjacentList("Giurgiu", new int[]{90}, new String[]{"Bucharest"});
        map.initializeAdjacentList("Urziceni", new int[]{85, 98, 142}, new String[]{"Bucharest", "Hirsova", "Vaslui"});
        map.initializeAdjacentList("Hirsova", new int[]{98, 86}, new String[]{"Urziceni", "Eforie"});
        map.initializeAdjacentList("Eforie", new int[]{86}, new String[]{"Hirsova"});
        map.initializeAdjacentList("Vaslui", new int[]{142, 92}, new String[]{"Urziceni", "Iasi"});
        map.initializeAdjacentList("Iasi", new int[]{92, 87}, new String[]{"Vaslui", "Neamt"});
        map.initializeAdjacentList("Neamt", new int[]{87}, new String[]{"Iasi"});
        System.out.println(map.toString());
    }
}


