#include <ros_library/library.h>
#include <Eigen/Geometry>
#include <opencv2/opencv.hpp>

std::string library::project_name(){
    cv::Point3f p = {1,2, 3};
    p.dot(p);
    Eigen::Affine3d e = Eigen::Affine3d::Identity();
    e = e * e;
    return std::string(PROJECT_NAME);
}
