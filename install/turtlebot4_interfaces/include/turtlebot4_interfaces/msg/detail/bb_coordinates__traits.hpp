// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__TRAITS_HPP_
#define TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__TRAITS_HPP_

#include "turtlebot4_interfaces/msg/detail/bb_coordinates__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlebot4_interfaces::msg::BBCoordinates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    value_to_yaml(msg.w, out);
    out << "\n";
  }

  // member: h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "h: ";
    value_to_yaml(msg.h, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlebot4_interfaces::msg::BBCoordinates & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlebot4_interfaces::msg::BBCoordinates>()
{
  return "turtlebot4_interfaces::msg::BBCoordinates";
}

template<>
inline const char * name<turtlebot4_interfaces::msg::BBCoordinates>()
{
  return "turtlebot4_interfaces/msg/BBCoordinates";
}

template<>
struct has_fixed_size<turtlebot4_interfaces::msg::BBCoordinates>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlebot4_interfaces::msg::BBCoordinates>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlebot4_interfaces::msg::BBCoordinates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__TRAITS_HPP_
