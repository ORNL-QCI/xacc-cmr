set (PACKAGE_NAME "XACC D-Wave SAPI Embedding Algorithm")
set (PACKAGE_DESCRIPTION "XACC Embedding Algorithm that delegates to D-Wave SAPI C library")

set (LIBRARY_NAME xacc-dwsapi-embedding)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file (GLOB HEADERS *.hpp)
file (GLOB SRC *.cpp)

add_library(${LIBRARY_NAME} SHARED ${SRC})

set (DWAVESAPILIB ${DWSAPI_ROOT}/lib/libdwave_sapi.so)

target_link_libraries(${LIBRARY_NAME} ${Boost_LIBRARIES} ${XACC_LIBRARIES} ${DWAVESAPILIB})

install(TARGETS ${LIBRARY_NAME} DESTINATION ${XACC_LIBRARY_DIR})

file (GLOB test_files tests/*.cpp)
add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${Boost_LIBRARIES};${LIBRARY_NAME};pthread;dl")

