//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_IMPL_WIN32_WIN32_WINDOW_H_
#define MINECRAFT_SRC_IMPL_WIN32_WIN32_WINDOW_H_

#include <minecraft/core/window.h>
#include <minecraft/render/context.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <cstdint>

#include <string>
#include <memory>

namespace minecraft::win32 {

// Win32Data represents the "data" stored on the Window class.
struct Win32Data {
  std::string title;
  bool is_vsync = false, is_closing = false;
  uint32_t width = 0, height = 0;
};

// Win32Window represents the Win32 Window implementation using GLFW.
class Win32Window : public core::Window {
 public:
  Win32Window(const std::string& title, uint32_t width, uint32_t height);

  void Initialize() override;

  void *GetPlatformHandle() override;

  void SetVSync(bool enabled) override;
  [[nodiscard]] bool IsVSync() const override;

 public:
  [[nodiscard]] uint32_t GetWidth() const override;
  [[nodiscard]] uint32_t GetHeight() const override;

  [[nodiscard]] bool ShouldClose() const override;

 public:
  void OnUpdate() override;

 private:
  Win32Data m_data;

 private:
  GLFWwindow* m_handle;
  std::unique_ptr<render::Context> m_context;
};

}

#endif //MINECRAFT_SRC_IMPL_WIN32_WIN32_WINDOW_H_
