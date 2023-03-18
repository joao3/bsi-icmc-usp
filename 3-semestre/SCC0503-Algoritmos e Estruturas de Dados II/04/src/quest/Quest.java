package quest;

import graph.Data;

public class Quest implements Data {
    private String name;
    private String description;
    private int id;

    public Quest(String name, String description, int id) {
        this.name = name;
        this.description = description;
        this.id = id;
    }

    @Override
    public String stringToGraphviz() {
        return  String.valueOf(id) + " : " + name;
    }

    @Override
    public String stringToTerminal() {
        return "Quest{\n\tID= '" + id + "'\n\tname= '" + name + "'\n\tdescription= '" + description + "'\n}\n";
    }
}
