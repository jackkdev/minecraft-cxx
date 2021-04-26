//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#define MINECRAFT_VERSION "0.1-INDEV"

#include <mpch.h>
#include <minecraft/core/application.h>

using namespace minecraft::core;

int main() {
  logger::set_level(logger::level::debug);
  logger::debug("Running Minecraft CXX v{}", MINECRAFT_VERSION);

  auto *application = new Application();
  application->Initialize();
  delete application;

  return EXIT_SUCCESS;
}
