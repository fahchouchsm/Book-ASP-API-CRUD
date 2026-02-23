public abstract class Robot {
    private int posx, posy;
    private Monde m;

    public Robot(int posx, int posy, Monde m) {
        this.posx = posx;
        this.posy = posy;
        this.m = m;
    }

    public Robot(Monde m) {
        this.m = m;
        posx = (int) (Math.random() * m.getNbc() + 1);
        posy = (int) (Math.random() * m.getNbl() + 1);
    }

    public void vaEn(int i, int j) {
        posx = i;
        posy = j;
    }

    public int getPosx() {
        return posx;
    }

    public int getPosy() {
        return posy;
    }

    public Monde getMonde() {
        return m;
    }

    public abstract void parcourir();

}
