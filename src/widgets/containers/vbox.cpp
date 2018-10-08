#include "vbox.h"
#include "../container.h"
#include "../../widget.h"

/* * * * * * * * * * * * * * *
 * PTH vbox implementation   *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  vbox::vbox(widget *parent)
    : container(parent, 0x53 /*Up Arrow*/, 0x58 /*Down Arrow*/) { }

  void vbox::add_widget(widget w, float weight) {
    container::add_widget(w, weight);
    set_size(x, y, width, height);
  }

  void vbox::set_size(int x, int y, int width, int height) {
    float y_next = 0;
    list<widget>::iterator wi = widgets.begin();
    list<float>::iterator wei = widget_weights.begin();
    do {
      wi->set_size(x, y_next, width, (float)height * *wei / weights_total);
      y_next += (float)height * *(wei++) / weights_total;
    } while (++wi != widgets.end());
  }
}
