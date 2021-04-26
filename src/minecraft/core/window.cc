//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#include <mpch.h>
#include <minecraft/core/window.h>
#include <minecraft/impl/win32/win32_window.h>

namespace minecraft::core {

std::unique_ptr<Window> Window::Create(
	const std::string &title,
	uint32_t width,
	uint32_t height
) {
#ifdef WIN32
  return std::make_unique<win32::Win32Window>(title, width, height);
#endif

  fprintf(stderr, "Fatal Error: This platform is not supported.");
  exit(EXIT_FAILURE);
}

}
