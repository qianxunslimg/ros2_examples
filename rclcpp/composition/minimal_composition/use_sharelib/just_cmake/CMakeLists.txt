cmake_minimum_required(VERSION 3.10)

project(use_sharelib)

# 不但要有自己制作的动态库路径 还要有ros2的动态库/软件包路径用来find_package
link_directories(/home/qianxunslimg/Desktop/study/ros_study/ros2_examples/install/examples_rclcpp_minimal_composition/lib /opt/ros/foxy/lib)

include_directories(include)

find_package(rclcpp REQUIRED)
find_package(rcutils REQUIRED) #也是需要的

# 当使用find_package(rclcpp REQUIRED)命令后，
# CMake会自动设置${rclcpp_INCLUDE_DIRS}变量，以便在后续的编译过程中使用。
include_directories(${rclcpp_INCLUDE_DIRS}) #包含rclcpp头文件 /opt/ros/foxy/include

add_executable(my_executable main.cpp)

target_link_libraries(my_executable composition_nodes rclcpp rcutils)