# ----------------------
# Add and Link libraries
# ----------------------
add_subdirectory(hello)
add_subdirectory(snowflake)
add_subdirectory(leetcode)
add_subdirectory(data_structure)

# Add Cpp files
add_library(cpp_project_example_library SHARED ${ALL_OBJECT_FILES}
        ../include/leetcode/climbing_stairs.h
        ../include/db_engine/db_runner.hpp
        ../include/db_engine/db_runner.hpp
        ../include/db_engine/db_runner.cpp
        ../include/db_engine/db_runner.hpp
        ../include/db_engine/db_runner.hpp
        ../include/db_engine/lrucache.hpp)

# Add Hpp files
target_include_directories(
    cpp_project_example_library
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Add external libraries
#target_link_libraries(duckdb ${WHITEBOX_LINK_LIBS})

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
