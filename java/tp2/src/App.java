public class App {
    public static void main(String[] args) throws Exception {
        Compte c1 = new Compte(1, 10000, 1);

        c1.affiche();
        c1.bloqMontant(11000);
        c1.retirerArgent(10);
    }
}
