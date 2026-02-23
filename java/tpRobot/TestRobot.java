public class TestRobot {
    public static void main(String[] args) throws Exception {
        try {
            Monde m = new Monde(3, 3);
            m.metPapierGras(1, 2);
            m.prendPapierGras(3, 1);
            System.out.println(m.toString());

            System.out.println(m.estSale(1, 2) ? "true" : "false");
            System.out.println("nbr de gras " + m.nbPapierGras());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
