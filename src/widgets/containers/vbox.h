#ifndef PTH_VBOX_H
#define PTH_VBOX_H

#include "../../widget.h"
#include "../container.h"

/* * * * * * * * * * * * * * *
 * PTH vbox header           *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  class vbox : container {

  public:
    vbox(widget *parent);
    virtual void draw(int x, int y, int width, int height);
  };
}

#endif
