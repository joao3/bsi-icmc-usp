import graph.AbstractGraph;
import graph.DigraphList;
import graph.Vertex;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Input {
    private final Scanner in;
    private final AbstractGraph graph;
    private final Map<Point, Vertex> pointVertexMap; // [Point:Vertex] usado para facilitar inserção de aresta

    public Input(AbstractGraph graph) {
        this.in = new Scanner(System.in);
        this.graph = graph;
        pointVertexMap = new HashMap<>();
    }

    public void readInput() {
        int numberOfVertices = in.nextInt();
        in.nextLine();
        readVertices(numberOfVertices);

        int numberOfEdges = in.nextInt();
        in.nextLine();
        readEdges(numberOfEdges);
    }

    private void readVertices(int numberOfVertices) {
        for (int i = 0; i < numberOfVertices; i++) {
            String line = in.nextLine();
            Point point = splitPoint(line);
            Vertex newVertex = new Vertex(point);
            pointVertexMap.put(point, newVertex);
            graph.addVertex(newVertex);
        }
    }

    private void readEdges(int numberOfEdges) {
        for (int i = 0; i < numberOfEdges; i++) {
            String line = in.nextLine();
            String[] pointsString = splitConnection(line);
            Point pointA = splitPoint(pointsString[0]);
            Point pointB = splitPoint(pointsString[1]);
            graph.addEdge(pointVertexMap.get(pointA), pointVertexMap.get(pointB),
                    Point.euclideanDistance(pointA, pointB));
        }
    }

    private Point splitPoint(String line) {
        String[] coordinates = line.split(",");

        return new Point(Double.parseDouble(coordinates[0]), Double.parseDouble(coordinates[1]));
    }

    private String[] splitConnection(String line) {
        return line.split(":");
    }
}

