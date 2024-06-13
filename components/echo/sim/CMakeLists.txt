project(echo_sim)

find_package(ITC_Common REQUIRED QUIET COMPONENTS itc_logger)
find_package(NOSENGINE REQUIRED QUIET COMPONENTS common transport client uart)

include_directories(inc
                    ${sim_common_SOURCE_DIR}/inc
                    ${ITC_Common_INCLUDE_DIRS}
                    ${NOSENGINE_INCLUDE_DIRS})

set(echo_sim_src
    src/echo_hardware_model.cpp
    src/echo_42_data_provider.cpp
    src/echo_data_provider.cpp
    src/echo_data_point.cpp
)

# For Code::Blocks and other IDEs
file(GLOB echo_sim_inc inc/*.hpp)

set(echo_sim_libs
    sim_common
    ${ITC_Common_LIBRARIES}
    ${NOSENGINE_LIBRARIES}
)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:$ORIGIN/../lib") # Pick up .so in install directory

add_library(echo_sim SHARED ${echo_sim_src} ${echo_sim_inc})
target_link_libraries(echo_sim ${echo_sim_libs})
install(TARGETS echo_sim LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
