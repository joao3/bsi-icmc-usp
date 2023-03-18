import graph.*;
//import org.apache.log4j.BasicConfigurator;

public class Main {
    public static void main(String[] args) {
        // Configura logger, para funcionamento do graphviz
        //BasicConfigurator.configure();

        AbstractGraph graph = new DigraphList();

        // Leitura e inserção das quests no grafo
        Input input = new Input(graph);
        Vertex startVertex = input.readInput();

        // DFS
        TraversalStrategy dfs = new DepthFirstTraversal(graph);
        dfs.traverseGraph(startVertex);

        //graph.printInGraphviz("04");
    }
}
