# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/dani/esp/esp-idf/components/bootloader/subproject"
  "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader"
  "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix"
  "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix/tmp"
  "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix/src/bootloader-stamp"
  "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix/src"
  "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/dani/github/rgb_matrix/rgb_matrix/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
