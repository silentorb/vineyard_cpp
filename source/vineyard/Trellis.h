#pragma once

#include "Property.h"
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <commoner/no_copy.h>

using namespace vineyard;

namespace vineyard {

  using Trellis_Map = std::function<Trellis &(const std::string &)>;

  class Trellis : commoner::no_copy {
      const std::string name;
      std::vector<std::unique_ptr<Property>> properties;

  public:
      Trellis(const std::string &name);
      ~Trellis();

      const std::string &get_name() const {
        return name;
      }

      void reserve_properties(size_t size);

      Property &create_property(const std::string &name, Types type);

      const std::vector<std::unique_ptr<Property>> &get_properties() const {
        return properties;
      }

      const Property &get_property(const std::string &property_name) const;

      const Property &get_property(int index) const {
        return *properties[index];
      }
  };
}