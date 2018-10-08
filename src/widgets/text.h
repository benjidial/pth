#ifndef PTH_TEXT_H
#define PTH_TEXT_H

#include "../widget.h"

/* * * * * * * * * * * * * * *
 * PTH text header           *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  class text : widget {
    char *text = "";
    int text_len = 0;

  public:
    char color = 0x07;
    bool editable = false;

    text(widget *parent, char *text="", int len=0, char color=0x07, bool editable=false);
    void set_text(char *text, int len);
    char *get_text(void);
    virtual void draw(int x, int y, int width, int height);
    virtual void interact(char key);
    virtual void on_focus(void);
  };
}

#endif
