//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#include <mpch.h>
#include <minecraft/impl/opengl/opengl_context.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

namespace minecraft::opengl {

OpenGLContext::OpenGLContext(void *window)
	: m_window(window) {
  MC_ASSERT_N(window != nullptr, "Native window pointer is null!");
}

void OpenGLContext::Initialize() {
  glfwMakeContextCurrent((GLFWwindow *)m_window);

  int status = gladLoadGL(glfwGetProcAddress);
  MC_ASSERT_N(status != 0, "Failed to initialize Glad!");

  logger::info("OpenGL Information");
  logger::info("Vendor: {}", glGetString(GL_VENDOR));
  logger::info("Renderer: {}", glGetString(GL_RENDERER));
  logger::info("Version: {}", glGetString(GL_VERSION));
}

void OpenGLContext::OnUpdate() {

}

}
