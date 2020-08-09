add_executable(map_utils_test)

target_sources(map_utils_test
PRIVATE
  main.cpp
  map_utils.test.cpp
  map_utils.cpp
  map_utils.h
)

target_link_libraries(map_utils_test
PRIVATE
  ::Catch2
)
