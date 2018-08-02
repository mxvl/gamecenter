cmake_minimum_required(VERSION 3.10.2)
project(gamecenter)
set(gamecenter_VERSION_MAJOR 0)
set(gamecenter_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/src/gamecenterConfig.h.in"
	"${PROJECT_BINARY_DIR}/src/gamecenterConfig.h"
	)

find_package(Curses REQUIRED)
set(ADDITIONAL_LIBRARIES menu)

file(GLOB SOURCES src/*.cpp src/game/rubik/*.cpp src/logic/signalHandling/*.cpp src/ui/*/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURSE_LIBRARIES} ${ADDITIONAL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES} ${ADDITIONAL_LIBRARIES})
