public class PolleurSauteur extends RobotPolleur {
    private int deltax;

    public PolleurSauteur(Monde m, int deltax) {
        super(m);
        this.deltax = deltax;
    }

    public PolleurSauteur(int posx, int posy, Monde m, int deltax) {
        super(posx, posy, m);
        this.deltax = deltax;
    }
}
