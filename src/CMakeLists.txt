set(SOURCE main.cpp window.cpp chain.cpp bone.cpp)
set(HEADERS window.h chain.h bone.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})
target_link_libraries(${PROJECT_NAME} SDL2)
