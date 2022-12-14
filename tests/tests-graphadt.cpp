#include <string>
#include <vector>
#include <iostream>

#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "BFS.h"
#include "FullBFS.h"
#include "SCCGraph.h"
#include "Mock.h"

#include "catch.hpp"



TEST_CASE("An empty edge is equivalent to all other empty edges", "[graphadt]") {
    Edge e;
    REQUIRE(e.isEmpty() == true);
    REQUIRE(Edge(-1, -1).isEmpty() == true);
}

TEST_CASE("We are able to retrieve the node_id using the name of the vertex.", "[graphadt]") {
    Graph g;insertBasicCycle(g, 0);
    Vertex v0(0, "0");
    REQUIRE(g.page_to_id.at("0") == 0);
}

TEST_CASE("Verify that vertices and edges are properly inserted", "[graphadt]") {
	Graph g;
    insertBasicCycle(g, 0);

	REQUIRE(g.num_vertices == 4);
	REQUIRE(g.num_edges == 4);
}

TEST_CASE("Verify that edgeExists queries work","[graphadt]") {
	Vertex v0 = Vertex(0, "0");
    Vertex v1 = Vertex(1, "1");
    Vertex v2 = Vertex(2, "2");
    Vertex v3 = Vertex(3, "3");
    Graph g;
    insertBasicCycle(g, 0);

	REQUIRE(g.edgeExists(v0, v1) == true);
	REQUIRE(g.edgeExists(v1, v1) == false);
	REQUIRE(g.edgeExists(v2, v3) == true);
}

TEST_CASE("Verify that vertexExists queries work", "[graphadt]") {
	Vertex v0 = Vertex(0, "0");
    Vertex v1 = Vertex(1, "1");
    Vertex v2 = Vertex(25, "anything");
    Graph g;
    insertBasicCycle(g, 0);

	REQUIRE(g.vertexExists(v0) == true);
	REQUIRE(g.vertexExists(v1) == true);
	REQUIRE(g.vertexExists(v2) == false);
}

TEST_CASE("Demonstrate how to use the incidentEdges and incidentVertices function.", "[graphadt]") {
    Graph g;
    insertBasicCycle(g, 0);
	Vertex v0 = Vertex(0, "0");
	for (auto& it : g.incidentEdges(v0)) {
        Edge incidentEdge = it; 
	}
    for(auto& it : g.incidentVertices(v0)){
        Vertex incidentVertex = it;
    }
	REQUIRE(true);
}

TEST_CASE("Verify that removeEdge function work as expected.", "[graphadt]"){
    Graph g;
    insertBasicCycle(g, 0);
    Vertex v0(0, "0");
    Vertex v1(1, "1");

    g.removeEdge(v0, v1);

    REQUIRE(g.num_edges == 3);
    REQUIRE(g.edgeExists(v0, v1) == false);

    g.removeEdge(v0, v1);       // this should not remove anything
    REQUIRE(g.num_edges == 3);  // num_edges should remain same for non-existent edge
}

TEST_CASE("Verify that removeVertex function work as expected.", "[graphadt]"){
    Graph g;
    insertBasicCycle(g, 0);
    Vertex v0(0, "0");

    g.removeVertex(v0);

    REQUIRE(g.num_vertices == 3);           // function should remove the Vertex
    REQUIRE(g.vertexExists(v0) == false);
    REQUIRE(g.num_edges == 2);              // function should remove all the vertex's Edges
}


