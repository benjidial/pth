#ifndef PTH_WIDGET_H
#define PTH_WIDGET_H

/* * * * * * * * * * * * * * *
 * PTH widget header         *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  class widget {
  protected:
    widget(bool focusable, widget *parent)
      : focusable(focusable), parent(parent) { }

  public:
    static widget *focus;

    bool focusable;
    widget *parent;

    virtual void draw(int x, int y, int width, int height);
    virtual void interact(char key);
    virtual void on_focus(void);
  };
}

#endif
