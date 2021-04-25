//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_CORE_WINDOW_H_
#define MINECRAFT_SRC_CORE_WINDOW_H_

#include <cstdint>
#include <cstdlib>

#include <string>
#include <memory>

namespace minecraft::core {

class Window {
 public:
  virtual ~Window() = default;

  virtual void *GetPlatformHandle() = 0;
  virtual void SetVSync(bool enabled) = 0;
  [[nodiscard]] virtual bool IsVSync() const = 0;

 public: // Interface Getters
  [[nodiscard]] virtual uint32_t GetWidth() const = 0;
  [[nodiscard]] virtual uint32_t GetHeight() const = 0;

 public: // Static Initialization Methods
  static std::unique_ptr<Window> Create(
	  const std::string &title,
	  uint32_t width,
	  uint32_t height
  );
};

}

#endif //MINECRAFT_SRC_CORE_WINDOW_H_
