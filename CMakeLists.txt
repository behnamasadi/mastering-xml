cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_BUILD_TYPE DEBUG)


project(mastering-xml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


message("\n########################################## LibXslt ##########################################\n")
#find_package(LibXslt)

# if(${LibXslt_FOUND})
#     MESSAGE("LibXslt_FOUND:" ${LibXslt_FOUND})
#     MESSAGE("LibXslt_VERSION:" ${LibXslt_VERSION})
#     MESSAGE("LIBXSLT_XSLTPROC_EXECUTABLE:" ${LIBXSLT_XSLTPROC_EXECUTABLE})
#     MESSAGE("LIBXSLT_EXSLT_LIBRARIES:" ${LIBXSLT_EXSLT_LIBRARIES})
#     add_executable(libxslt_demo src/libxslt_demo.cpp)
#     target_link_libraries(libxslt_demo  ${LIBXSLT_EXSLT_LIBRARIES})
# else()
# 	message("LibXslt not found")
# endif()





find_package(PkgConfig)

message("\n########################################## tinyxml2 ##########################################\n")
pkg_check_modules(TINYXML2 tinyxml2)
if(${TINYXML2_FOUND})
    MESSAGE("TINYXML2_FOUND:" ${TINYXML2_FOUND})
    MESSAGE("TINYXML2_VERSION:" ${TINYXML2_VERSION})
    MESSAGE("TINYXML2_LIBRARIES:" ${TINYXML2_LIBRARIES})
    add_executable(tinyxml2_demo src/tinyxml2_demo.cpp)
    target_link_libraries(tinyxml2_demo ${TINYXML2_LIBRARIES})
else()
	message("tinyxml2 not found")
endif()




message("\n########################################## LibXml2 ##########################################\n")
find_package(LibXml2)

if(${LibXslt_FOUND})
	MESSAGE("LibXml2_FOUND:" ${LibXml2_FOUND})
	MESSAGE("LIBXML2_INCLUDE_DIR:" ${LIBXML2_INCLUDE_DIR})
	MESSAGE("LIBXML2_INCLUDE_DIRS:" ${LIBXML2_INCLUDE_DIRS})
	MESSAGE("LIBXML2_LIBRARIES:" ${LIBXML2_LIBRARIES})
	MESSAGE("LIBXML2_DEFINITIONS:" ${LIBXML2_DEFINITIONS})
	MESSAGE("LIBXML2_XMLLINT_EXECUTABLE:" ${LIBXML2_XMLLINT_EXECUTABLE})
	MESSAGE("LIBXML2_VERSION_STRING:" ${LIBXML2_VERSION_STRING})
	add_executable(libxml2_demo src/libxml2_demo.cpp)
	target_link_libraries(libxml2_demo ${LIBXML2_LIBRARIES})
else()
	message("LibXml2 not found")
endif()






message("\n########################################## XercesC ##########################################\n")
find_package(XercesC)

if(${LibXslt_FOUND})
	MESSAGE("XercesC_FOUND:" ${XercesC_FOUND})
	MESSAGE("XercesC_VERSION:" ${XercesC_VERSION})
	MESSAGE("XercesC_INCLUDE_DIRS:" ${XercesC_INCLUDE_DIRS})
	MESSAGE("XercesC_LIBRARIES:" ${XercesC_LIBRARIES})
	add_executable(xerces_c_demo src/xerces_c_demo.cpp)
	target_link_libraries(xerces_c_demo ${XercesC_LIBRARIES})
else()
	message("XercesC not found")
endif()





message("\n########################################## XalanC ##########################################\n")
find_package(XalanC)

if(${LibXslt_FOUND})
	MESSAGE("XalanC_FOUND:" ${XalanC_FOUND})
	MESSAGE("XalanC_VERSION:" ${XalanC_VERSION})
	MESSAGE("XalanC_INCLUDE_DIRS:" ${XalanC_INCLUDE_DIRS})
	MESSAGE("XalanC_LIBRARIES:" ${XalanC_LIBRARIES})
	add_executable(xalan_c_demo src/xalan_c_demo.cpp)
	target_link_libraries(xalan_c_demo ${XercesC_LIBRARIES})
else()
	message("XalanC not found")
endif()

message("\n########################################## XQilla ##########################################\n")

message("\n########################################## opensp ##########################################\n") 









