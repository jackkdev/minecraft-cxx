//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_IMPL_OPENGL_OPENGL_CONTEXT_H_
#define MINECRAFT_SRC_IMPL_OPENGL_OPENGL_CONTEXT_H_

#include <minecraft/render/context.h>

namespace minecraft::opengl {

class OpenGLContext : public render::Context {
 public:
  explicit OpenGLContext(void *window);

  void Initialize() override;
  void OnUpdate() override;

 private:
  void *m_window;
};

}

#endif //MINECRAFT_SRC_IMPL_OPENGL_OPENGL_CONTEXT_H_
