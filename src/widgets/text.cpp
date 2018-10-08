#include "../widget.h"
#include "text.h"
#include <p-clib.h>
#include <cstring>

/* * * * * * * * * * * * * * *
 * PTH text implementation   *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  text(widget *parent, char *text="", int len=0, char color=0x07, bool editable=false)
    : widget(parent, editable), text(text), text_len(len), color(color), editable(editable) { }
  void widget::draw(int x, int y, int width, int height) {
    /*FIXME: doesn't handle whitespace other than plain spaces specially*/
    /*FIXME: doesn't handle text that doesn't fit in viewport specially
             (should probably have a vertical scrollbar)*/
    char *curr = text;
    char safe;
    int y_next = y, n = 0;
    set_color(color);
    while ((n += width) < text_len) {
      safe = curr[width];
      curr[width] = '\0';
      move_cursor(y_next++, x);
      print_bytes(curr);
      (curr += width)[0] = safe;
    }
    fill[width] = '\0';
    print_bytes(fill);
    move_cursor(y_next, x);
    print_bytes(curr);
    while (++y_next < y + height) {
      move_cursor(y_next, x);
      print_bytes(fill);
    }
    fill[width] = ' ';
  }

  void text::set_text(char *text, int len) {
    this.text = text;
    text_len = len;
  }

  char *text::get_text(void) {
    return text;
  }

  void interact(char key) {
    /*TODO: handle navigation keys accordingly, otherwise insert character at cursor*/
  }

  void on_focus(void) {
    /*TODO: move cursor*/
  }
}
