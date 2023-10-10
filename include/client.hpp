#pragma once

#include <X11/Xlib.h>
#include <list>
#include <memory>

class Client {
private:
  Window window_;
  Window frame_;

public:
  explicit Client(Window window, Window frame)
      : window_(window), frame_(frame) {}

  ~Client() = default;

  static std::list<std::unique_ptr<Client>> &clients_;
};