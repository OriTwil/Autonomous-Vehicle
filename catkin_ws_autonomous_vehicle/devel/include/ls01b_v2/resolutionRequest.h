// Generated by gencpp from file ls01b_v2/resolutionRequest.msg
// DO NOT EDIT!


#ifndef LS01B_V2_MESSAGE_RESOLUTIONREQUEST_H
#define LS01B_V2_MESSAGE_RESOLUTIONREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Float64.h>

namespace ls01b_v2
{
template <class ContainerAllocator>
struct resolutionRequest_
{
  typedef resolutionRequest_<ContainerAllocator> Type;

  resolutionRequest_()
    : resolution()  {
    }
  resolutionRequest_(const ContainerAllocator& _alloc)
    : resolution(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Float64_<ContainerAllocator>  _resolution_type;
  _resolution_type resolution;





  typedef boost::shared_ptr< ::ls01b_v2::resolutionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ls01b_v2::resolutionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct resolutionRequest_

typedef ::ls01b_v2::resolutionRequest_<std::allocator<void> > resolutionRequest;

typedef boost::shared_ptr< ::ls01b_v2::resolutionRequest > resolutionRequestPtr;
typedef boost::shared_ptr< ::ls01b_v2::resolutionRequest const> resolutionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ls01b_v2::resolutionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ls01b_v2::resolutionRequest_<ContainerAllocator1> & lhs, const ::ls01b_v2::resolutionRequest_<ContainerAllocator2> & rhs)
{
  return lhs.resolution == rhs.resolution;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ls01b_v2::resolutionRequest_<ContainerAllocator1> & lhs, const ::ls01b_v2::resolutionRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ls01b_v2

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ls01b_v2::resolutionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ls01b_v2::resolutionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ls01b_v2::resolutionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ba38fa778a789d6bd91d8ad5a0772954";
  }

  static const char* value(const ::ls01b_v2::resolutionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xba38fa778a789d6bULL;
  static const uint64_t static_value2 = 0xd91d8ad5a0772954ULL;
};

template<class ContainerAllocator>
struct DataType< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ls01b_v2/resolutionRequest";
  }

  static const char* value(const ::ls01b_v2::resolutionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Float64 resolution\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Float64\n"
"float64 data\n"
;
  }

  static const char* value(const ::ls01b_v2::resolutionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.resolution);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct resolutionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ls01b_v2::resolutionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ls01b_v2::resolutionRequest_<ContainerAllocator>& v)
  {
    s << indent << "resolution: ";
    s << std::endl;
    Printer< ::std_msgs::Float64_<ContainerAllocator> >::stream(s, indent + "  ", v.resolution);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LS01B_V2_MESSAGE_RESOLUTIONREQUEST_H
