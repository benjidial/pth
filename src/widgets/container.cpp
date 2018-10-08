#include "container.h"
#include "../widget.h"
#include <list>

/* * * * * * * * * * * * * * * * *
 * PTH container implementation  *
 * Copyright 2018 Benji Dial     *
 * Under MIT license             *
 * * * * * * * * * * * * * * * * */

using std::list;

namespace pth {
  container::container(widget *parent, char prev, char next)
    : widget(false, parent), prev(prev), next(next) { }

  void container::add_widget(widget w, float weight) {
    widgets.push_back(w);
    widget_weights.push_back(weight);
    weights_total += weight;
    if (!focusable && w.focusable)
      focusable = true;
      focus = --widgets.end();
  }

  void container::set_size(int x, int y, int width, int height)
    : widget::set_size(x, y, width, height) {
    for (widget w : widgets)
      w.set_size(x, y, width, height);
  }

  void container::draw(void) {
    for (widget w : widgets)
      w.draw();
  }

  void container::interact(char key) {
    if (key == prev) {
      widget *safe = &*focus;
      while (focus-- != widgets.begin())
        if ((*focus).focusable) {
          safe->on_unfocus();
          widget::focus = &*focus;
          focus->on_focus();
          return;
        }
      focus = widgets.begin();
      parent->interact(prev);
      return;
    } if (key == next || key == 0x41 /*Tab*/) {
      widget *safe = &*focus;
      while (++focus != widgets.end())
        if ((*focus).focusable) {
          safe->on_unfocus();
          widget::focus = &*focus;
          focus->on_focus();
          return;
        }
      focus--;
      parent->interact(key);
      return;
    }
    parent->interact(key);
  }

  void container::on_focus(void) {
    widget::focus = &*focus;
    focus->on_focus();
  }

  void container::on_unfocus(void) {
    focus->on_unfocus();
  }
}
