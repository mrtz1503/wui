cmake_minimum_required(VERSION 3.14)
project(wui VERSION 1.0.0 LANGUAGES CXX)


# options
option(WUI_BUILD_EXAMPLES "Build example" ON)



###########  ###########

# SOURCE_FILES
set(SOURCE_FILES
    Application.cpp
    ApplicationConfig.cpp
    Window.cpp
    Event.cpp
    SystemDriver.cpp
    Utils.cpp
    MainWindow.cpp

    Definition.h

)

if (WIN32)
    set(PLATFORM_SOURCES
        Win32_Error.cpp
        Win32_Init.cpp
        Win32_SystemDriver.cpp
        Win32_WindowDriver.cpp
    )

    list(TRANSFORM PLATFORM_SOURCES PREPEND "src/platform/win/")

endif()



list(TRANSFORM SOURCE_FILES PREPEND "src/")


add_library(${PROJECT_NAME} ${SOURCE_FILES} ${PLATFORM_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(wui
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)





if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    DEBUG_POSTFIX "d"
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
    CMAKE_CXX_EXTENSIONS OFF
)


#################### Installation instructions ####################


include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


# Export the targets to a script
install(EXPORT ${PROJECT_NAME}-targets
    FILE 
        ${PROJECT_NAME}Targets.cmake
    NAMESPACE 
        ${PROJECT_NAME}::
    DESTINATION 
        ${INSTALL_CONFIGDIR}
)


include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CMake/Config.cmake.in
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)


#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)




export(EXPORT ${PROJECT_NAME}-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::)

#Register package in the User Package Registry
export(PACKAGE ${PROJECT_NAME})



if(WUI_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()




