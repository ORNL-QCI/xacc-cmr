project(xacc-dwsapi-embedding CXX)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

if(APPLE)
   set(CMAKE_MACOSX_RPATH 1)
endif()
   
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

if (NOT DWSAPI_ROOT) 
   set (DWSAPI_ROOT /usr/local)
endif()

if (NOT EXISTS ${DWSAPI_ROOT}/include/dwave_sapi.h)
  message(FATAL_ERROR "Cannot build without D-Wave C Header and Library")
endif()

find_package (XACC REQUIRED)

set(CppMicroServicesConfig_DIR "${XACC_ROOT}/share/cppmicroservices3/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${XACC_ROOT}/share/xacc")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CppMicroServicesConfig_DIR}")
include(tests)
include(CppMicroServicesConfig)

include_directories(${XACC_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(embedding)

