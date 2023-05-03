// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice
#include "turtlebot4_interfaces/msg/detail/bb_coordinates__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
turtlebot4_interfaces__msg__BBCoordinates__init(turtlebot4_interfaces__msg__BBCoordinates * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // w
  // h
  // z
  return true;
}

void
turtlebot4_interfaces__msg__BBCoordinates__fini(turtlebot4_interfaces__msg__BBCoordinates * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // w
  // h
  // z
}

bool
turtlebot4_interfaces__msg__BBCoordinates__are_equal(const turtlebot4_interfaces__msg__BBCoordinates * lhs, const turtlebot4_interfaces__msg__BBCoordinates * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  // h
  if (lhs->h != rhs->h) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
turtlebot4_interfaces__msg__BBCoordinates__copy(
  const turtlebot4_interfaces__msg__BBCoordinates * input,
  turtlebot4_interfaces__msg__BBCoordinates * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // w
  output->w = input->w;
  // h
  output->h = input->h;
  // z
  output->z = input->z;
  return true;
}

turtlebot4_interfaces__msg__BBCoordinates *
turtlebot4_interfaces__msg__BBCoordinates__create()
{
  turtlebot4_interfaces__msg__BBCoordinates * msg = (turtlebot4_interfaces__msg__BBCoordinates *)malloc(sizeof(turtlebot4_interfaces__msg__BBCoordinates));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot4_interfaces__msg__BBCoordinates));
  bool success = turtlebot4_interfaces__msg__BBCoordinates__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
turtlebot4_interfaces__msg__BBCoordinates__destroy(turtlebot4_interfaces__msg__BBCoordinates * msg)
{
  if (msg) {
    turtlebot4_interfaces__msg__BBCoordinates__fini(msg);
  }
  free(msg);
}


bool
turtlebot4_interfaces__msg__BBCoordinates__Sequence__init(turtlebot4_interfaces__msg__BBCoordinates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  turtlebot4_interfaces__msg__BBCoordinates * data = NULL;
  if (size) {
    data = (turtlebot4_interfaces__msg__BBCoordinates *)calloc(size, sizeof(turtlebot4_interfaces__msg__BBCoordinates));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot4_interfaces__msg__BBCoordinates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot4_interfaces__msg__BBCoordinates__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtlebot4_interfaces__msg__BBCoordinates__Sequence__fini(turtlebot4_interfaces__msg__BBCoordinates__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtlebot4_interfaces__msg__BBCoordinates__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtlebot4_interfaces__msg__BBCoordinates__Sequence *
turtlebot4_interfaces__msg__BBCoordinates__Sequence__create(size_t size)
{
  turtlebot4_interfaces__msg__BBCoordinates__Sequence * array = (turtlebot4_interfaces__msg__BBCoordinates__Sequence *)malloc(sizeof(turtlebot4_interfaces__msg__BBCoordinates__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = turtlebot4_interfaces__msg__BBCoordinates__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
turtlebot4_interfaces__msg__BBCoordinates__Sequence__destroy(turtlebot4_interfaces__msg__BBCoordinates__Sequence * array)
{
  if (array) {
    turtlebot4_interfaces__msg__BBCoordinates__Sequence__fini(array);
  }
  free(array);
}

bool
turtlebot4_interfaces__msg__BBCoordinates__Sequence__are_equal(const turtlebot4_interfaces__msg__BBCoordinates__Sequence * lhs, const turtlebot4_interfaces__msg__BBCoordinates__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot4_interfaces__msg__BBCoordinates__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot4_interfaces__msg__BBCoordinates__Sequence__copy(
  const turtlebot4_interfaces__msg__BBCoordinates__Sequence * input,
  turtlebot4_interfaces__msg__BBCoordinates__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot4_interfaces__msg__BBCoordinates);
    turtlebot4_interfaces__msg__BBCoordinates * data =
      (turtlebot4_interfaces__msg__BBCoordinates *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot4_interfaces__msg__BBCoordinates__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          turtlebot4_interfaces__msg__BBCoordinates__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot4_interfaces__msg__BBCoordinates__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
