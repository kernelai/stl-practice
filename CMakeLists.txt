cmake_minimum_required(VERSION 3.14)
project(stl-practice VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

# unit test
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
if(ENABLE_UNIT_TESTS)
  #download gtest
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
  enable_testing()
  add_executable(
    main_test
    initializer_list.h
    initializer_list.cpp
    initializer_list_test.cpp
  )
  target_link_libraries(
    main_test
    gtest_main
  )
  
  include(GoogleTest)
  gtest_discover_tests(main_test)
endif()

# executable target
set(SOURCES
  main.cpp 
  )
add_executable(stl-pratice ${SOURCES})

# benchmark
#add_subdirectory(third-party/benchmark)
#add_executable(hello_bm
#  hello_bm.cpp
#  hello.h
#  hello.cpp)
#target_link_libraries(hello_bm benchmark::benchmark )

# package
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
