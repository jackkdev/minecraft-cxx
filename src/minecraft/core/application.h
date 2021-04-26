//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_MINECRAFT_CORE_APPLICATION_H_
#define MINECRAFT_SRC_MINECRAFT_CORE_APPLICATION_H_

#include <minecraft/core/window.h>

#include <memory>

namespace minecraft::core {

class Application {
 public:
  Application();
  ~Application();

  void Initialize();

 private:
  std::unique_ptr<Window> m_window;
};

}

#endif //MINECRAFT_SRC_MINECRAFT_CORE_APPLICATION_H_
