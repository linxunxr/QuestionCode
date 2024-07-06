/**
 * Copyright (C), 2024-07-04
 * @author LinXun
 * @date 24-7-4 上午9:04
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
using namespace std;
int main() {
 int a, b;
 while (std::cin >> a >> b) {
  if (a == 0 && b == 0) {
   break;
  }
  cout << a + b << endl;
 }
}
