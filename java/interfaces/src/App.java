public class App {
    public static void main(String[] args) throws Exception {

        // Producteur p = new Producteur(100);
        // System.out.println(p.calcSalaire());
        ProducteurPrime pPrime = new ProducteurPrime(50);
        System.out.println(pPrime.calcSalaire());
        pPrime.x();
    }
}
