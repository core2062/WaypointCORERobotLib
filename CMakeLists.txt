cmake_minimum_required(VERSION 3.3)
project(CORERobotLib)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES "src/*.*")
file(GLOB_RECURSE INCLUDES "src/*.*")
include_directories(src)

file(GLOB_RECURSE DEP_INCLUDES "3rdparty/json/src/*.*" "3rdparty/seasocks/src/main/c/*.*" "build/tmp/expandedArchives/CTRE-phoenix-cpp-5.2.1.1-headers.zip_ed51ae3396f2e2d306a9f6a233af2bce/*.*" "build/tmp/expandedArchives/navx-cpp-3.0.346-headers.zip_bdc8378de58d7490d517245a513e81b3/*.*" "build/tmp/expandedArchives/wpilibc-2018.2.2-headers.zip_2b481ef032541827aa05d34c722e7cda/*.*" "build/tmp/expandedArchives/hal-2018.2.2-headers.zip_eb4bfce635b238c6934d705223ab1444/*.*" "build/tmp/expandedArchives/wpiutil-cpp-3.0.0-headers.zip_71db4973bf73247f06ec3fdb86e1126b/*.*" "build/tmp/expandedArchives/ntcore-cpp-4.0.0-headers.zip_517391151665b6a51f10f788c06ee62d/*.*" "build/tmp/expandedArchives/cscore-cpp-1.1.0-headers.zip_7179d2a404841338b55673d83c119071/*.*" "build/tmp/expandedArchives/opencv-cpp-3.2.0-headers.zip_1b8591564854592a4aff6bd224b2b0a3/*.*" "build/tmp/expandedArchives/ni-libraries-2018.2.2-headers.zip_6aedc4b55a982775a7b6e16df1020d5b/*.*")
include_directories(3rdparty/json/src)
include_directories(3rdparty/seasocks/src/main/c)
include_directories(build/tmp/expandedArchives/CTRE-phoenix-cpp-5.2.1.1-headers.zip_ed51ae3396f2e2d306a9f6a233af2bce)
include_directories(build/tmp/expandedArchives/navx-cpp-3.0.346-headers.zip_bdc8378de58d7490d517245a513e81b3)
include_directories(build/tmp/expandedArchives/wpilibc-2018.2.2-headers.zip_2b481ef032541827aa05d34c722e7cda)
include_directories(build/tmp/expandedArchives/hal-2018.2.2-headers.zip_eb4bfce635b238c6934d705223ab1444)
include_directories(build/tmp/expandedArchives/wpiutil-cpp-3.0.0-headers.zip_71db4973bf73247f06ec3fdb86e1126b)
include_directories(build/tmp/expandedArchives/ntcore-cpp-4.0.0-headers.zip_517391151665b6a51f10f788c06ee62d)
include_directories(build/tmp/expandedArchives/cscore-cpp-1.1.0-headers.zip_7179d2a404841338b55673d83c119071)
include_directories(build/tmp/expandedArchives/opencv-cpp-3.2.0-headers.zip_1b8591564854592a4aff6bd224b2b0a3)
include_directories(build/tmp/expandedArchives/ni-libraries-2018.2.2-headers.zip_6aedc4b55a982775a7b6e16df1020d5b)
set(ALL_INCLUDES ${INCLUDES} ${DEP_INCLUDES})

add_executable(fake_libCORERobotLib.so ${SOURCES} ${ALL_INCLUDES})

add_custom_target(libCORERobotLib.so_build gradlew.bat build WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
add_custom_target(libCORERobotLib.so_deploy gradlew.bat deploy WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
file(GLOB_RECURSE SOURCES "src/*.*" "test/*.*")
file(GLOB_RECURSE INCLUDES "src/*.*" "src/CORESimulation/*.*")
include_directories(src)
include_directories(src/CORESimulation)

file(GLOB_RECURSE DEP_INCLUDES "3rdparty/wpilib/include/*.*" "3rdparty/json/src/*.*" "3rdparty/googletest/googletest/include/*.*" "3rdparty/googletest/googlemock/include/*.*" "src/*.*" "src/CORESimulation/*.*")
include_directories(3rdparty/wpilib/include)
include_directories(3rdparty/json/src)
include_directories(3rdparty/googletest/googletest/include)
include_directories(3rdparty/googletest/googlemock/include)
include_directories(src)
include_directories(src/CORESimulation)
set(ALL_INCLUDES ${INCLUDES} ${DEP_INCLUDES})

add_executable(fake_CORERobotLibTest.dll ${SOURCES} ${ALL_INCLUDES})

add_custom_target(CORERobotLibTest.dll_build gradlew.bat build WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
add_custom_target(CORERobotLibTest.dll_deploy gradlew.bat deploy WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
