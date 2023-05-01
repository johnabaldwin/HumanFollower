// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtlebot4_interfaces:msg/BBCoordinates.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__STRUCT_HPP_
#define TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__turtlebot4_interfaces__msg__BBCoordinates __attribute__((deprecated))
#else
# define DEPRECATED__turtlebot4_interfaces__msg__BBCoordinates __declspec(deprecated)
#endif

namespace turtlebot4_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BBCoordinates_
{
  using Type = BBCoordinates_<ContainerAllocator>;

  explicit BBCoordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->w = 0.0f;
      this->h = 0.0f;
    }
  }

  explicit BBCoordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->w = 0.0f;
      this->h = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _w_type =
    float;
  _w_type w;
  using _h_type =
    float;
  _h_type h;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__w(
    const float & _arg)
  {
    this->w = _arg;
    return *this;
  }
  Type & set__h(
    const float & _arg)
  {
    this->h = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtlebot4_interfaces__msg__BBCoordinates
    std::shared_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtlebot4_interfaces__msg__BBCoordinates
    std::shared_ptr<turtlebot4_interfaces::msg::BBCoordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BBCoordinates_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    if (this->h != other.h) {
      return false;
    }
    return true;
  }
  bool operator!=(const BBCoordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BBCoordinates_

// alias to use template instance with default allocator
using BBCoordinates =
  turtlebot4_interfaces::msg::BBCoordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtlebot4_interfaces

#endif  // TURTLEBOT4_INTERFACES__MSG__DETAIL__BB_COORDINATES__STRUCT_HPP_
