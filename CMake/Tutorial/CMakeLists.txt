cmake_minimum_required (VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

# projectname is the same as the main-executable
project(Tutorial VERSION 1.0)
SET(NAME "${PROJECT_NAME}" CACHE STRING "Project name passed as executable name")

configure_file(TutorialConfig.h.in TutorialConfig.h)
add_definitions('-g')
add_definitions('-Wall')
add_definitions('-std=c++17')

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -DNAME:STRING=${PROJECT_NAME} -P elfclean.cmake
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running termux-elf-cleaner..."
  )

set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_SOURCE_DIR}/${PROJECT_NAME})
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
