public class Compte {
    private double solde;
    private int numC;
    private int prop;
    private boolean estBloq;
    private double montantBloq;

    public Compte(int numC, double solde, int prop) {
        this.numC = numC;
        this.solde = solde;
        this.prop = prop;
    }

    public Compte(Compte c) {
        c.numC = numC;
        c.solde = solde;
        c.prop = prop;
    }

    public void affiche() {
        System.out.println("Numero de compte: " + numC + " ,proprietaire: " + prop + " ,solde: " + solde);
    }

    public void verserArgent(double somme) {
        if (somme < 0) {
            System.out.println("La somme est negative");
            return;
        }
        solde += somme;
    }

    //
    public void retirerArgent(double montant) {
        if (estBloq()) {
            return;
        } else if (montant > solde - montantBloq) {
            System.out.println("Le solde est bloq d'un montant de " + montantBloq + " MAD");
        } else if (montant < solde) {
            System.out.println("Solde insuffisant");
        } else {
            solde -= montant;
        }
    }

    public static void virment(Compte c1, Compte c2, double montant) {
        if (c1.estBloq()) {
            return;
        }
        c1.retirerArgent(montant);
        c2.verserArgent(montant);
    }

    public static boolean verifierSolde(Compte c1, Compte c2) {
        return c1.solde == c2.solde;
    }

    public void bloquerCompte() {
        estBloq = true;
    }

    public boolean estBloq() {
        if (estBloq) {
            System.out.println("impossible defectuer cette operation le compte est bloquer");
            return true;
        }
        return false;
    }

    //
    public void bloqMontant(double montant) {
        montantBloq = montant;
    }
}