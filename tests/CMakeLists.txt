FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4)
FetchContent_MakeAvailable(Catch2)

#### Combined unittest

if((CMAKE_PROJECT_NAME STREQUAL hashmap OR MODERN_CMAKE_BUILD_TESTING))
  set (TEST "test-all")
  file(GLOB SRC_LIST CONFIGURE_DEPENDS "src/*.cpp")
  
  add_executable(${TEST}.bin ${SRC_LIST})
  target_compile_features(${TEST}.bin PRIVATE cxx_std_14)
  target_link_libraries(${TEST}.bin PRIVATE Catch2::Catch2WithMain)
  target_link_libraries(${TEST}.bin PRIVATE pair)
  add_test(NAME ${TEST}
  		COMMAND ${TEST}.bin)
endif()

#### Individual unittests

### Hashmap unittest
set (TEST "test-pair")
set (SRC_LIST "src/pair.cpp")

add_executable(${TEST}.bin ${MAIN} ${SRC_LIST})
target_compile_features(${TEST}.bin PRIVATE cxx_std_14)
target_link_libraries(${TEST}.bin PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${TEST}.bin PRIVATE pair)
add_test(NAME ${TEST}
		COMMAND ${TEST}.bin)

