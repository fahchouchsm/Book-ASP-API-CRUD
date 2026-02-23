public class PointRouge extends Point {
    PointRouge(double x, double y, String nom) {
        super(x, y, nom);
    }

    public void afficher() {
        System.out.println("Point Rouge: ");
        super.afficher();
    }
}
