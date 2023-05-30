#pragma once
#include <iostream>
#include <cstring>

class String {
public:
  String();
  String(const char*);
  String(const std::string&);
  String(const String&);
  String(String&&) noexcept;
  ~String();

  void setCap(int);
  void setBuf(const char*);
  int getCap() const;
  char* getBuf() const;

  String& operator=(const String&);
  String& operator=(String&&);
  char operator[](int) const;
private:
  int m_capacity;
  char* m_buf;
};

std::ostream& operator<<(std::ostream&, const String&);

inline int my_strlen(const char* str) {
  return std::strlen(str);
}

inline int my_strlen(const std::string& str) {
  return str.length();
}

inline int my_strlen(const String& str) {
  return std::strlen(str.getBuf());
}

template <typename T, typename U>
String operator+(const T& str1, const U& str2) {
  String result;
  int tmp = my_strlen(str1) + my_strlen(str2);
  result.setCap(tmp);
  char *s = new char[tmp + 1];
  for(int i = 0; i < my_strlen(str1); ++i) {
    s[i] = str1[i];
  }
  for(int i = 0; i < my_strlen(str2); ++i) {
    s[i + my_strlen(str1)] = str2[i];
  }
  result.setBuf(s);
  return result;
}

template String operator+<const String&, const std::string&>(const String&, const std::string&);
template String operator+<const String&, const String&>(const String&, const String&);
template String operator+<const String&, const char*&>(const String&, const char*&);
template String operator+<const std::string&, const String&>(const std::string&, const String&);
template String operator+<const char*&, const String&>(const char*&, const String&);