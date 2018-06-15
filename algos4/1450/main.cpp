/**
    Algorithms. Module 4.
    http://acm.timus.ru/problem.aspx?space=1&num=1450
    @date June 15, 2018
    @author maanti
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int start;
    int end;
    int weight;
};

struct Graph {
    int verticesNumber, edgesNumber, firstStation, lastStation;
    struct Edge *edges;
};

/**
 * Reads number of vertices, number and direction of edges,
 * first and last station numbers from stdin and creates a
 * Graph structure.
 *
 * @return Graph structure instance
*/
struct Graph *createGraph();

/**
 * Implements Bellman-Ford algorithm to find a path with
 * the maximum weight in the graph.
 *
 * @param graph where the search will be performed
 * @return maximum weight
*/
int bellmanFord(struct Graph *graph);

int main() {
    int result = bellmanFord(createGraph());
    if (result == INT_MAX)
        printf("%s", "No solution");
    else
        printf("%d", result);
    return 0;
}

int bellmanFord(struct Graph *graph) {
    int weights[graph->verticesNumber];
    /**
     * Initializes distances with "Infinity".
     * Uses INT_MAX because integers are inherently finite
     * and INT_MAX is the closest to infinity value we can get.
     * Sets distance to the firstStation to zero.
     */
    for (int i = 0; i < graph->verticesNumber; i++)
        weights[i] = INT_MAX;
    weights[graph->firstStation] = 0;
    /**
     * For every vertex's edge new distance is computed
     * while there was at least one edge relaxation.
     * For unreachable vertices distance will remain equal to
     * INT_MAX.
     */
    bool relaxationHappened = false;
    for (int i = 1; i < graph->verticesNumber; i++) {
        for (int j = 0; j < graph->edgesNumber; j++) {
            int fromStation = graph->edges[j].start;
            int toStation = graph->edges[j].end;
            int weight = graph->edges[j].weight;
            if (weights[fromStation] != INT_MAX &&
                weights[fromStation] + weight < weights[toStation]) {
                weights[toStation] = weights[fromStation] + weight;
                relaxationHappened = true;
            }
        }
        if (!relaxationHappened) {
            break;
        }
    }
    return abs(weights[graph->lastStation]);
}

struct Graph *createGraph() {
    auto *graph = new Graph;
    scanf("%d %d", &graph->verticesNumber, &graph->edgesNumber);
    graph->edges = new Edge[graph->edgesNumber];
    for (int i = 0; i < graph->edgesNumber; i++) {
        scanf("%d %d %d", &graph->edges[i].start, &graph->edges[i].end,
              &graph->edges[i].weight);
        graph->edges[i].start--;
        graph->edges[i].end--;
        graph->edges[i].weight = -graph->edges[i].weight;
    }
    scanf("%d %d", &graph->firstStation, &graph->lastStation);
    graph->firstStation--;
    graph->lastStation--;
    return graph;
}
