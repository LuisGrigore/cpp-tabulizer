# Tabulizer C++ Library

## Description

**Tabulizer** is a lightweight C++ library for creating and rendering textual tables in the terminal. It supports:

- Customizable borders (ASCII or Unicode, single, double, rounded, bold, dashed, minimal, etc.)
- Per-cell formatting: text alignment (horizontal and vertical), letter casing
- Automatic row and column sizing
- Flexible tables with a maximum size and truncation
- Easy-to-use API for creating tables programmatically

Compatible with **C++98**, making it suitable for legacy and modern environments.

---

## Installation

### Include source

1. Execute this command inside your project directory

```bash
git clone https://github.com/LuisGrigore/cpp-tabulizer.git
cd cpp-tabulizer
./tools/initializer/init.sh -include_src
cd ..
```

2. Link the library Makefile to your projects build system

3. Link `build/lib/libtabulizer.a` in your project compilation


### Built only

1. Execute this command inside your project directory

```bash
git clone https://github.com/LuisGrigore/cpp-tabulizer.git
cd cpp-tabulizer
./tools/initializer/init.sh -build_only
cd ..
```
2. Link `build/lib/libtabulizer.a` in your project compilation


### Python

Not yet supported

---

## BorderStyle Presets

| Style                  | Example |
|------------------------|---------|
| `ascii()`              | `+---+---+|   |   |+---+---+` |
| `unicode()`            | `┌───┬───┐│   │   │└───┴───┘` |
| `unicodeRounded()`     | `╭───╮╭───╮│   │ │   │╰───╯╰───╯` |
| `unicodeDouble()`      | `╔═══╦═══╗║   ║   ║╚═══╩═══╝` |
| `unicodeBold()`        | `▛▀▀▀▜▛▀▀▀▜▌   ▐ ▌   ▐▙▄▄▄▟▙▄▄▄▟` |
| `unicodeDashed()`      | `┌─ ─┬─ ─┐│   │   │└─ ─┴─ ─┘` |
| `minimal()`            | `- - | |- -` |

> These examples are simplified. Actual rendering may vary depending on terminal font and Unicode support.

---

## Enums

**Border (bitmask)**

| Value           | Description           |
|-----------------|----------------------|
| `BORDER_NONE`   | No border            |
| `BORDER_TOP`    | Top border           |
| `BORDER_BOTTOM` | Bottom border        |
| `BORDER_LEFT`   | Left border          |
| `BORDER_RIGHT`  | Right border         |
| `BORDER_ALL`    | All sides            |

**LetterCase**

| Value                  | Description                      |
|------------------------|----------------------------------|
| `LETTER_CASE_ALL_UPPER`| All letters uppercase            |
| `LETTER_CASE_ALL_LOWER`| All letters lowercase            |
| `LETTER_CASE_DEFAULT`  | Keep original casing             |

**HAlign (Horizontal Alignment)**

| Value            | Description         |
|-----------------|-------------------|
| `H_ALIGN_LEFT`  | Align left         |
| `H_ALIGN_CENTER`| Align center       |
| `H_ALIGN_RIGHT` | Align right        |

**VAlign (Vertical Alignment)**

| Value             | Description       |
|------------------|-----------------|
| `V_ALIGN_TOP`     | Align top        |
| `V_ALIGN_CENTER`  | Align center     |
| `V_ALIGN_BOTTOM`  | Align bottom     |

---

## CellOptions

```cpp
struct CellOptions {
    LetterCase letterCase;  // Default: LETTER_CASE_DEFAULT
    HAlign hAlign;          // Default: H_ALIGN_CENTER
    VAlign vAlign;          // Default: V_ALIGN_CENTER
    BorderMask border;      // Default: BORDER_NONE
};
```

- Used when setting cell content in `ITabulizer::setCell`.

---

## ITabulizer (Interface)

| Method                                      | Description |
|--------------------------------------------|------------|
| `virtual ~ITabulizer()`                     | Destructor |
| `virtual void setCell(unsigned int row, unsigned int col, const std::string& content, const CellOptions& options = CellOptions())` | Set the content and formatting of a cell |
| `virtual void display()`                     | Render the table to the terminal |

---

## StaticTabulizer (Implementation)

| Method / Member                             | Description |
|---------------------------------------------|------------|
| `StaticTabulizer(maxCellWidth, maxCellHeight, flex, borderStyle)` | Constructor with table configuration |
| `setCell(row, col, content, options)`       | Set content and options for a specific cell |
| `display()`                                 | Render the table |
| `Cell`                                      | Internal cell class, handles content, alignment, and borders |

**Cell internal class**

| Method                     | Description |
|----------------------------|------------|
| `getContent()`             | Returns the string content |
| `hasBorder(Border border)` | Check if a specific border exists |
| `getVerticalAlignment()`   | Get vertical alignment |
| `getHorizontalAlignment()` | Get horizontal alignment |

---

## TabulizerFactory

| Method | Description |
|--------|------------|
| `createStaticTabulizer(maxCellWidth, maxCellHeight, flex, borderStyle)` | Factory method to create a `StaticTabulizer` instance |

---

## Example Usage

```cpp
#include "ITabulizer.hpp"
#include "TabulizerFactory.hpp"
#include "BorderStyle.hpp"

int main() {
    ITabulizer* table = TabulizerFactory::createStaticTabulizer(
        20, 5, true, BorderStyle::unicodeDouble()
    );

    CellOptions header;
    header.letterCase = LETTER_CASE_ALL_UPPER;
    header.hAlign = H_ALIGN_CENTER;
    header.vAlign = V_ALIGN_CENTER;
    header.border = BORDER_ALL;

    table->setCell(0, 0, "NAME", header);
    table->setCell(0, 1, "AGE", header);

    CellOptions data;
    data.hAlign = H_ALIGN_LEFT;
    data.border = BORDER_ALL;

    table->setCell(1, 0, "Alice", data);
    table->setCell(1, 1, "28", data);

    table->display();

    delete table;
    return 0;
}
```

---

## Features

- Full control of table borders with `BorderStyle`
- Configurable horizontal and vertical alignment
- Letter casing per cell
- Flexible tables with automatic width/height adjustment
- Easy factory-based creation
- Compatible with C++98

---

