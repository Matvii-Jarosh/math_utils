cmake_minimum_required(VERSION 3.16)

project(2d_line_len VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(2d_line_len MANUAL_FINALIZATION main.cpp)
else()
    if(ANDROID)
        add_library(2d_line_len SHARED main.cpp)
    else()
        add_executable(2d_line_len main.cpp)
    endif()
endif()

target_link_libraries(2d_line_len PRIVATE Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 2d_line_len
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(2d_line_len PROPERTIES MACOSX_BUNDLE FALSE)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(2d_line_len)
endif()
