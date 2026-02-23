public class Prof {
    private String cin;
    public String nom;

    public Prof(String cin, String nom) {
        this.cin = cin;
        this.nom = nom;
    }

    public String getCin() {
        return cin;
    }

    public void afficher() {
        System.out.println("cin =" + cin + " nom " + nom);
    }

    public void setCin(String cin) {
        this.cin = cin;
    }

}