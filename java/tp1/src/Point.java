public class Point {
    private double x;
    private double y;
    private String nom;

    public Point(double x, double y, String nom) {
        this.nom = nom;
        this.x = x;
        this.y = y;
    }

    public void afficher() {
        System.out.println(nom + "(" + x + ", " + y + ")");
    }

    public void modifier(double changx, double changy) {
        x = changx;
        y = changy;
    }

    public void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }

    public void initial() {
        x = 0;
        y = 0;
    }

    public static boolean verif(Point p1, Point p2) {
        if (p1.x == p2.x && p1.y == p2.y) {
            return true;
        }
        return false;
    }

    public boolean verif(Point p) {
        if (p.x == x && p.y == y) {
            return true;
        }
        return false;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

}
