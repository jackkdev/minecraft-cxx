//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#include <mpch.h>
#include <minecraft/core/application.h>

namespace minecraft::core {

Application::Application() {
  m_window = Window::Create("Minecraft C++", 1600, 900);
}

Application::~Application() {}

void Application::Initialize() {
  m_window->Initialize();
  m_window->SetVSync(true);

  while (!m_window->ShouldClose()) {
	m_window->OnUpdate();
  }
}

}
