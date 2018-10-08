#include "widget.h"
#include <p-clib.h>

/* * * * * * * * * * * * * * *
 * PTH widget implementation *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  void widget::set_size(int x, int y, int width, int height) {
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
  }

  void widget::draw(void) { }

  void widget::interact(char key) {
    parent->interact(key);
  }

  void widget::on_focus(void) {
    move_cursor(y, x);
  }
  
  void widget::on_unfocus(void) { }
}