#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Ramen::ramen" for configuration ""
set_property(TARGET Ramen::ramen APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Ramen::ramen PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libramen.a"
  )

list(APPEND _cmake_import_check_targets Ramen::ramen )
list(APPEND _cmake_import_check_files_for_Ramen::ramen "${_IMPORT_PREFIX}/lib/libramen.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
