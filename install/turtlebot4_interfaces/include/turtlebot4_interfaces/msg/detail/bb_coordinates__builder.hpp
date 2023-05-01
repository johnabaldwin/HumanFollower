// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__BUILDER_HPP_
#define TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__BUILDER_HPP_

#include "turtlebot4_interfaces/msg/detail/bb_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace turtlebot4_interfaces
{

namespace msg
{

namespace builder
{

class Init_BBCoordinates_h
{
public:
  explicit Init_BBCoordinates_h(::turtlebot4_interfaces::msg::BBCoordinates & msg)
  : msg_(msg)
  {}
  ::turtlebot4_interfaces::msg::BBCoordinates h(::turtlebot4_interfaces::msg::BBCoordinates::_h_type arg)
  {
    msg_.h = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot4_interfaces::msg::BBCoordinates msg_;
};

class Init_BBCoordinates_w
{
public:
  explicit Init_BBCoordinates_w(::turtlebot4_interfaces::msg::BBCoordinates & msg)
  : msg_(msg)
  {}
  Init_BBCoordinates_h w(::turtlebot4_interfaces::msg::BBCoordinates::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_BBCoordinates_h(msg_);
  }

private:
  ::turtlebot4_interfaces::msg::BBCoordinates msg_;
};

class Init_BBCoordinates_y
{
public:
  explicit Init_BBCoordinates_y(::turtlebot4_interfaces::msg::BBCoordinates & msg)
  : msg_(msg)
  {}
  Init_BBCoordinates_w y(::turtlebot4_interfaces::msg::BBCoordinates::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BBCoordinates_w(msg_);
  }

private:
  ::turtlebot4_interfaces::msg::BBCoordinates msg_;
};

class Init_BBCoordinates_x
{
public:
  Init_BBCoordinates_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BBCoordinates_y x(::turtlebot4_interfaces::msg::BBCoordinates::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BBCoordinates_y(msg_);
  }

private:
  ::turtlebot4_interfaces::msg::BBCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot4_interfaces::msg::BBCoordinates>()
{
  return turtlebot4_interfaces::msg::builder::Init_BBCoordinates_x();
}

}  // namespace turtlebot4_interfaces

#endif  // TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__BUILDER_HPP_
