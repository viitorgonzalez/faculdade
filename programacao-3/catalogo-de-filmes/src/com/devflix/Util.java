package com.devflix;

import javax.swing.JOptionPane;

public class Util {
  public static int JShowDialog(String opcs[]) {
    int opc = JOptionPane.showOptionDialog(
      null,
      "Escolha uma Opção",
      "Menu",
      JOptionPane.DEFAULT_OPTION,
      JOptionPane.INFORMATION_MESSAGE,
      null,
      opcs,
      opcs[0]
    );

    return opc;
  }
}
