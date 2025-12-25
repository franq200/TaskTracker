find_package(Qt6 REQUIRED COMPONENTS Test Core)

add_executable(SessionTimerTests
    SessionTimerTest.cpp

    ../src/sessionTimer.cpp
    ../include/sessionTimer.h
)

target_include_directories(SessionTimerTests PRIVATE
    ../include
)

target_link_libraries(SessionTimerTests
    Qt6::Test
    Qt6::Core
)

set_target_properties(SessionTimerTests PROPERTIES
    AUTOMOC ON
)

add_test(NAME SessionTimerTests COMMAND SessionTimerTests)
