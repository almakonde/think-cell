add_executable(helloworld_test)

target_sources(helloworld_test
PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/sayhello.test.cpp
)

target_link_libraries(helloworld_test
PRIVATE
  $<TARGET_OBJECTS:helloworld>
  ::Catch2
)

add_test("helloworld_test" helloworld_test.exe)