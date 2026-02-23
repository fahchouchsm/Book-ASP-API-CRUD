import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("entrer le nombre des etudiant");
        int n = sc.nextInt();
        Etudiant[] tab = new Etudiant[n];
        for (int i = 0; i < n; i++) {
            System.out.println("entrer le nom d'etudiant");
            String nom = sc.nextLine();
            tab[i] = new Etudiant(nom);
        }
        for (int i = 0; i < n; i++) {
            System.out.println("entrer la moyenne de " + tab[i].getNom());
            double moy = sc.nextDouble();
            tab[i].setMoy(moy);
        }

        sc.close();
    }
}
