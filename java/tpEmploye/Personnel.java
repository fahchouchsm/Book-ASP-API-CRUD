public class Personnel {
    protected Employe[] tabEmployes;
    protected int nbEmployes;
    protected final int capaciteMax = 200;

    public Personnel(int capaciteMax) {
        this.tabEmployes = new Employe[capaciteMax];
        this.nbEmployes = 0;
    }

    public void ajouterEmploye(Employe employe) {
        if (nbEmployes < capaciteMax) {
            tabEmployes[nbEmployes] = employe;
            nbEmployes++;
        } else {
            System.out.println("Capacité maximale atteinte.");
        }
    }

    public void afficherEmployes() {
        for (int i = 0; i < nbEmployes; i++) {
            System.out.println("Nom: " + tabEmployes[i].getNom() + ", Prénom: " + tabEmployes[i].getPrenom() +
                    ", Age: " + tabEmployes[i].getAge() + ", Poste: " + tabEmployes[i].getPoste() +
                    ", Salaire: " + tabEmployes[i].getSalaire());
        }
    }

    public void supprimerEmploye(String nom) {
        for (int i = 0; i < nbEmployes; i++) {
            if (tabEmployes[i].getNom().equals(nom)) {
                for (int j = i; j < nbEmployes - 1; j++) {
                    tabEmployes[j] = tabEmployes[j + 1];
                }
                tabEmployes[nbEmployes - 1] = null;
                nbEmployes--;
                return;
            }
        }
        System.out.println("Employé non trouvé.");
    }

}
