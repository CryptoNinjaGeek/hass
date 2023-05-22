#pragma once

#include <hass/Controller.h>

namespace hass::driver {
class DockerController final : public Controller {
public:
  DockerController() = default;
};
} // namespace hass::driver
