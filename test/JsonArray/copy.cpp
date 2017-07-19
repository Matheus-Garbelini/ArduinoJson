// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("DynamicJsonArray::operator=()") {
  DynamicJsonArray array;

  SECTION("operator=(const StaticJsonArray<N>&)") {
    array.add(666);

    {
      StaticJsonArray<JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(1)> prototype;
      prototype.add(42);
      prototype.createNestedObject()["hello"] = "world";

      array = prototype;
    }

    CHECK(array.size() == 2);
    REQUIRE(array[0] == 42);
    REQUIRE(array[1].is<JsonObject>());
    REQUIRE(array[1]["hello"] == std::string("world"));
  }
}