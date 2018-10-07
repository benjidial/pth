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
  class hbox : container {

  public:
    hbox(widget *parent);
    virtual void draw(int x, int y, int width, int height);
  };
}

#endif
