#ifndef PTH_HBOX_H
#define PTH_HBOX_H

#include "../../widget.h"
#include "../container.h"

/* * * * * * * * * * * * * * *
 * PTH hbox header           *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  class hbox : public container {
  public:
    hbox(widget *parent);

    virtual void add_widget(widget w, float weight);

    virtual void set_size(int x, int y, int width, int height);
  };
}

#endif
