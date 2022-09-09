#define CATCH_CONFIG_MAIN

#include<catch2/catch.hpp>

#include "tarjan.h"

namespace circuits {

TEST_CASE("sanity check", "[tarjan]") {
Graph graph{};
REQUIRE_THROWS(tarjan(graph));
}

}
