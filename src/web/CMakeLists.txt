# -*- cmake -*-

project(
    "MyFCGIApp"
    VERSION 0.1
    DESCRIPTION "Fast CGI template"
    LANGUAGES CXX
)

set(BINARY_NAME "${PROJECT_NAME}.${CMAKE_SYSTEM_PROCESSOR}")

set(CMAKE_CXX_STANDARD 11)
set(BoostCGI_USED_CXX_FEATURES cxx_auto_type)

find_package(Boost COMPONENTS filesystem thread iostreams date_time system unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

include_directories(
    "${CMAKE_MODULE_PATH}/cgi"
)

include_directories(
    "${CMAKE_MODULE_PATH}/common"
)

set(SOURCE_FILES
    main.cpp
)

set(HEADER_FILES
    main.h
)

list(APPEND SOURCE_FILES ${HEADER_FILES})

add_executable(${BINARY_NAME} ${SOURCE_FILES})
target_link_libraries(${BINARY_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

configure_file(main.in "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}" COPYONLY @ONLY)