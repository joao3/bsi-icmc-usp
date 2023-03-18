import graph.Data;

import java.util.Objects;

public class Point implements Data {
    private final double x;
    private final double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public static double euclideanDistance(Point p1, Point p2) {
        double squareDistance = Math.pow((p1.x - p2.x), 2) + Math.pow((p1.y - p2.y), 2);
        return Math.sqrt(squareDistance);
    }

    @Override
    public String stringToGraphviz() {
        return "(" + x + ", " + y + ")";
    }

    @Override
    public String stringToTerminal() {
        return stringToGraphviz();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Point point = (Point) o;
        return Double.compare(point.x, x) == 0 && Double.compare(point.y, y) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
