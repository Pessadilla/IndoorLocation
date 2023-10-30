cmake_minimum_required(VERSION 3.16)

project(IndoorLocation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appIndoorLocation
    main.cpp
)

qt_add_qml_module(appIndoorLocation
    URI IndoorLocation
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES Functions/circleintersection.h Functions/circleintersection.cpp
    SOURCES Functions/trianglecenter.h Functions/trianglecenter.cpp
    SOURCES
    SOURCES Functions/pointcomparer.h Functions/pointcomparer.cpp
    SOURCES Functions/findcoordinate.h Functions/findcoordinate.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appIndoorLocation PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appIndoorLocation
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appIndoorLocation
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appIndoorLocation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
