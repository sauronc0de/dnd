#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>

#include <boost/hana.hpp>
#include <nlohmann/json.hpp>

namespace hana = boost::hana;

namespace JsonIO {
// Generic serialization using Boost.Hana
template <typename T>
void to_json(nlohmann::json& j, T const& obj) {
  hana::for_each(hana::keys(obj), [&](auto key) {
    auto name = hana::to<const char*>(key);
    j[name] = hana::at_key(obj, key);
  });
}

template <typename T>
void from_json(nlohmann::json const& j, T& obj) {
  T def{}; // default-constructed value

  hana::for_each(hana::keys(obj), [&](auto key) {
    auto name = hana::to<const char*>(key);
    using ValueT = std::decay_t<decltype(hana::at_key(obj, key))>;

    if (j.contains(name)) {
      hana::at_key(obj, key) = j.at(name).template get<ValueT>();
    } else {
      // Automatically use the default value for missing fields
      hana::at_key(obj, key) = hana::at_key(def, key);
    }
  });
}

template <typename T>
T loadJsonFile(std::string const& path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open: " + path);
  }

  nlohmann::json j;
  file >> j;

  return j.get<T>();
}

template <typename T>
std::vector<std::pair<std::string, T>> loadAllFromDir(std::string const& dirPath) {
  std::vector<std::pair<std::string, T>> out;

  for (auto const& entry : std::filesystem::directory_iterator(dirPath)) {
    if (!entry.is_regular_file()) {
      continue;
    }

    auto path = entry.path().string();
    try {
      T obj = loadJsonFile<T>(path);
      out.emplace_back(path, std::move(obj));
    } catch (std::exception const& e) {
      // std::cerr << "❌ Failed to load " << path << ": " << e.what() << std::endl;
    }
  }
  return out;
}

template <typename T>
void print_struct(T const& obj) {
  std::cout << "{ ";
  bool first = true;
  hana::for_each(hana::keys(obj), [&](auto key) {
    if (!first) {
      std::cout << ", ";
    }
    first = false;

    auto name = hana::to<const char*>(key);
    std::cout << name << ": " << hana::at_key(obj, key);
  });
  std::cout << " }" << std::endl;
}

template <typename T>
bool overwrite(std::string filePath, T json_struct) {
  // Overwrite the file
  std::ofstream outFile(filePath);
  if (!outFile) {
    std::cerr << "❌ Failed to open file for writing: " << filePath << "\n";
    return 1;
  }

  nlohmann::json j = json_struct;
  outFile << j.dump(2) << "\n";

  // std::cout << "✅ Overwritten file with updated AAA at: " << filePath << "\n";

  return 0;
}

#define JSON_IO_STRUCT(NAME, ...)                             \
  struct NAME {                                               \
    BOOST_HANA_DEFINE_STRUCT(NAME, __VA_ARGS__);              \
  };                                                          \
  inline void to_json(nlohmann::json& j, NAME const& obj) {   \
    JsonIO::to_json(j, obj);                                  \
  }                                                           \
  inline void from_json(nlohmann::json const& j, NAME& obj) { \
    JsonIO::from_json(j, obj);                                \
  }
} // namespace JsonIO