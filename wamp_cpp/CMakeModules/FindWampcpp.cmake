###############################################################################
#
# Variables set by the module:
# WAMPCPPLIB_FOUND    - TRUE if all components are found
# WAMPCPP_INCLUDE_DIR  - Location of the include directory
# WAMPCPP_LIBRARY_DIR  - Location of the library directory
# WAMPCPP_LIBRARY      - libinkubator (needed for linking)
#
# Example Usages:
#
# FIND_PACKAGE(wampcpp)
#
###############################################################################

# Handles standard arguments
include(FindPackageHandleStandardArgs)



# find the include directories.
 # only look in default directories
find_path(
  WAMPCPP_INCLUDE_DIR
  NAMES wamp_cpp/WAMPServer.h
  HINTS
   /usr/include
  DOC "wamp_cpp include dir"
 )


find_library(
  WAMPCPP_LIBRARY
  NAMES wamp_cpp
  DOC "wamp_cpp library"
)

set(WAMPCPP_INCLUDE_DIRS ${WAMPCPP_INCLUDE_DIR})
set(WAMPCPP_LIBRARIES ${WAMPCPP_LIBRARY})

# Check that all files and directories were properly found
find_package_handle_standard_args (
  WAMPCPPLIB 
  DEFAULT_MSG
  WAMPCPPLIB_ROOT_DIR
  WAMPCPP_INCLUDE_DIR
  WAMPCPP_LIBRARY 
)

get_filename_component(
  WAMPCPP_LIBRARY_DIR 
  ${WAMPCPP_LIBRARY} 
  PATH
)

mark_as_advanced(
  WAMPCPP_INCLUDE_DIR
  WAMPCPP_LIBRARY_DIR
  WAMPCPP_LIBRARY
)