#ifndef PTH_HBOX_H
#define PTH_HBOX_H

#include "../widget.h"
#include <list>

/* * * * * * * * * * * * * * *
 * PTH containers/hbox.h     *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  class hbox : widget {
  protected:
    list<widget> widgets;
    list<float> widget_weights;
    float weights_total = 0;

  public:
    void add_widget(widget w, float weight);
    virtual void draw(int x, int y, int width, int height);
  };
}

#endif
