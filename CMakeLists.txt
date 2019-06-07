cmake_minimum_required(VERSION 3.10)
project(VikTek2d)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Vik_Wrap REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${VIK_WRAP_INCLUDE_DIR} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

# add_library(${PROJECT_NAME})


add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Scene.cpp)

if (MINGW)
        set(LIBRARIES -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lVik_Wrap)
elseif (UNIX)
        set(LIBRARIES ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${VIK_WRAP_LIBRARY})
endif()

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})