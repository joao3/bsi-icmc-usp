package graph;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractGraph implements GraphInterface {
    /*
    protected static final int GRAPHVIZ_IMAGE_WIDTH = 800;
    protected static final String GRAPHVIZ_FOLDER = "graphImgs/";
    protected static final String GRAPHVIZ_FILE_EXTENSION = ".svg";
     */

    private int numberOfVertices;
    private List<Vertex> vertices;

    public AbstractGraph() {
        this.setVertices(new ArrayList<>());
        this.setNumberOfVertices(vertices.size());
    }

    public int getNumberOfVertices() {
        return numberOfVertices;
    }

    public void setNumberOfVertices(int numberOfVertices) {
        this.numberOfVertices = numberOfVertices;
    }

    public List<Vertex> getVertices() {
        return vertices;
    }

    public void setVertices(List<Vertex> vertices) {
        this.vertices = vertices;
    }

    @Override
    public void addVertex(Vertex vertex) {
        vertices.add(vertex);
        numberOfVertices++;
    }

    @Override
    public void removeVertex(Vertex vertex) {

    }
}