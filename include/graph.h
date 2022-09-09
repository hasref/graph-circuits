#pragma once

#include <initializer_list>
#include <vector>
#include <cstddef>

namespace circuits {

struct vertex {
  std::size_t id{};
};

struct edge{
  vertex from{};
  vertex to{};
};

class Graph {
  public:
  Graph() = default;
  private:
  std::vector<vertex> vertices_;
  std::vector<edge> edges_;
};

}
