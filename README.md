![ik screenshot](https://github.com/pyth/screenshots/blob/master/ik_solver.png)

# 2d_ik_solver
A simple inverse kinematics solver for an arm in 2d

## About
This is an implementation on an inverse kinematics solver for an arm with variable number of joints in a two dimensional coordiante system.

## Dependecies
  * [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)
  * [SDL2](https://github.com/libsdl-org/SDL/releases/tag/release-2.30.11)

## Build
  1. Install missing dependencies
  ```
    conan install .
  ```
  2. Build the project
  ```
    conan build .
  ```

## Running
  ```
    ./build/ik_solver
  ```