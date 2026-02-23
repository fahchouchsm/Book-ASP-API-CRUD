public abstract class RobotPolleur extends Robot {

    public RobotPolleur(Monde m) {
        super(m);
    }

    public RobotPolleur(int posx, int posy, Monde m) {
        super(posx, posy, m);
    }

    public void polluer() {
        getMonde().metPapierGras(getPosy(), getPosx());
    }
}
