package ma.ehei.gi4;

public class Etudiant {
  private String nom;
  private String prenom;

  public Etudiant(String nom, String prenom) {
    this.nom = nom;
    this.prenom = prenom;
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

  public String toString() {
      return "le nom est " + nom + " le prenom est " + prenom;
  }

}
