#include <string>

#include "BorderStyle.hpp"
#include "ITabulizer.hpp"
#include "TabulizerFactory.hpp"

int main() {
  ITabulizer* table = TabulizerFactory::createStaticTabulizer(
      20, 5, true, BorderStyle::unicodeDouble());

  CellOptions headerOptions;
  headerOptions.letterCase = LETTER_CASE_ALL_UPPER;
  headerOptions.hAlign = H_ALIGN_CENTER;
  headerOptions.vAlign = V_ALIGN_CENTER;
  headerOptions.border = BORDER_ALL;

  table->setCell(0, 0, "FIRST NAME LONG HEADER", headerOptions);
  table->setCell(0, 1, "LAST NAME", headerOptions);
  table->setCell(0, 2, "AGE", headerOptions);
  table->setCell(0, 3, "CITY", headerOptions);
  table->setCell(0, 4, "COUNTRY", headerOptions);
  table->setCell(0, 5, "SCORE", headerOptions);

  CellOptions row1Options;
  row1Options.hAlign = H_ALIGN_LEFT;
  row1Options.vAlign = V_ALIGN_TOP;
  row1Options.border = BORDER_ALL;

  table->setCell(1, 0, "Jonathan Alexander Smithington", row1Options);
  table->setCell(1, 1, "Doe", row1Options);
  table->setCell(1, 2, "28", row1Options);
  table->setCell(1, 3, "New York City", row1Options);
  table->setCell(1, 4, "United States of America", row1Options);
  table->setCell(1, 5, "95", row1Options);

  CellOptions row2Options;
  row2Options.hAlign = H_ALIGN_CENTER;
  row2Options.vAlign = V_ALIGN_CENTER;
  row2Options.border = BORDER_ALL;

  table->setCell(2, 0, "Alice", row2Options);
  table->setCell(2, 1, "Johnson", row2Options);
  table->setCell(2, 2, "34", row2Options);
  table->setCell(2, 3, "Los Angeles", row2Options);
  table->setCell(2, 4, "USA", row2Options);
  table->setCell(2, 5, "88", row2Options);

  CellOptions row3Options;
  row3Options.hAlign = H_ALIGN_RIGHT;
  row3Options.vAlign = V_ALIGN_BOTTOM;
  row3Options.border = BORDER_ALL;

  table->setCell(3, 0, "Bob", row3Options);
  table->setCell(3, 1, "Williams-Smythe", row3Options);
  table->setCell(3, 2, "45", row3Options);
  table->setCell(3, 3, "San Francisco", row3Options);
  table->setCell(3, 4, "USA", row3Options);
  table->setCell(3, 5, "76", row3Options);

  table->display();
  delete table;
  return 0;
}
