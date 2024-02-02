cmake_minimum_required(VERSION 3.16)
project(sfmlflappybird LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(SOURCES 
    src/main.cpp
    src/Player.h
    src/Player.cpp
    src/PipeManager.h
    src/PipeManager.cpp
    src/Pipe.h
    src/Pipe.cpp
)

# Set the desired project name and executable name
add_executable(flappybird ${SOURCES})
target_link_libraries(flappybird PRIVATE sfml-graphics)
target_compile_features(flappybird PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET flappybird
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:flappybird>
        VERBATIM)
endif()

install(TARGETS flappybird)
