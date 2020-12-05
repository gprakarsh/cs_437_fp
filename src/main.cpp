#include <iostream>
#include <stdlib.h>

#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "BFS.h"
#include "Mock.h"


void demo() {
    Vertex v0 = Vertex(0, "0");
    Vertex v1 = Vertex(1, "1");
    Vertex v2 = Vertex(2, "2");
    Vertex v3 = Vertex(3, "3");

    Graph g;
    insertBasicCycle(g, 0);
    std::cout << "Cyclical structure\n";
    g.displayGraph();

    Graph treeGraph;
    insertBasicTree(treeGraph, 0);
    std::cout << "Treelike structure\n";
    treeGraph.displayGraph();

    std::cout << "BFS Traversal of tree from root='0':\n";

    for (auto v : treeGraph.getBFS(Vertex(0, "0"))) {
        std::cout << v << ", ";
    }
    std::cout << '\n';

    std::cout << "BFS Traversal of tree from subroot='0.1':\n";

    for (auto v : treeGraph.getBFS(Vertex(1, "0.1"))) {
        std::cout << v << ", ";
    }
    std::cout << '\n';

    std::cout << "Demonstration of BFS and obtaining predecessors.\n";
    auto bfs = treeGraph.getBFS(Vertex(0, "0"));
    for (auto it = bfs.begin(); it != bfs.end(); ++it) {
        std::cout << *it; 
        if(!it.arrivalEdge().isEmpty()){
            std::cout<<", origin: " << it.arrivalEdge().source_node_id_ << '\n';
        } else {
            std::cout<<" (root)"<<std::endl;
        }
    }
    bfs = treeGraph.getBFS(Vertex(1, "1"));
}

int main(int argc, char* argv[]){

    demo();
    ////////////Preprocessing//////////////

    if (argc >= 4){
        std::cout<<"Started preprocessing"<<std::endl;

        std::string verticesFile = argv[1];
        std::string edgesFile = argv[2];

        Graph pGraph(verticesFile,edgesFile);

        std::cout<<"Preprocessing successful"<<std::endl;


    //////////////////User-Interface/////////////////////////
        if (std::string(argv[3]) == "--interactive" || std::string(argv[3]) == "-i") {
            bool exit = false;
            while(!exit){
                std::cout<<"What would you like to do?"<<std::endl;
                std::cout<<"1) See full graph"<<std::endl;
                std::cout<<"2) Clear Screen"<<std::endl;
                //Add more options here
                std::cout<<"Type the corresponding number to the desired option or anything else to exit"<<std::endl;
                int option;
                std::cin>>option;
                if(option==1){
                    pGraph.displayGraph();
                }else if(option==2){
                    system("clear");
                }else{
                    exit = true;
                }
            }
        }
    }
    //////////////////////////////////////

    return 0;
};
