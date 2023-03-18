package graph;

public class Vertex {
    private Data data;

    public Vertex(Data data) {
        setData(data);
    }

    public Data getData() {
        return data;
    }

    public void setData(Data data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return data.stringToTerminal();
    }
}
