#include <hass/drivers/ArangoGraphController.h>
#include <hass/drivers/DockerController.h>

using namespace hass;
using namespace hass::driver;

std::shared_ptr<Controller> Controller::create(jsoncons::json) {
  return std::make_shared<DockerController>();
}

auto Controller::setup(jsoncons::json) -> void {}

auto Controller::populate(jsoncons::json) -> void {}

auto Controller::run(jsoncons::json) -> void {}

auto Controller::report() -> std::string { return ""; }
