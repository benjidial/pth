#ifndef PTH_TEXT_H
#define PTH_TEXT_H

#include "../widget.h"

/* * * * * * * * * * * * * * *
 * PTH text header           *
 * Copyright 2018 Benji Dial *
 * Under MIT license         *
 * * * * * * * * * * * * * * */

namespace pth {
  class text : public widget {
  protected:
    char *text = "";
    int text_len = 0;
    char *fill = "                                                                                "/*80*/;
    int curs_x, curs_y;

  public:
    char color = 0x07;
    bool editable = false;

    text(widget *parent, char *text="", int len=0, char color=0x07, bool editable=false);
    virtual void set_text(char *text, int len);
    char *get_text(void);

    virtual void set_size(x, y, width, height);
    virtual void draw(void);
    virtual void interact(char key);
    virtual void on_focus(void);
  };
}

#endif
