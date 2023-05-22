#include <cxxopts.hpp>
#include <iostream>
#include <Input.h>

/*
 * arango_bench -c template.json
 * */

auto main(int argc, char* argv[]) -> int {
  arango_bench::input::BenchInput input;
  cxxopts::Options options("arango_import", "Import of data into arangodb");
  options.allow_unrecognised_options();

  auto add = options.add_options();
  add("c,configuration", "Configuration file");
  add("help", "Print usage");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  if (result.count("configuration")) input.configuration = result["configuration"].as<std::string>();

  return 0;
}
