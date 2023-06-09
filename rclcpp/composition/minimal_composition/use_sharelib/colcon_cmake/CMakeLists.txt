cmake_minimum_required(VERSION 3.5)
project(colcon_cmake)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)

# 自己制作的动态库路径
link_directories(/home/qianxunslimg/Desktop/study/ros_study/ros2_examples/install/examples_rclcpp_minimal_composition/lib)

include_directories(include)

add_executable(colcon_cmake.out main.cpp)

# 自己制作的动态库
target_link_libraries(colcon_cmake.out composition_nodes)

# find_package的rclcpp 直接ament
# ament_target_dependencies 简化了与软件包的依赖项管理相关的 CMake 步骤，并自动处理包含目录和链接库的设置。
ament_target_dependencies(colcon_cmake.out rclcpp)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
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