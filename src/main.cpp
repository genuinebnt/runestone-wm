#include <glog/logging.h>
#include <iostream>

#include "window_manager.hpp"

int main(int argc, char **argv) {
  ::google::InitGoogleLogging(argv[0]);

  unique_ptr<WindowManager> wm(WindowManager::init());

  if (!wm) {
    LOG(ERROR) << "Failed to initialize window manager";
    return -1;
  }

  wm->run();

  return 0;
}