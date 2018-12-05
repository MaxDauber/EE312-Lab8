cmake_minimum_required(VERSION 3.12)
project(Lab8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug/sm_doc_set)

add_executable(Lab8
        cmake-build-debug/sm_doc_set/abf0704.txt
        cmake-build-debug/sm_doc_set/abf70402.txt
        cmake-build-debug/sm_doc_set/bef1121.txt
        cmake-build-debug/sm_doc_set/bgt221.txt
        cmake-build-debug/sm_doc_set/bmu5.txt
        cmake-build-debug/sm_doc_set/bwa248.txt
        cmake-build-debug/sm_doc_set/catchmeifyoucan.txt
        cmake-build-debug/sm_doc_set/ckh80.txt
        cmake-build-debug/sm_doc_set/ecu201.txt
        cmake-build-debug/sm_doc_set/edo14.txt
        cmake-build-debug/sm_doc_set/edo20.txt
        cmake-build-debug/sm_doc_set/edo26.txt
        cmake-build-debug/sm_doc_set/ehc229.txt
        cmake-build-debug/sm_doc_set/erk185.txt
        cmake-build-debug/sm_doc_set/esv254.txt
        cmake-build-debug/sm_doc_set/hal10.txt
        cmake-build-debug/sm_doc_set/hte42.txt
        cmake-build-debug/sm_doc_set/jrf1109.txt
        cmake-build-debug/sm_doc_set/prz100.txt
        cmake-build-debug/sm_doc_set/sra107.txt
        cmake-build-debug/sm_doc_set/sra119.txt
        cmake-build-debug/sm_doc_set/sra126.txt
        cmake-build-debug/sm_doc_set/sra31.txt
        cmake-build-debug/sm_doc_set/sra42.txt
        cmake-build-debug/sm_doc_set/tyc12.txt
        ___.cpp
        main.cpp
        hash.h
        )
