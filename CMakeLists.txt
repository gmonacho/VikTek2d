cmake_minimum_required(VERSION 3.10)
project(VikTek2d)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Vik_Wrap REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/graphic
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/input
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/physic
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/messageBox
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/lvik
                    ${VIK_WRAP_INCLUDE_DIR}
                    ${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

# add_library(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
        src/graphic/Sprite.cpp
        src/graphic/Camera.cpp
        src/graphic/Text.cpp
        src/graphic/Scene.cpp
        src/physic/Object.cpp
        src/lvik/vikString.cpp
        src/main.cpp)


set(LIBRARIES -L/${VIK_WRAP_LIBRARY_DIR} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${VIK_WRAP_LIBRARY})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})