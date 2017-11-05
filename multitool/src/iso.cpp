
#include "iso.hpp"
#include "error.hpp"
#include "font.hpp"
#include <iostream>
#include <libgen.h>

bool ISO::mount() {
  multitool_log("ISO::mount(): mounting ", m_path);
  return true;
}

bool ISO::unmount() {
  multitool_log("ISO::unmount(): unmounting ", m_path);
  return true;
}

bool ISO::on_select() {
  multitool_log("ISO::on_select()");
  if (m_mounted) {
    unmount();
  } else {
    mount();
  }
  return true;
}

Bitmap ISO::render() const {
  multitool_log("ISO::render()");
  auto buff = new char[m_path.size() + 1];
  m_path.copy(buff, m_path.size() + 1);
  auto bitmap = render_text(basename(buff));
  delete[] buff;
  return bitmap;
}
