#include <memory>
#include "minimal_composition/publisher_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    // 使用动态库提供的功能和函数
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>(rclcpp::NodeOptions()));
    rclcpp::shutdown();
    return 0;
}