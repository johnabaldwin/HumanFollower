// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlebot4_interfaces/msg/detail/bb_coordinates__rosidl_typesupport_introspection_c.h"
#include "turtlebot4_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlebot4_interfaces/msg/detail/bb_coordinates__functions.h"
#include "turtlebot4_interfaces/msg/detail/bb_coordinates__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlebot4_interfaces__msg__BBCoordinates__init(message_memory);
}

void BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_fini_function(void * message_memory)
{
  turtlebot4_interfaces__msg__BBCoordinates__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_member_array[5] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_interfaces__msg__BBCoordinates, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_interfaces__msg__BBCoordinates, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_interfaces__msg__BBCoordinates, w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "h",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_interfaces__msg__BBCoordinates, h),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_interfaces__msg__BBCoordinates, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_members = {
  "turtlebot4_interfaces__msg",  // message namespace
  "BBCoordinates",  // message name
  5,  // number of fields
  sizeof(turtlebot4_interfaces__msg__BBCoordinates),
  BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_member_array,  // message members
  BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_type_support_handle = {
  0,
  &BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlebot4_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlebot4_interfaces, msg, BBCoordinates)() {
  if (!BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_type_support_handle.typesupport_identifier) {
    BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &BBCoordinates__rosidl_typesupport_introspection_c__BBCoordinates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
