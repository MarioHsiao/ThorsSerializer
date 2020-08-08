#include "SerializeConfig.h"
#include "gtest/gtest.h"
#include "JsonThor.h"
#include "BsonThor.h"
#include <sstream>
#include <string>


TEST(EscapeControl, JsonNormalInput)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"String With no special characters\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::jsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, true);
}
TEST(EscapeControl, JsonInputContainsTab)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\t A string with A tab\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::jsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, JsonInputContainsBS)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\b A string with A Back Space\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::jsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, JsonInputContainsNL)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\n A string with A New Line\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::jsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, JsonInputContainsFF)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\f A string with A Form Feed\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::jsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, JsonInputContainsCR)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\r A string with A Carridge Return\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::jsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, JsonOutputContainsTab)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\t A string with A tab");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::jsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 't');
}
TEST(EscapeControl, JsonOutputContainsBS)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\b A string with A Back Space");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::jsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'b');
}
TEST(EscapeControl, JsonOutputContainsNL)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\n A string with A New Line");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::jsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'n');
}
TEST(EscapeControl, JsonOutputContainsFF)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\f A string with A Form Feed");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::jsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'f');
}
TEST(EscapeControl, JsonOutputContainsCR)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\r A string with A Carridge Return");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::jsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'r');
}

TEST(EscapeControl, BsonNormalInput)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"String With no special characters\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::bsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, true);
}
TEST(EscapeControl, BsonInputContainsTab)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\t A string with A tab\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::bsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, BsonInputContainsBS)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\b A string with A Back Space\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::bsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, BsonInputContainsNL)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\n A string with A New Line\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::bsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, BsonInputContainsFF)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\f A string with A Form Feed\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::bsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, BsonInputContainsCR)
{
    using ThorsAnvil::Serialize::ParserInterface;
    std::stringstream   input("\"\r A string with A Carridge Return\"");
    std::string         value;
    bool                importDone = false;

    if (input >> ThorsAnvil::Serialize::bsonImporter(value, ParserInterface::ParseType::Weak)) {
        importDone = true;
    }
    EXPECT_EQ(importDone, false);
}
TEST(EscapeControl, BsonOutputContainsTab)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\t A string with A tab");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::bsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 't');
}
TEST(EscapeControl, BsonOutputContainsBS)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\b A string with A Back Space");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::bsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'b');
}
TEST(EscapeControl, BsonOutputContainsNL)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\n A string with A New Line");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::bsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'n');
}
TEST(EscapeControl, BsonOutputContainsFF)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\f A string with A Form Feed");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::bsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'f');
}
TEST(EscapeControl, BsonOutputContainsCR)
{
    using ThorsAnvil::Serialize::PrinterInterface;
    std::string         value("\r A string with A Carridge Return");
    std::stringstream   output;
    bool                exportDone = false;

    if (output << ThorsAnvil::Serialize::bsonExporter(value, PrinterInterface::OutputType::Default)) {
        exportDone = true;
    }
    EXPECT_EQ(exportDone, true);
    EXPECT_EQ(output.str().find('\t'), std::string::npos);
    auto find = output.str().find('\\');
    ASSERT_NE(find, std::string::npos);
    EXPECT_EQ(output.str()[find+1], 'r');
}

