#pragma once

#include "Types.h"
#include <string>
#include <commoner/no_copy.h>

namespace vineyard {

  class Trellis;

  class Property : commoner::no_copy {
      const std::string name;
      Trellis &trellis;
      Types type;
      Trellis *other_trellis = nullptr;
      Property *other_property = nullptr;
      int index;

  public:
      Property(const std::string &name, Types type, Trellis &trellis);

      const std::string &get_name() const {
        return name;
      }

      Trellis &get_trellis() const {
        return trellis;
      }

      void set_other_trellis(Trellis *other_trellis) {
        this->other_trellis = other_trellis;
      }

      Types get_type() const {
        return type;
      }

      Trellis *get_other_trellis() const {
        return other_trellis;
      }

  };
}