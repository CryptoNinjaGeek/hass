#pragma once

#include <jsoncons/json.hpp>
#include <memory>

namespace hass {

class Controller {
public:
  Controller() = default;

  auto setup(jsoncons::json) -> void;
  auto populate(jsoncons::json) -> void;
  auto run(jsoncons::json) -> void;
  auto report() -> std::string;

  static auto create(jsoncons::json) -> std::shared_ptr<Controller>;

private:
};
} // namespace hass
