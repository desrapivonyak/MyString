#pragma once
#include "String.h"

int main() {
  const char *a = "Hello, ";
  const char* b = "world!";
  String s1 = a;
  String s2;
  s2.setBuf(b);
  String result = s1 + s2;
  std::cout << "String + String:" << std::endl;
  std::cout << result.getBuf() << std::endl;
  std::string str1 = "Hello, ";
  String result2 = str1 + s2;
  std::cout << "std::string + String:" << std::endl;
  std::cout << result2.getBuf() << std::endl;
  const char* cstr1 = "Hello, ";
  String result3 = cstr1 + s2;
  std::cout << "const char* + String:" << std::endl;
  std::cout << result3.getBuf() << std::endl;
  std::string str2 = "world!";
  String result4 = s1 + str2;
  std::cout << "String + std::string:" << std::endl;
  std::cout << result4.getBuf() << std::endl;
  const char* cstr2 = "world!";
  String result5 = s1 + cstr2;
  std::cout << "String + const char*:" << std::endl;
  std::cout << result5.getBuf() << std::endl;
}