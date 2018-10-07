#ifndef PTH_CONTAINER_H
#define PTH_CONTAINER_H

#include "../widget.h"
#include <list>

/* * * * * * * * * * * * * * *
 * PTH container header      *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  class container : widget {
  protected:
    list<widget> widgets;
    list<float> widget_weights;
    float weights_total = 0;

    list<widget>::iterator focus;

    char prev, next;

  public:
    container(widget *parent, char prev, char next);

    void add_widget(widget w, float weight);
    virtual void draw(int x, int y, int width, int height) = 0;
    virtual void interact(char key);
    virtual void on_focus();
  };
}

#endif
