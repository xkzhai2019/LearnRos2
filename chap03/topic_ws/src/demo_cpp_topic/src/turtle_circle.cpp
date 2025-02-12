#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono> // 引入时间相关头文件

using namespace std::chrono_literals; // 使用时间单位的字面量，可以在代码中使用s和ms表示时间
class TurtleCircle: public rclcpp::Node{
    private:
        rclcpp::TimerBase::SharedPtr timer_; // 定时器智能指针
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_; // 发布者智能指针
    public:
        explicit TurtleCircle(const std::string& node_name): Node(node_name){
            publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            timer_ = this->create_wall_timer(1000ms,std::bind(&TurtleCircle::timer_callback,this));
        }

    private:
        void timer_callback(){
            auto msg = geometry_msgs::msg::Twist();
            msg.linear.x = 1.0;
            msg.angular.z = 0.5;
            publisher_->publish(msg); 
        }

};

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<TurtleCircle>("turtle_square");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

