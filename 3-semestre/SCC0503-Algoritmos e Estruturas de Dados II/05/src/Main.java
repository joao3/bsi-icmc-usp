import graph.*;
//import org.apache.log4j.BasicConfigurator;

public class Main {
    public static void main(String[] args) {
        // Configura logger, para funcionamento do graphviz
        //BasicConfigurator.configure();

        AbstractGraph graph = new DigraphList();

        Input input = new Input(graph);
        input.readInput();

        FloydWarshallTraversal fwt = new FloydWarshallTraversal(graph);
        fwt.traverseGraph(graph.getVertices().get(0));

        Eccentricity eccentricity = new Eccentricity(graph, fwt.getDistanceMatrix());
        Vertex centralVertex = eccentricity.centralVertex();
        Vertex peripheralVertex = eccentricity.peripheralVertex();
        Vertex furthestFromPeripheralVertex = eccentricity.furthestVertex(peripheralVertex);

        System.out.println(centralVertex.getData().stringToTerminal());
        System.out.println(peripheralVertex.getData().stringToTerminal());
        System.out.println(furthestFromPeripheralVertex.getData().stringToTerminal());

        //graph.printInGraphviz("02");
    }
}