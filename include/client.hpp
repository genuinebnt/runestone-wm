#pragma once

#include <X11/Xlib.h>
#include <list>
#include <memory>

class Client {

public:
  Window window_;
  Window frame_;
  explicit Client(Window window, Window frame)
      : window_(window), frame_(frame) {}

  ~Client() = default;

  static std::list<Client *> clients_;
};