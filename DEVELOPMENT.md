# Development

## Week 1 (Up to Nov. 19th)

In the first week, we established our goals to work on the BFS traversal and the A* Search, and Landmark Path algorithms.
We all met several times over break, and discussed various aspects of the project, including the project structure, the underlying data structure for the graph, and the desired API of the data structure.
We first had an implementation that used pointers to keep track of various vertices.
However, because of concerns about memory management and readability and bad pointer usage, we then began work on implementing all pointer-like operations with iterators to STL containers instead.
While memory management would no longer be an issue, a problem that we faced was readability and usage -- while STL is "safer" than pointers, pointers are easier to reason about than STL containers and iterators.
Simultaneously, when some of our group members tried to work on A*, we realized that this algorithm did not make sense for our dataset (since we have no heuristic), and we met again to decide to switch to **_Dijkstra's Algorithm_** instead.
By Nov. 29th, we had a Graph data structure with a clean API that we can now use for algorithms. This GraphADT data structure also has its own tests where each group memeber contributed for atleast one test. 
