package graph;

import graph.AbstractGraph;

public class Eccentricity {
    private AbstractGraph graph;
    private double[][] distancesMatrix;

    public Eccentricity(AbstractGraph graph, double[][] distancesMatrix) {
        this.graph = graph;
        this.distancesMatrix = distancesMatrix;
    }

    public double getVertexEccentricity(Vertex vertex) {
        int vertexIndex = graph.getVertices().indexOf(vertex);
        double eccentricity = 0;
        boolean foundTheFirst = false;
        for (int i = 0; i < graph.getNumberOfVertices(); i++) {
            if (i != vertexIndex) {
                if (distancesMatrix[i][vertexIndex] > eccentricity || !foundTheFirst) {
                    eccentricity = distancesMatrix[i][vertexIndex];
                    foundTheFirst = true;
                }
            }
        }
        return eccentricity;
    }

    public Vertex centralVertex() {
        Vertex centralVertex = null;
        double minimumEccentricity = Double.POSITIVE_INFINITY;
        for (Vertex currentVertex : graph.getVertices()) {
            double currentVertexEccentricity = getVertexEccentricity(currentVertex);
            if (currentVertexEccentricity < minimumEccentricity) {
                centralVertex = currentVertex;
                minimumEccentricity = currentVertexEccentricity;
            }
        }
        return centralVertex;
    }

    public Vertex peripheralVertex() {
        Vertex peripheralVertex = null;
        double maximumEccentricity = Double.NEGATIVE_INFINITY;
        for (Vertex currentVertex : graph.getVertices()) {
            double currentVertexEccentricity = getVertexEccentricity(currentVertex);
            if (currentVertexEccentricity > maximumEccentricity) {
                peripheralVertex = currentVertex;
                maximumEccentricity = currentVertexEccentricity;
            }
        }
        return peripheralVertex;
    }

    public Vertex furthestVertex(Vertex source) {
        int sourceVertexIndex = graph.getVertices().indexOf(source);
        Vertex furthestVertex = null;
        double maximumDistance = Double.NEGATIVE_INFINITY;
        for (int i = 0; i < graph.getNumberOfVertices(); i++) {
            if (distancesMatrix[sourceVertexIndex][i] > maximumDistance) {
                maximumDistance = distancesMatrix[sourceVertexIndex][i];
                furthestVertex = graph.getVertices().get(i);
            }
        }
        return furthestVertex;
    }
}
