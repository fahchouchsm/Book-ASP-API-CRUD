package runners;

public class Produit {
  private String code;
  public float prix;

  public Produit(String code, float prix) {
    this.code = code;
    this.prix = prix;
  }

  public String getCode() {
    return code;
  }

  public float getPrix() {
    return prix;
  }
}
