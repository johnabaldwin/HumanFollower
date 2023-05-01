// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__STRUCT_H_
#define TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/BBCoordinates in the package turtlebot4_interfaces.
typedef struct turtlebot4_interfaces__msg__BBCoordinates
{
  float x;
  float y;
  float w;
  float h;
} turtlebot4_interfaces__msg__BBCoordinates;

// Struct for a sequence of turtlebot4_interfaces__msg__BBCoordinates.
typedef struct turtlebot4_interfaces__msg__BBCoordinates__Sequence
{
  turtlebot4_interfaces__msg__BBCoordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot4_interfaces__msg__BBCoordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__STRUCT_H_
