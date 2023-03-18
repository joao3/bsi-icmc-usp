public class FilteredSistema implements FilterSistema {

  public String lerDados(String s) {
    if (s.contains("789")) {
      return "987";
    } 

    return s;
  }

  public String[] lerArray(String[] s) {
    for (int i = 0; i < s.length; i++) {
      if (s[i].contains("789")) {
        s[i] = "987";
      }
    }
    return s;

  }
}
