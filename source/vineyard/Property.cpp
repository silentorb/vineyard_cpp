#include <stdexcept>
#include "Property.h"

namespace vineyard {

  Property::Property(const string &name, Types type) :
    name(name), type(type) {

  }

  const Type_Info &Property::get_info() const {
    return get_type_info(get_type());
  }
}