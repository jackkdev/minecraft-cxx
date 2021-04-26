//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#include <minecraft/render/context.h>
#include <minecraft/impl/opengl/opengl_context.h>

namespace minecraft::render {

std::unique_ptr<Context> Context::Create(void *window) {
#if 1
  return std::make_unique<opengl::OpenGLContext>(window);
#endif
}

}
