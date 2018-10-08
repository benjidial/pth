#ifndef PTH_BUTTON_H
#define PTH_BUTTON_H

#include "../widget.h"
#include <list>

/* * * * * * * * * * * * * * *
 * PTH button header         *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  class button {
  protected:
    char *text = "";
    int text_len = 0;
    char *fill = "                                                                                " /*80*/;

  public:
    char unfocused_color = 0x7f, focused_color = 0x8f;
    void (*func)(button *);

    button(widget *parent, char *text="", int len=0, char unfocused_color=0x7f, char focused_color=0x8f);

    virtual void set_size(int x, int y, int width, int height);
    virtual void draw(void);
    virtual void interact(char key);
    virtual void on_focus(void);
    virtual void on_unfocus(void);
  };
}

#endif
