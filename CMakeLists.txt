cmake_minimum_required(VERSION 3.21)
project(Assignment_4___Linked_List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_4___Linked_List
        Ledger.cpp
        Ledger.h
        LedgerDriver.cpp
        Node.cpp
        Node.h
        State.cpp
        State.h
        Transaction.cpp
        Transaction.h)
