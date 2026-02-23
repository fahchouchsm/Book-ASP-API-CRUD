public class PolleurToutDroit extends RobotPolleur {
    private int colDepart;

    public PolleurToutDroit(Monde m, int colDepart) {
        super(m);
        this.colDepart = colDepart;
    }

    public PolleurToutDroit(int posx, int posy, Monde m, int colDepart) {
        super(posx, posy, m);
        this.colDepart = colDepart;
    }

    @Override
    public void parcourir() {

        for (int i = 1; i <= getMonde().getNbl(); i++) {
            vaEn(i, colDepart);
            polluer();
        }
    }

}
