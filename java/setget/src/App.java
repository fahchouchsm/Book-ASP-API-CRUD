public class App {
    public static void main(String[] args) throws Exception {
        Prof p = new Prof("f14", "hamid lamba", 30);
        p.afficher();
        p.setCin("F15");
        System.out.println(p.getCin());
    }
}
