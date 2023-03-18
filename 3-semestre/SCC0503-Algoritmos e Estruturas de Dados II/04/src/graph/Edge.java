package graph;

public class Edge {
    private Vertex destination;
    private int weight;

    public Edge(Vertex destination, int weight) {
        setDestination(destination);
        setWeight(weight);
    }

    public Edge(Vertex destination) {
        setDestination(destination);
        setWeight(1);
    }

    public Vertex getDestination() {
        return destination;
    }

    public void setDestination(Vertex destination) {
        this.destination = destination;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }
}
