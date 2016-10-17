#include <stdexcept>
#include "Property.h"

using namespace std;

namespace vineyard {

  Property::Property(const string &name, Types type, Trellis &trellis) :
    name(name), type(type), trellis(trellis) {

  }
}