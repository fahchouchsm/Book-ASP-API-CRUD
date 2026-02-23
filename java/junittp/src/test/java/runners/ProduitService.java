package runners;

import java.util.ArrayList;

public class ProduitService {
  private ArrayList<Produit> produits = new ArrayList<>();


  public void ajouterProduit(Produit produit) throws IllegalArgumentException {
    if (hasValidCode(produit) || produit.getPrix() < 0 || produit.getCode().length() != 3) {
      throw new IllegalArgumentException();
    }
    for (Produit p : produits) {
      {
        if (p.getCode() == produit.getCode()) {
          throw new IllegalArgumentException();
        }
      }
    }
    produits.add(produit);
  }

  private boolean hasValidCode(Produit produit) {
    return produit.getCode().length() <= 3;
  }

  public ArrayList<Produit> listerProduits() {
    return produits;
  }

}
