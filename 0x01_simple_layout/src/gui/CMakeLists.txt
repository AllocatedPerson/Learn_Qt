set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(GUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/maincontentswidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/common/scrollablevlistwidget.cpp)


add_library(gui SHARED ${GUI_SOURCES})

target_link_libraries(gui PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
