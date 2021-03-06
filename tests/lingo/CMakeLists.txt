# Create executable
add_executable(test_lingo)
set_target_properties(test_lingo PROPERTIES FOLDER Tests)

# Add settings
target_compile_definitions(test_lingo PRIVATE "LINGO_SPEC_DIRECTORY=\"${LINGO_SPEC_DIRECTORY}\"")

# Add dependencies
target_link_libraries(test_lingo test_main lingo)
target_include_directories(test_lingo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

# Add sources
set(TEST_LINGO_SOURCES)
list(APPEND TEST_LINGO_SOURCES "test_types.hpp" "test_case.hpp" "test_strings.hpp" "tuple_matrix.hpp")

# Platform
list(APPEND TEST_LINGO_SOURCES "platform/endian.cpp")

# Encoding
list(APPEND TEST_LINGO_SOURCES "encoding/endian.cpp")
list(APPEND TEST_LINGO_SOURCES "encoding/utf8.cpp")
list(APPEND TEST_LINGO_SOURCES "encoding/utf16.cpp")
list(APPEND TEST_LINGO_SOURCES "encoding/utf32.cpp")

# Pages
list(APPEND TEST_LINGO_SOURCES "page/ascii.cpp")
list(APPEND TEST_LINGO_SOURCES "page/iso_8859.cpp")
list(APPEND TEST_LINGO_SOURCES "page/unicode.cpp")

# Strings
list(APPEND TEST_LINGO_SOURCES "string.cpp")
list(APPEND TEST_LINGO_SOURCES "string_view.cpp")
list(APPEND TEST_LINGO_SOURCES "string_converter.cpp")

target_sources(test_lingo PRIVATE ${TEST_LINGO_SOURCES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${TEST_LINGO_SOURCES})

# Discover tests
catch_discover_tests(test_lingo)