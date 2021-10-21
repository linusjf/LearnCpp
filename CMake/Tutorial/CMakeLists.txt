cmake_minimum_required (VERSION 3.10)

# projectname is the same as the main-executable
project(Tutorial VERSION 1.0)
SET(NAME "${PROJECT_NAME}" CACHE STRING "Project name passed as executable name")
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)
add_definitions('-g')
add_definitions('-Wall')
add_definitions('-std=c++17')

set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_SOURCE_DIR}/${PROJECT_NAME})

if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions/libMathFunctions.a)
endif()

# add the executable
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -DNAME:STRING=${PROJECT_NAME} -P elfclean.cmake
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running termux-elf-cleaner..."
  )
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

