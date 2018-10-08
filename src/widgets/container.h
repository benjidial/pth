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
  class container : public widget {
  protected:
    list<widget> widgets;
    list<float> widget_weights;
    float weights_total = 0;

    list<widget>::iterator focus;

    char prev, next;

  public:
    container(widget *parent, char prev, char next);
    virtual void add_widget(widget w, float weight);

    virtual void set_size(int x, int y, int width, int height);
    virtual void draw(void);
    virtual void interact(char key);
    virtual void on_focus(void);
    virtual void on_unfocus(void);
  };
}

#endif
