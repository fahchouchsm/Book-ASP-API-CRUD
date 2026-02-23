public class ProducteurPrime extends Producteur implements Iprime, I2prime {

    public ProducteurPrime(double nbu) {
        super(nbu);
    }

    public double calcSalaire() {
        return super.calcSalaire() + prime;
    }

    public void x() {
        Iprime.x();
        I2prime.x();
    }
}