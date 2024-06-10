# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RouletteGambleSimulator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RouletteGambleSimulator_autogen.dir\\ParseCache.txt"
  "RouletteGambleSimulator_autogen"
  )
endif()
