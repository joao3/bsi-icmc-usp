package graph;

public interface GraphInterface {
    void addVertex(Vertex vertex);
    void removeVertex(Vertex vertex);

    void addEdge(Vertex source, Vertex destination, int weight);
    void addEdge(Vertex source, Vertex destination);
    void removeEdge(Vertex source, Vertex destination);

    boolean edgeExists(Vertex source, Vertex destination);

    boolean hasAnyEdge(Vertex vertex);

    int getFirstConnectedVertexIndex(Vertex vertex);
    int getNextConnectedVertexIndex(Vertex vertex, int currentEdge);
    Vertex getFirstConnectedVertex(Vertex vertex);
    Vertex getNextConnectedVertex(Vertex source, Vertex currentConnection);

    float getDistance(Vertex source, Vertex destination);

    String toString();
    //void printInGraphviz(String fileName);
}
