#include <string>
#include <iostream>
#include "BorderStyle.hpp"
#include "ITabulizer.hpp"
#include "TabulizerFactory.hpp"

int main() {

  ITabulizer* table = TabulizerFactory::createStaticTabulizer(
      80, 3, true, BorderStyle::unicodeRounded());


  CellOptions header;
  header.letterCase = LETTER_CASE_ALL_UPPER;
  header.hAlign = H_ALIGN_CENTER;
  header.vAlign = V_ALIGN_CENTER;
  header.border = BORDER_ALL;

  table->setCell(0, 0, "PRODUCT", header);
  table->setCell(0, 1, "DESCRIPTION", header);
  table->setCell(0, 2, "PRICE", header);
  table->setCell(0, 3, "STOCK", header);


  CellOptions leftTop;
  leftTop.hAlign = H_ALIGN_LEFT;
  leftTop.vAlign = V_ALIGN_TOP;
  leftTop.border = BORDER_ALL;

  CellOptions center;
  center.hAlign = H_ALIGN_CENTER;
  center.vAlign = V_ALIGN_CENTER;
  center.border = BORDER_ALL;

  CellOptions rightBottom;
  rightBottom.hAlign = H_ALIGN_RIGHT;
  rightBottom.vAlign = V_ALIGN_BOTTOM;
  rightBottom.border = BORDER_ALL;

  table->setCell(1, 0, "Laptop", leftTop);
  table->setCell(1, 1, "Lightweight 13-inch display", center);
  table->setCell(1, 2, "1299.99", rightBottom);
  table->setCell(1, 3, "42", rightBottom);

  table->setCell(2, 0, "Headphones", leftTop);
  table->setCell(2, 1, "Noise cancelling Wireless", center);
  table->setCell(2, 2, "199.50", rightBottom);
  table->setCell(2, 3, "128", rightBottom);

  table->setCell(3, 0, "Smartwatch", leftTop);
  table->setCell(3, 1, "Fitness tracking Heart rate monitor", center);
  table->setCell(3, 2, "349.00", rightBottom);
  table->setCell(3, 3, "75", rightBottom);

  table->display();
  delete table;
  return 0;
}