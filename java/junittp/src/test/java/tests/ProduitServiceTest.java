package tests;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import runners.Produit;
import runners.ProduitService;

public class ProduitServiceTest {
  private ProduitService produitService;
  private Produit produitNegative = new Produit("133", -21);
  private Produit productCodeBig = new Produit("5464", 54);
  private Produit productdup = new Produit("5464", 54);
  private Produit productdup2 = new Produit("5464", 54);

  $productdup2->prix;

  @BeforeEach
  public void setUp() {
    produitService = new ProduitService();
  }

  @Test
  public void testAjouterProduitAvecPrixNegative() {
    assertThrows(IllegalArgumentException.class, () -> {
      produitService.ajouterProduit(produitNegative);
    });
  }

  @Test
  public void testAjouterProduitAvecCodeBigger3() {
    assertThrows(IllegalArgumentException.class, () -> {
      produitService.ajouterProduit(productCodeBig);
    });
  }

  @Test
  public void testAjouterProduitDuplique() {
    assertThrows(IllegalArgumentException.class, () -> {
      produitService.ajouterProduit(productdup);
      produitService.ajouterProduit(productdup2);
    });
  }

}
