#pragma once
#include "String.h"
#include <ostream>

String::String() : m_capacity(0), m_buf(nullptr) {};

String::String(const char* c) {
  m_capacity = std::strlen(c) + 1;
  m_buf = new char[m_capacity];
  std::strcpy(m_buf, c);
}

String::String(const std::string& str) : m_capacity(str.length()) {
  m_buf = new char[m_capacity + 1];
  std::strcpy(m_buf, str.c_str());
}

String::String(const String& str) {
  if(this != &str){
    delete[] m_buf;
    if(str.m_buf){
      m_buf = new char[str.m_capacity];
      m_capacity = str.m_capacity;
      std::strcpy(m_buf, str.m_buf);
    }
  }
}

String::String(String&& str) noexcept{
  m_capacity = str.m_capacity;
  m_buf = str.m_buf;
  str.m_capacity = 0;
  delete[] str.m_buf;
}

String::~String() {
  delete[] m_buf;
}

void String::setCap(int c) {
  m_capacity = c;
}

void String::setBuf(const char *c) {
  if(c) {
    delete[] m_buf;
    m_capacity = std::strlen(c) + 1;
    m_buf = new char[m_capacity];
    std::strcpy(m_buf, c);
  }
}

int String::getCap() const {
  return m_capacity;
}

char* String::getBuf() const {
  return m_buf;
}

String& String::operator=(const String& str) {
  if(this != &str) {
    delete[] m_buf;
    m_capacity = str.m_capacity;
    m_buf = new char[m_capacity];
    std::strcpy(m_buf, str.m_buf);
  }
  return *this;
}

String& String::operator=(String&& str) {
  if(this != &str) {
    delete[] m_buf;
    m_capacity = str.m_capacity;
    m_buf = str.m_buf;
    str.m_capacity = 0;
  }
  return *this;
}

char String::operator[](int i) const{
  return m_buf[i];
}

std::ostream& operator<<(std::ostream& os, const String& str) {
  os<<str.getBuf();
  return os;
}
