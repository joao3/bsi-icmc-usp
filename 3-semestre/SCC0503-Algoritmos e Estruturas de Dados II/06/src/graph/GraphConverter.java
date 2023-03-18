package graph;

public class GraphConverter {
    public static AbstractGraph predecessorListToGraph(AbstractGraph dungeon, int[] predecessorArray) {
        try {
            AbstractGraph newDungeon = dungeon.clone();

            newDungeon.removeAllEdges();
            for (int i = 0;  i < dungeon.getNumberOfVertices(); i++) {
                int predecessorIndex = predecessorArray[i];
                if (predecessorIndex != -1) {
                    Vertex source = dungeon.getVertices().get(predecessorIndex);
                    Vertex destination = dungeon.getVertices().get(i);
                    float weight = dungeon.getEdge(source, destination).getWeight();
                    newDungeon.addEdge(source, destination, weight);
                }
            }
            return newDungeon;
        }
        catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return null;
    }
}
