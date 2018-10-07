#ifndef PTH_WIDGET_H
#define PTH_WIDGET_H

/* * * * * * * * * * * * * * *
 * PTH widget.h              *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  class widget {
  public:
    virtual void draw(int x, int y, int width, int height);
  };
}

#endif
