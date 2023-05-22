#include <hass/hass.h>
#include <iostream>

using namespace hass;
using namespace hass::tools;
using namespace jsoncons;

std::string data = R"(
  {
    "system":{
      "version":"3.10.0",  // specifing a direct image tag from docker hub is also allowed
      "deployment":"local", // local | cloud
      "cleanup":true,
      "agency":3,
      "coordinators":3,
      "dbservers":4
    },
    "database":{
      "name":"test",
      "replication_factor":3,
      "write_factor":1,
      "collections":{
        "count":10,
        "naming_schema":"collection_{id}",
        "sharding":{
          "from":10,
          "to":100
        }
      }
    },
    "data":{
      "documents":{
        "fields":5,
        "count":1000000,
        "size":500,
        "types":[
          "string",
          "integer",
          "float",
          "boolean",
          "date"
        ]
      }
    },
    "test":{
    }
  }
)";

auto main() -> int {
  try {
    json j = json::parse(data);

    auto controller = Controller::create(j["system"]);
    controller->setup(j["database"]);
    controller->populate(j["data"]);
    controller->run(j["test"]);

    std::cout << controller->report() << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
