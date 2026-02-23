package ma.ehei.gi4;

import com.fasterxml.jackson.dataformat.xml.XmlMapper;
import com.fasterxml.jackson.core.JsonProcessingException;

public class EtudiantMapper {
  public static String convertEtudiant(Etudiant etudiant) throws JsonProcessingException {
    XmlMapper xmlMapper = new XmlMapper();
    return xmlMapper.writeValueAsString(etudiant);
  }
}
