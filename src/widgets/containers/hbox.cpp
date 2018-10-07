#include "hbox.h"
#include "../../widget.h"
#include <list>

/* * * * * * * * * * * * * * *
 * PTH hbox implementation   *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  void hbox::add_widget(widget w, float weight) {
    widgets.push_back(w);
    widget_weights.push_back(weight);
    weights_total += weight;
  }

  void hbox::draw(int x, int y, int width, int height) {
    float x_next = 0;
    list<widget>::iterator wi = widgets.begin();
    list<float>::iterator wei = widget_weights.begin();
    do {
      (*wi).draw(x_next, y, (float)width * *wei / weights_total, height);
      x_next += (float)width * *(wei++) / weights_total;
    } while (++wi != widgets.end());
  }
}
