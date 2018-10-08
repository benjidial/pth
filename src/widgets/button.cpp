#include <p-clib.h>
#include "button.h"
#include "../widget.h"

/* * * * * * * * * * * * * * *
 * PTH hbox implementation   *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  button::button(widget *parent, char *text="", int len=0, char unfocused_color=0x7f, char focused_color=0x8f)
    : widget(true, parent), text(text), text_len(len), unfocused_color(unfocused_color), focused_color(focused_color) { }

  button::set_size(int x, int y, int width, int height) {
    fill[this.width] = ' ';
    fill[this.width = width] = '\0';
  }

  button::draw(void) {
    set_color(widget.focus == this ? focused_color : unfocused_color);
    int y_end = y + height;
    int write_y = (y + y_end) / 2 - 1;
    fill[width] = '\0';
    while (y_end-- > y) {
      move_cursor(y_end, x);
      print_bytes(fill);
    }
    move_cursor(write_y, x + (width - text_len) / 2);
    print_bytes(text);
    fill[width] = ' ';
  }

  button::interact(char key) {
    switch (key) {
    case 0x40 /*Enter/Return*/:
    case 0x43 /*Space*/:
      func(this);
      return;
    }
    parent->interact(key);
  }

  button::on_focus(void) = button::draw;

  button::on_unfocus(void) = button::draw;
}
