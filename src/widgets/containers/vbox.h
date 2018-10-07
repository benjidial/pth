#ifndef PTH_VBOX_H
#define PTH_VBOX_H

#include "../../widget.h"
#include <list>

/* * * * * * * * * * * * * * *
 * PTH vbox header           *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  class vbox : widget {
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
