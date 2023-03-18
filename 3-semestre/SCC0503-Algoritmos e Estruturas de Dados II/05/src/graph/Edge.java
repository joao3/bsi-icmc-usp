package graph;

public class Edge {
    private Vertex destination;
    private double weight;

    public Edge(Vertex destination, double weight) {
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

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}
