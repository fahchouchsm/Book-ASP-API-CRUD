public class Employe {

    private String nom;
    private String prenom;
    private int age;
    private String poste;
    private double salaire;

    public Employe(String nom, String prenom, int age, String poste, double salaire) {
        this.nom = nom;
        this.prenom = prenom;
        this.age = age;
        this.poste = poste;
        this.salaire = salaire;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getPoste() {
        return poste;
    }

    public void setPoste(String poste) {
        this.poste = poste;
    }

    public double getSalaire() {
        return salaire;
    }

    public void setSalaire(double salaire) {
        this.salaire = salaire;
    }
}