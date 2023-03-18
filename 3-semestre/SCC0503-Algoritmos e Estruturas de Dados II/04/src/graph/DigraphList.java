package graph;

/*
import guru.nidi.graphviz.engine.Format;
import guru.nidi.graphviz.engine.Graphviz;
import guru.nidi.graphviz.model.MutableGraph;
 */

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/*
import static guru.nidi.graphviz.model.Factory.mutGraph;
import static guru.nidi.graphviz.model.Factory.mutNode;
*/

public class DigraphList extends AbstractGraph{
    List<List<Edge>> adjacencyList;

    public DigraphList() {
        super();
        setAdjacencyList(new ArrayList<>());
    }

    public List<List<Edge>> getAdjacencyList() {
        return adjacencyList;
    }

    public void setAdjacencyList(List<List<Edge>> adjacencyList) {
        this.adjacencyList = adjacencyList;
    }

    @Override
    public void addVertex(Vertex vertex) {
        super.addVertex(vertex);
        adjacencyList.add(new ArrayList<>());
    }

    @Override
    public void addEdge(Vertex source, Vertex destination, int weight) {
        if (!edgeExists(source, destination)) {
            int sourceIndex = getVertices().indexOf(source);
            getAdjacencyList().get(sourceIndex).add(new Edge(destination, weight));
        }
    }

    @Override
    public void addEdge(Vertex source, Vertex destination) {
        if (!edgeExists(source, destination)) {
            int sourceIndex = getVertices().indexOf(source);
            getAdjacencyList().get(sourceIndex).add(new Edge(destination));
        }
    }

    @Override
    public void removeEdge(Vertex source, Vertex destination) {
        if (edgeExists(source, destination)) {
            int sourceIndex = getVertices().indexOf(source);
            List<Edge> sourceEdges = getAdjacencyList().get(sourceIndex);
            for (int i = 0; i < sourceEdges.size(); i++) {
                if (sourceEdges.get(i).getDestination() == destination) {
                    sourceEdges.remove(sourceEdges.get(i));
                }
            }
        }
    }

    @Override
    public boolean edgeExists(Vertex source, Vertex destination) {
        int sourceIndex = getVertices().indexOf(source);
        List<Edge> sourceEdges = getAdjacencyList().get(sourceIndex);
        for (Edge edge : sourceEdges) {
            if (edge.getDestination() == destination) {
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean hasAnyEdge(Vertex vertex) {
        int vertexIndex = getVertices().indexOf(vertex);

        // Verifica se há alguma aresta saindo do vértice
        if (!getAdjacencyList().get(vertexIndex).isEmpty()) {
            return true;
        }

        // Verifica se há alguma aresta chegando no vértice
        for (int i = 0; i < getNumberOfVertices(); i++) {
            for (Edge edge : getAdjacencyList().get(i)) {
                if (edge.getDestination() == vertex) {
                    return true;
                }
            }
        }

        return false;
    }

    @Override
    public int getFirstConnectedVertexIndex(Vertex vertex) {
        int vertexIndex = getVertices().indexOf(vertex);
        List<Edge> vertexEdges = getAdjacencyList().get(vertexIndex);
        if (vertexEdges.isEmpty()) {
            return -1;
        } else {
            Vertex destinationVertex = vertexEdges.get(0).getDestination();
            return getVertices().indexOf(destinationVertex);
        }
    }

    @Override
    public int getNextConnectedVertexIndex(Vertex vertex, int currentConnectedVertexIndex) {
        int vertexIndex = getVertices().indexOf(vertex);
        List<Edge> vertexEdges = getAdjacencyList().get(vertexIndex);
        Vertex currentConnectedVertex = getVertices().get(currentConnectedVertexIndex);

        int currentEdgeIndex = 0;
        while (vertexEdges.get(currentEdgeIndex).getDestination() != currentConnectedVertex) {
            currentEdgeIndex++;
        }
        currentEdgeIndex++;

        if (vertexEdges.size() > currentEdgeIndex) {
            return getVertices().indexOf(vertexEdges.get(currentEdgeIndex).getDestination());
        }

        return -1;
    }

    @Override
    public Vertex getFirstConnectedVertex(Vertex vertex) {
        int vertexIndex = getVertices().indexOf(vertex);
        if (getAdjacencyList().get(vertexIndex).isEmpty()) {
            return null;
        }
        return getAdjacencyList().get(vertexIndex).get(0).getDestination();
    }

    @Override
    public Vertex getNextConnectedVertex(Vertex source, Vertex currentConnection) {
        int vertexIndex = getVertices().indexOf(source);
        List<Edge> vertexEdges = getAdjacencyList().get(vertexIndex);

        // Busca o índice do vértice que leva até a conexão atual
        int currentEdgeIndex = 0;
        while (vertexEdges.get(currentEdgeIndex).getDestination() != currentConnection) {
            currentEdgeIndex++;
        }
        // O índice do próxima conexão será o do atual + 1
        currentEdgeIndex++;

        if (vertexEdges.size() > currentEdgeIndex) {
            return vertexEdges.get(currentEdgeIndex).getDestination();
        }
        return null;
    }

    @Override
    public float getDistance(Vertex source, Vertex destination) {
        int vertexIndex = getVertices().indexOf(source);
        for (Edge edge : getAdjacencyList().get(vertexIndex)) {
            if (edge.getDestination() == destination) {
                return edge.getWeight();
            }
        }

        return -1;
    }

    /*
    @Override
    public void printInGraphviz(String fileName) {
        MutableGraph g = mutGraph("example1Digraph").setDirected(true);

        for (int i = 0; i < getNumberOfVertices(); i++) {
            for (int j = 0; j < getAdjacencyList().get(i).size(); ++j) {
                int destinationIndex = getVertices().indexOf(getAdjacencyList().get(i).get(j).getDestination());
                g.add(mutNode(getVertices().get(i).getData().stringToGraphviz()).addLink(getVertices().get(destinationIndex).getData().stringToGraphviz()));
            }
        }
        try {
            Graphviz.fromGraph(g).width(GRAPHVIZ_IMAGE_WIDTH).render(Format.SVG).toFile(new File(GRAPHVIZ_FOLDER+fileName+GRAPHVIZ_FILE_EXTENSION));
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
     */
}
