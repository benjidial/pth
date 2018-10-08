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
    int x, y, width, height;

  public:
    static widget *focus;

    bool focusable;
    widget *parent;

    virtual void set_size(int x, int y, int width, int height);
    virtual void draw(void);
    virtual void interact(char key);
    virtual void on_focus(void);
    virtual void on_unfocus(void);
  };
}

#endif
