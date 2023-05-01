// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlebot4_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "turtlebot4_interfaces/msg/detail/bb_coordinates__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace turtlebot4_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_interfaces
cdr_serialize(
  const turtlebot4_interfaces::msg::BBCoordinates & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  turtlebot4_interfaces::msg::BBCoordinates & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_interfaces
get_serialized_size(
  const turtlebot4_interfaces::msg::BBCoordinates & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_interfaces
max_serialized_size_BBCoordinates(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace turtlebot4_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtlebot4_interfaces, msg, BBCoordinates)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
