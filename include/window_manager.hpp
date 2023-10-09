#pragma once

extern "C" {
#include <X11/Xlib.h>
}
#include <glog/logging.h>
#include <memory>

using std::make_unique;
using std::unique_ptr;

class WindowManager {
private:
  Display *display_;
  const Window root_;
  static inline bool wm_detected_ = false;

  static auto OnXError(Display *display, XErrorEvent *e) -> int;
  static auto OnWMDectected(Display *display, XErrorEvent *e) -> int;

  auto OnCreateNotify(const XCreateWindowEvent &e) -> void;
  auto OnDestroyNotify(const XDestroyWindowEvent &e) -> void;
  auto OnConfigureRequest(const XConfigureRequestEvent &e) -> void;
  auto OnConfigureNotify(const XConfigureEvent &e) -> void;
  auto OnMapRequest(const XMapRequestEvent &e) -> void;
  auto OnMapNotify(const XMapEvent &e) -> void;
  auto OnUnmapNotify(const XUnmapEvent &e) -> void;
  auto OnReparentNotify(const XReparentEvent &e) -> void;
  auto Frame(Window w, bool was_created_before_window_manager) -> void;
  auto Unframe(Window w) -> void;

public:
  explicit WindowManager(Display *display)
      : display_(CHECK_NOTNULL(display)), root_(DefaultRootWindow(display_)) {}

  static auto init() -> unique_ptr<WindowManager>;

  auto run() -> void;

  ~WindowManager() = default;
};