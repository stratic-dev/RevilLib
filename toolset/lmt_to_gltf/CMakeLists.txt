project(LMT2GLTF)

build_target(
  NAME
  lmt_to_gltf
  TYPE
  ESMODULE
  VERSION
  1
  SOURCES
  lmt_to_gltf.cpp
  animengine.cpp
  LINKS
  revil-interface
  gltf-interface
  AUTHOR
  "Lukas Cone"
  DESCR
  "MTF LMT to GLTF"
  START_YEAR
  2022)

if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
  target_compile_options(lmt_to_gltf PRIVATE -frelaxed-template-template-args)
endif()

project(LMT2JSON)

build_target(
  NAME
  lmt_to_json
  TYPE
  ESMODULE
  VERSION
  1
  SOURCES
  lmt_to_json.cpp
  LINKS
  revil-interface
  gltf-interface
  AUTHOR
  "Lukas Cone"
  DESCR
  "MTF LMT to JSON"
  START_YEAR
  2022)
