import org.junit.jupiter.api.Test;
import com.fasterxml.jackson.core.JsonProcessingException;
import ma.ehei.gi4.Etudiant;
import ma.ehei.gi4.EtudiantMapper;
import static org.junit.jupiter.api.Assertions.*;

class EtudiantMapperTest {

  @Test
  void testMapping() throws JsonProcessingException {
    Etudiant e = new Etudiant("hamid", "lamba");
    String xml = EtudiantMapper.convertEtudiant(e);
    assertNotNull(xml);
    assertTrue(xml.contains("hamid"));
    assertTrue(xml.contains("lamba"));
  }
}
