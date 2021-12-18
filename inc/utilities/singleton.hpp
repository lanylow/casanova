#pragma once

template <typename T> class singleton {
protected:
  singleton() { }
  ~singleton() { }

public:
  static T& get() {
    static T inst{ };
    return inst;
  }
};