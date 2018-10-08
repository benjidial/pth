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
  class vbox : public container {
  public:
    vbox(widget *parent);

    virtual void add_widget(widget w, float weight);

    virtual void set_size(int x, int y, int width, int height);
  };
}

#endif
