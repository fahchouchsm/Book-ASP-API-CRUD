public class App {
    public static void main(String[] args) throws Exception {
        Point point = new Point(10.0, 20.0, "Rectangle");
        point.afficher();
        point.modifier(15.0, 25.0);
        point.afficher();
        point.deplacer(5.0, 5.0);
        point.afficher();
        Point point2 = new Point(20.0, 30.0, "fn");
        System.out.println(Point.verif(point, point2));
    }
}
