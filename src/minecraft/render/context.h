//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_RENDER_CONTEXT_H_
#define MINECRAFT_SRC_RENDER_CONTEXT_H_

#include <minecraft/core/window.h>

namespace minecraft::render {

class Context {
 public:
  virtual ~Context() = default;

  virtual void Initialize() = 0;
  virtual void OnUpdate() = 0;

 public:
  static std::unique_ptr<Context> Create(void *window);
};

}

#endif //MINECRAFT_SRC_RENDER_CONTEXT_H_
