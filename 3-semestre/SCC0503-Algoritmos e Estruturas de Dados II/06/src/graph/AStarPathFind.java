package graph;

import java.util.*;
import java.util.List;

public class AStarPathFind extends TraversalStrategy {
    public AStarPathFind(AbstractGraph graph) {
        super(graph);
    }

    @Override
    void traverseGraph(Vertex source, Vertex destination) {
        // Distância real do vértice inicial até o vértice i + heurística do vértice i até o destino
        float[] distancesToDestination = new float[getGraph().getNumberOfVertices()];
        Arrays.fill(distancesToDestination, Float.POSITIVE_INFINITY);
        int sourceIndex = getGraph().getVertices().indexOf(source);
        distancesToDestination[sourceIndex] = euclideanDistance((Room) source, (Room) destination);
        setDistanceToVertex(sourceIndex, 0f);
        List<Vertex> verticesToVisit = new ArrayList<>();
        verticesToVisit.add(source);
        while (!verticesToVisit.isEmpty()) {
            Vertex currentVisitedVertex = getNextVertex(verticesToVisit, distancesToDestination);
            int currentVisitedVertexIndex = getGraph().getVertices().indexOf(currentVisitedVertex);
            addToPath(currentVisitedVertex);
            if (currentVisitedVertex == destination) {
                break;
            }
            verticesToVisit.remove(currentVisitedVertex);
            Vertex adjacentVertex = getGraph().getFirstConnectedVertex(currentVisitedVertex);
            while (adjacentVertex != null) {
                int adjacentVertexIndex = getGraph().getVertices().indexOf(adjacentVertex);
                float realDistance = getDistanceToVertex(currentVisitedVertexIndex) +
                        manhattanDistance((Room) currentVisitedVertex, (Room) adjacentVertex);
                if (realDistance < getDistanceToVertex(adjacentVertexIndex)) {
                    setPredecessorVertexIndex(adjacentVertexIndex, currentVisitedVertexIndex);
                    setDistanceToVertex(adjacentVertexIndex, realDistance);
                    distancesToDestination[adjacentVertexIndex] = realDistance +
                            euclideanDistance((Room) adjacentVertex, (Room) destination);
                    if (!verticesToVisit.contains(adjacentVertex)) {
                        verticesToVisit.add(adjacentVertex);
                    }
                }
                adjacentVertex = getGraph().getNextConnectedVertex(currentVisitedVertex, adjacentVertex);
            }
        }
        printPath();
    }

    private Vertex getNextVertex(List<Vertex> verticesToVisit, float[] distancesToDestination) {
        Vertex nextVertex = null;
        float currentGuess = Float.POSITIVE_INFINITY;
        for (Vertex currentVertex : verticesToVisit) {
            int currentVertexIndex = getGraph().getVertices().indexOf(currentVertex);
            if (distancesToDestination[currentVertexIndex] < currentGuess) {
                currentGuess = distancesToDestination[currentVertexIndex];
                nextVertex = currentVertex;
            }
        }

        return nextVertex;
    }

    @Override
    void traverseGraph(Vertex source) {

    }

    float euclideanDistance(Room source, Room destination) {
        double squaredDistance = Math.pow(source.getRoom().getX() - destination.getRoom().getX(), 2) +
                Math.pow(source.getRoom().getY() - destination.getRoom().getY(), 2);
        return (float) Math.sqrt(squaredDistance);
    }

    float manhattanDistance(Room source, Room destination) {
        return (float) Math.abs(source.getRoom().getX() - destination.getRoom().getX() +
                Math.abs(source.getRoom().getY() - destination.getRoom().getY()));
    }

}
