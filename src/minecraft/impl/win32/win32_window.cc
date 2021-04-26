//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#include <mpch.h>
#include <minecraft/render/context.h>
#include <minecraft/impl/win32/win32_window.h>

namespace minecraft::win32 {

Win32Window::Win32Window(
	const std::string &title,
	uint32_t width,
	uint32_t height
) {
  m_data.title = title;
  m_data.width = width;
  m_data.height = height;

  m_handle = nullptr;
}

void Win32Window::Initialize() {
  // Initialize GLFW.
  if (!glfwInit()) {
	fprintf(stderr, "Error: Failed to initialize GLFW.\n");
	exit(EXIT_FAILURE);
  }

  // Hint the correct GL version.
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_RESIZABLE, true);

  // Create the window handle.
  m_handle = glfwCreateWindow(
	  static_cast<int>(m_data.width),
	  static_cast<int>(m_data.height),
	  m_data.title.c_str(),
	  nullptr,
	  nullptr
  );

  // Setup the window context.
  m_context = render::Context::Create(m_handle);
  m_context->Initialize();

  // Setup the user data.
  glfwSetWindowUserPointer(m_handle, &m_data);

  // Setup the window close callback.
  glfwSetWindowCloseCallback(m_handle, [](GLFWwindow* handle) {
	auto *data = (Win32Data *)glfwGetWindowUserPointer(handle);
	data->is_closing = true;
  });

  // Setup the size callback.
  glfwSetWindowSizeCallback(m_handle, [](GLFWwindow *handle, int width, int height) {
	auto *data = (Win32Data *)glfwGetWindowUserPointer(handle);

	data->width = static_cast<uint32_t>(width);
	data->height = static_cast<uint32_t>(height);
  });
}

void *Win32Window::GetPlatformHandle() {
  return m_handle;
}

void Win32Window::SetVSync(bool enabled) {
  m_data.is_vsync = true;
  glfwSwapInterval(int(m_data.is_vsync));
}

bool Win32Window::IsVSync() const {
  return m_data.is_vsync;
}

uint32_t Win32Window::GetWidth() const {
  return m_data.width;
}

uint32_t Win32Window::GetHeight() const {
  return m_data.height;
}

bool Win32Window::ShouldClose() const {
  return m_data.is_closing;
}

void Win32Window::OnUpdate() {
  glfwSwapBuffers(m_handle);
  glfwPollEvents();
}

}
