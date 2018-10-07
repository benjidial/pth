#include "vbox.h"
#include "../../widget.h"
#include <list>

/* * * * * * * * * * * * * * *
 * PTH vbox implementation   *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  void vbox::add_widget(widget w, float weight) {
    widgets.push_back(w);
    widget_weights.push_back(weight);
    weights_total += weight;
  }

  void vbox::draw(int x, int y, int width, int height) {
    float y_next = 0;
    list<widget>::iterator wi = widgets.begin();
    list<float>::iterator wei = widget_weights.begin();
    do {
      (*wi).draw(x, y_next, width, (float)height * *wei / weights_total);
      y_next += (float)height * *(wei++) / weights_total;
    } while (++wi != widgets.end());
  }
}
