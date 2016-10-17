#include "Trellis.h"
#include <stdexcept>

using namespace std;

namespace vineyard {

  Trellis::Trellis(const string &name) :
    name(name) {

  }

  Trellis::~Trellis() {

  }

  void Trellis::reserve_properties(size_t size) {
    properties.reserve(size);
  }

  // For performance, create_property expects reserve_properties to be called first
  Property &Trellis::create_property(const string &name, Types type) {
    auto &property = properties[properties.size()];
    property.reset(new Property(name, type, *this));
    properties.resize(properties.size() + 1); // Update properties length

    return *property;
  }

  const Property &Trellis::get_property(const std::string &property_name) const {
    for (auto &property: properties) {
      if (property->get_name() == property_name)
        return *property;
    }

    throw runtime_error("Could not find property " + property_name);
  }
}