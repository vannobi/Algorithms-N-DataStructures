#pragma once
#include <chrono>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string SETTINGS_PATH = "./utils/number-settings.txt";
std::string RANDOM_PATH = "./utils/random/";

class Timer {
 public:
  Timer(double* p) {
    res = p;
    m_StartTime = std::chrono::high_resolution_clock::now();
  }
  ~Timer() { Stop(); }
  void Stop() {
    auto endTime = std::chrono::high_resolution_clock::now();
    auto start =
        std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTime)
            .time_since_epoch()
            .count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime)
                   .time_since_epoch()
                   .count();
    auto duration = end - start;
    double ms = duration * .001;
    *res = ms / 1000;
    // std::cout << ms << "ms\n";
    std::cout << ms / 1000 << " sec\n";
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
  double* res;
};

template <typename T>
void printLn(std::vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    if (i + 1 != vec.size()) {
      std::cout << vec[i] << ',';
    } else {
      std::cout << vec[i] << '\n';
    }
  }
}
template <typename T>
void printLn(std::vector<T>& vec, std::string& buff) {
  for (size_t i = 0; i < vec.size(); i++) {
    std::ostringstream ss;
    ss << std::scientific << std::setprecision(3) << vec[i];
    buff += ss.str();
    if (i + 1 != vec.size()) {
      buff += ',';
    } else {
      buff += '\n';
    }
  }
}
void printLn(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

auto readSettings() -> std::vector<int> {
  int num;
  std::ifstream settings(SETTINGS_PATH.c_str());
  settings >> num;
  std::vector<int> res(num);
  for (auto& i : res) {
    settings >> i;
  }
  settings.close();
  return res;
}

auto getNextArray(int size, int currCycle) -> int* {
  int* nextArr = new int[size];
  // std::cout << "gen size : " << size << '\n';
  std::string path = RANDOM_PATH + std::to_string(size) + "-" +
                     std::to_string(currCycle) + ".txt";

  // std::cout << path << '\n';

  std::ifstream NumReader(path.c_str());
  for (int i = 0; i < size; i++) {
    NumReader >> nextArr[i];
  }
  NumReader.close();
  return nextArr;
}