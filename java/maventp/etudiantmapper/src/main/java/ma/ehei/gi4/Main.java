package ma.ehei.gi4;


import com.fasterxml.jackson.core.JsonProcessingException;

public class Main {
    public static void main(String[] args) throws JsonProcessingException {
        Etudiant e = new Etudiant("simo", "rouji");
        System.out.println(EtudiantMapper.convertEtudiant(e));
    }
}