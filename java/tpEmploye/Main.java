public class Main {
    public static void main(String[] args) {
        Personnel personnel = new Personnel(5);
        Employe employe1 = new Employe("Dupont", "Jean", 30, "Développeur", 3000);
        Employe employe2 = new Employe("Martin", "Sophie", 28, "Designer", 2800);
        Employe employe3 = new Employe("Durand", "Pierre", 35, "Manager", 4000);

        personnel.ajouterEmploye(employe1);
        personnel.ajouterEmploye(employe2);
        personnel.ajouterEmploye(employe3);

        System.out.println("Liste des employés :");
        personnel.afficherEmployes();

        personnel.supprimerEmploye("Martin");
        System.out.println("\nListe des employés après suppression :");
        personnel.afficherEmployes();
    }
}
