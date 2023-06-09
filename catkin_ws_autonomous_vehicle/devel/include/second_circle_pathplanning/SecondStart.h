// Generated by gencpp from file second_circle_pathplanning/SecondStart.msg
// DO NOT EDIT!


#ifndef SECOND_CIRCLE_PATHPLANNING_MESSAGE_SECONDSTART_H
#define SECOND_CIRCLE_PATHPLANNING_MESSAGE_SECONDSTART_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace second_circle_pathplanning
{
template <class ContainerAllocator>
struct SecondStart_
{
  typedef SecondStart_<ContainerAllocator> Type;

  SecondStart_()
    : second_flag(false)
    , optimization_flag(false)  {
    }
  SecondStart_(const ContainerAllocator& _alloc)
    : second_flag(false)
    , optimization_flag(false)  {
  (void)_alloc;
    }



   typedef uint8_t _second_flag_type;
  _second_flag_type second_flag;

   typedef uint8_t _optimization_flag_type;
  _optimization_flag_type optimization_flag;





  typedef boost::shared_ptr< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> const> ConstPtr;

}; // struct SecondStart_

typedef ::second_circle_pathplanning::SecondStart_<std::allocator<void> > SecondStart;

typedef boost::shared_ptr< ::second_circle_pathplanning::SecondStart > SecondStartPtr;
typedef boost::shared_ptr< ::second_circle_pathplanning::SecondStart const> SecondStartConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::second_circle_pathplanning::SecondStart_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::second_circle_pathplanning::SecondStart_<ContainerAllocator1> & lhs, const ::second_circle_pathplanning::SecondStart_<ContainerAllocator2> & rhs)
{
  return lhs.second_flag == rhs.second_flag &&
    lhs.optimization_flag == rhs.optimization_flag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::second_circle_pathplanning::SecondStart_<ContainerAllocator1> & lhs, const ::second_circle_pathplanning::SecondStart_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace second_circle_pathplanning

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f0667236eadb504e422cb705b4187e2d";
  }

  static const char* value(const ::second_circle_pathplanning::SecondStart_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf0667236eadb504eULL;
  static const uint64_t static_value2 = 0x422cb705b4187e2dULL;
};

template<class ContainerAllocator>
struct DataType< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
{
  static const char* value()
  {
    return "second_circle_pathplanning/SecondStart";
  }

  static const char* value(const ::second_circle_pathplanning::SecondStart_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool second_flag\n"
"bool optimization_flag\n"
;
  }

  static const char* value(const ::second_circle_pathplanning::SecondStart_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.second_flag);
      stream.next(m.optimization_flag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SecondStart_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::second_circle_pathplanning::SecondStart_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::second_circle_pathplanning::SecondStart_<ContainerAllocator>& v)
  {
    s << indent << "second_flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.second_flag);
    s << indent << "optimization_flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.optimization_flag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SECOND_CIRCLE_PATHPLANNING_MESSAGE_SECONDSTART_H
