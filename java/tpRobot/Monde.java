public class Monde {
    private int nbl, nbc;
    private boolean[][] mat; // declation dune matrice

    public Monde() {
        nbc = 10;
        nbl = 10;
        mat = new boolean[10][10];
        initMonde();
    }

    public int getNbl() {
        return nbl;
    }

    public int getNbc() {
        return nbc;
    }

    public Monde(int nbl, int nbc) {
        this.nbl = nbl;
        this.nbc = nbc;
        mat = new boolean[nbl][nbc]; // initialisation dune mat
        initMonde();
    }

    private void initMonde() {
        for (int i = 0; i < nbl; i++) {
            for (int j = 0; j < nbc; j++) {
                mat[i][j] = false;
            }
        }
    }

    public String toString() {
        String c = "";
        for (int i = 0; i < nbl; i++) {
            for (int j = 0; j < nbc; j++) {
                if (mat[i][j]) {
                    c += "o";
                } else {
                    c += ".";
                }
                c += "\t"; // 4 espace
            }
            c += "\n";
        }

        return c;
    }

    public void metPapierGras(int i, int j) {
        mat[i - 1][j - 1] = true;

    }

    public void prendPapierGras(int i, int j) {
        mat[i - 1][j - 1] = false;
    }

    public boolean estSale(int i, int j) {
        return mat[i][j];
    }

    public int nbPapierGras() {
        int count = 0;
        for (int i = 0; i < nbl; i++) {
            for (int j = 0; j < nbc; j++) {
                if (mat[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }

}