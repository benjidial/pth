#include "hbox.h"
#include "../container.h"
#include "../../widget.h"

/* * * * * * * * * * * * * * *
 * PTH hbox implementation   *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  hbox::hbox(widget *parent)
    : container(parent, 0x55 /*Left Arrow*/, 0x56 /*Right Arrow*/) { }

  void hbox::add_widget(widget w, float weight) {
    container::add_widget(w, weight);
    set_size(x, y, width, height);
  }

  void hbox::set_size(int x, int y, int width, int height) {
    float x_next = 0;
    list<widget>::iterator wi = widgets.begin();
    list<float>::iterator wei = widget_weights.begin();
    do {
      wi->set_size(x_next, y, (float)width * *wei / weights_total, height);
      x_next += (float)width * *(wei++) / weights_total;
    } while (++wi != widgets.end());
  }
}
