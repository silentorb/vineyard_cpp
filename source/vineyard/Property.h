#pragma once

#include "Types.h"
#include <string>

using namespace std;

namespace vineyard {

  class Trellis;

  class Property {
      const string name;
      Trellis *trellis;
      Types type;
      Trellis *other_trellis = nullptr;
      const string other_trellis_name;
      int offset = -1;

  public:
      Property(const string &name, Types type);

      const string &get_name() const {
        return name;
      }

      Trellis &get_trellis() const {
        return *trellis;
      }

      void set_trellis(Trellis &trellis) {
        this->trellis = &trellis;
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

      int get_offset() const {
        return offset;
      }

      void set_offset(int offset) {
        Property::offset = offset;
      }

      const Type_Info &get_info() const;

      const string &get_other_trellis_name() const {
        return other_trellis_name;
      }
  };
}