package graph;

public class DepthFirstTraversal extends TraversalStrategy {
    public DepthFirstTraversal(AbstractGraph graph) {
        super(graph);
    }

    @Override
    void traverseGraph(Vertex source, Vertex destination) {

    }

    @Override
    public void traverseGraph(Vertex source) {
        traverseGraphRecursion(source);
    }

    public void traverseGraphRecursion(Vertex currentVisitedVertex) {
        int currentVisitedVertexIndex = getGraph().getVertices().indexOf(currentVisitedVertex);
        addToPath(currentVisitedVertex);
        markVertexAsVisited(currentVisitedVertexIndex);

        Vertex currentAdjacentVertex = getGraph().getFirstConnectedVertex(currentVisitedVertex);
        while (currentAdjacentVertex != null) {
            int currentAdjacentVertexIndex = getGraph().getVertices().indexOf(currentAdjacentVertex);
            if (!hasVertexBeenVisited(currentAdjacentVertexIndex)) {
                traverseGraphRecursion(currentAdjacentVertex);
                setPredecessorVertexIndex(currentAdjacentVertexIndex, currentVisitedVertexIndex);
            }
            currentAdjacentVertex = getGraph().getNextConnectedVertex(currentVisitedVertex, currentAdjacentVertex);
        }
    }
}
