public class Etudiant {
    private String nom;
    private double moy = 0;
    private double[] notesModule = new double[4];

    public Etudiant(String nom) {
        this.nom = nom;
    }

    public String getNom() {
        return nom;
    }

    public double getMoy() {
        return moy;
    }

    public void setMoy(double moy) {
        if (moy >= 0 && moy <= 20) {
            this.moy = moy;
        } else {
            System.out.println("error");
        }
    }

    public void setNotes(double[] notes) {
        double some = 0;
        for (int i = 0; i < 4; i++) {
            notesModule[i] = notes[i];
            some += notes[i];
        }
        this.moy = some / 4;
    }

}
