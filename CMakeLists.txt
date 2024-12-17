cmake_minimum_required(VERSION 3.27)
project(jobSearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(jobSearch
        User.cpp
        User.h
        Candidate.cpp
        Candidate.h
        Employer.cpp
        Employer.h
        Jobs.cpp
        Jobs.h
        Application.cpp
        Application.h
        main.cpp)
