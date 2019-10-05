# C-Containers

A collection of dynamic containers written in C modeled after the .NET Generic Collections (albeit with a lot less capability!)

## The Containers

All containers in this library are dynamically allocated using a Create function and deallocated using Destroy.
Items are stored and retrieved as void pointers. The containers are only responsible for managing their own internal memory; the user is expected to malloc and free the items actually placed into the containers.
All containers feature a contains function, and maintains its count.
Refer to the unit tests to see usage examples.

* Queue container with enqueue, dequeue, and peek functions.

* Stack container with push, pop and peek functions.

* List container with retrieval, insertion and removal capability to any location.

## Allocator

This is not a typical container, but rather a simple memory manager.
This can be useful when you want to use dynamic memory but do not want the overhead of calling malloc repeatedly, or at all.

First you must allocate memory, either statically or dynamically, and use it to intiailize an Allocator object.
You can then use the Allocator's malloc-like interface for any other purpose.
The Allocator only allows freeing of the entire managed space, rather than individual blocks.

Note, the Allocator does not actually malloc or free! If providing a malloc'ed memory space, you must free that space yourself.

## Build

The C-Containers are built using cmake into a library file.

    > git clone https://github.com/BetaPollux/C-Containers.git
    > cd C-Containers
    > mkdir build
    > cd build
    > cmake ..
    > cmake --build .

## Unit Tests (Unity Fixture)

This collection uses unit tests created with the Unity Fixture framework
To run the tests, you must first clone the Unity repo, refer to https://github.com/ThrowTheSwitch/Unity.
By default the repo is assumed to be at /usr/local/lib/Unity.

The tests are run using ctest.

    > git clone https://github.com/BetaPollux/C-Containers.git
    > cd C-Containers
    > mkdir build
    > cd build
    > cmake ..
    > cmake --build .
    > ctest

If Unity is not at the default location, you can configure the build using the UNITY_ROOT cache variable:

    > cmake -D UNITY_ROOT=~/repos/Unity ..

Note that the CMake installation of Unity is not compatible with Unity Fixture at this time!
You must use the above method.
