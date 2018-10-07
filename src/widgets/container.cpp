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

  void container::interact(char key) {
    if (key == prev) {
      while (focus-- != widgets.begin())
        if ((*focus).focusable) {
          widget::focus = &*focus;
          (*focus).on_focus();
          return;
        }
      focus = widgets.begin();
      parent->interact(prev);
      return;
    } if (key == next || key == 0x41 /*Tab*/) {
      while (++focus != widgets.end())
        if ((*focus).focusable) {
          widget::focus = &*focus;
          (*focus).on_focus();
          return;
        }
      focus--;
      parent->interact(key);
      return;
    }
    parent->interact(key);
  }

  void container::on_focus() {
    widget::focus = &*focus;
    (*focus).on_focus();
  }
}
