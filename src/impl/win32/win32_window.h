//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_IMPL_WIN32_WIN32_WINDOW_H_
#define MINECRAFT_SRC_IMPL_WIN32_WIN32_WINDOW_H_

#include <core/window.h>

#include <cstdint>

#include <string>
#include <memory>

namespace minecraft::win32 {

class Win32Window : public core::Window {
 public:
  Win32Window(const std::string& title, uint32_t width, uint32_t height);

  void *GetPlatformHandle() override;

  void SetVSync(bool enabled) override;
  bool IsVSync() const override;

 public:
  uint32_t GetWidth() const override;
  uint32_t GetHeight() const override;

 private:
  std::string m_title;
  uint32_t m_width, m_height;
};

}

#endif //MINECRAFT_SRC_IMPL_WIN32_WIN32_WINDOW_H_
