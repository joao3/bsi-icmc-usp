import graph.AbstractGraph;
import graph.Vertex;
import quest.Quest;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Input {
    private Scanner in;
    private AbstractGraph graph;
    private Map<Integer, Vertex> idVertexMap; // [Id:Vertex] usado para facilitar inserção de aresta

    public Input(AbstractGraph graph) {
        this.in = new Scanner(System.in);
        this.graph = graph;
        idVertexMap = new HashMap<>();
    }

    // Le e insere vertices, le e insere arestas, retorna vertice para começar a busca
    public Vertex readInput() {
        int numberOfVertices = in.nextInt();
        in.nextLine();
        readVertices(numberOfVertices);

        int numberOfEdges = in.nextInt();
        in.nextLine();
        readEdges(numberOfEdges);

        int startQuestId = in.nextInt();
        return idVertexMap.get(startQuestId);
    }

    private void readVertices(int numberOfVertices) {
        for (int i = 0; i < numberOfVertices; i++) {
            String name = in.nextLine();
            String description = in.nextLine();

            Vertex newVertex = new Vertex(new Quest(name, description, i));
            idVertexMap.put(i, newVertex);
            graph.addVertex(newVertex);
        }
    }

    private void readEdges(int numberOfEdges) {
        for (int i = 0; i < numberOfEdges; i++) {
            int sourceId = in.nextInt();
            int destinationId = in.nextInt();
            graph.addEdge(idVertexMap.get(sourceId), idVertexMap.get(destinationId));
        }
    }
}
