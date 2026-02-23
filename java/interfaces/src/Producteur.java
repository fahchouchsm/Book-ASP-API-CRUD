public class Producteur {
    private double nbu;

    public Producteur(double nbu) {
        this.nbu = nbu;
    }

    public double calcSalaire() {
        return nbu * 10;
    }

}
