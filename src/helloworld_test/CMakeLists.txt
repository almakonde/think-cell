add_executable(helloworld_test)

target_sources(helloworld_test
PRIVATE
  main.cpp
  sayhello.test.cpp
)

target_compile_features(helloworld_test
PUBLIC
    cxx_std_17
)

target_link_libraries(helloworld_test
PRIVATE
  $<TARGET_OBJECTS:helloworld>
  ::Catch2
)

add_test("helloworld_test" helloworld_test.exe)