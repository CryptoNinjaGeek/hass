#pragma once

#include <hass/Controller.h>

namespace hass::driver {
class ArangoGraphController final : public Controller {
public:
  ArangoGraphController() = default;
};
} // namespace hass::driver