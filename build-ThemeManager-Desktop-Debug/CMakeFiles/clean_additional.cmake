# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ThemeManager_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ThemeManager_autogen.dir/ParseCache.txt"
  "ThemeManager_autogen"
  )
endif()
