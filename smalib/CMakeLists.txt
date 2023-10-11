project(smalib)

set(SOURCE_FILES sma.cpp)
set(HEADER_FILES sma.h)

add_library(smalib_lib ${SOURCE_FILES} ${HEADER_FILES})
