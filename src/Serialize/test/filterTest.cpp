#include "SerializeConfig.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Traits.h"
#include "JsonThor.h"
#include "SerUtil.h"
#include "filterTest.h"

using namespace ThorsAnvil::Serialize;

TEST(FilterTes, BasicFilter)
{
    using ThorsAnvil::Serialize::jsonImporter;
    using ThorsAnvil::Serialize::jsonExporter;

    std::ifstream       jsonStrem("test/data/large.json");
    std::vector<::Data>   value;
    jsonStrem >> jsonImporter(value);
    EXPECT_EQ(1, value.size());
}

TEST(FilterTes, ManualFilter)
{
    using ThorsAnvil::Serialize::jsonImporter;
    using ThorsAnvil::Serialize::jsonExporter;

    std::ifstream       jsonStrem("test/data/large.single.json");
    std::vector<::Data> value;
    Data                result;
    while(jsonStrem >> jsonImporter(result)) {
        if (result._id == "5cff620c48229f7d88fc620d") {
            value.emplace_back(std::move(result));
        }
    }
    EXPECT_EQ(1, value.size());
}

