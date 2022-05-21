cmake_minimum_required(VERSION 3.22)

project(balandis VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

function(add)
    set(prefix          ARG)
    set(no_values       TEST)
    set(single_values   TARGET)
    set(multi_values    SOURCES LIBS FLAGS)

    cmake_parse_arguments(${prefix}
                          "${no_values}"
                          "${single_values}"
                          "${multi_values}"
                          ${ARGN}
                          )

    if(ARG_TEST)
        add_executable(${ARG_TARGET} test/${ARG_TARGET}.cpp ${ARG_SOURCES})

        add_test(NAME       ${ARG_TARGET}
                 COMMAND    ${ARG_TARGET}
                 )
    else()
        add_executable(${ARG_TARGET} src/${ARG_TARGET}.cpp ${ARG_SOURCES})
    endif()

    foreach(LIB "${ARG_LIBS}")
        target_link_libraries(${ARG_TARGET} PRIVATE ${LIB})
    endforeach()
endfunction()

add(TARGET balandis 
    FLAGS -Wall
    LIBS glfw GL
    SOURCES src/Engine.cpp src/Window.cpp src/Renderer.cpp
    )