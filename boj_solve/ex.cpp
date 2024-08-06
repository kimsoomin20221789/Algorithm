#include "rclcpp/rclcpp.hpp"
#include <string>
#include "sensor_msgs/msg/laser_scan.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
#include <vector>
#include <utility> // for using pair
#include <visualization_msgs/msg/marker.hpp>
#define _USE_MATH_DEFINES
#include <cmath>


using std::placeholders::_1;
using namespace std;
int max_gap_index = 0;

struct Vector2D{
    double x;
    double y;
};


class WallFollow : public rclcpp::Node {

public:
    WallFollow() : Node("wall_follow_node")
    {
        // Create ROS subscribers and publishers
        publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>(this->drive_topic, 10);
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(this->lidarscan_topic, 10, std::bind(&WallFollow::scan_callback, this, _1));
    }

private:

vector<pair<int, int>> get_obstacles_mod(std::vector<float> ranges, float angle_increment, float range_max, float angle_min) const {

    vector<pair<int, int> > result;
    int start_idx = 0;
    int end_idx = 0;
    int obs_size = 0;
    int passing_value = 15;
    ranges = trim_filter_ranges(ranges);
    int ranges_size = ranges.size();

    int i;
    for(i = 1; i < ranges_size; i++) {
        double cur_angle = (angle_min) + ((i-1)*(angle_increment));
        double next_angle = (angle_min) + (i*(angle_increment));
        Vector2D a = get_coordinate(cur_angle, ranges[i-1]);
        Vector2D b = get_coordinate(next_angle, ranges[i]);

        end_idx = i-1;

        if(is_neary_point(a, b, 0.375)) {
            obs_size++;
        }
        else {
            if(obs_size >= passing_value) {
                result.push_back(pair<int, int>(start_idx, end_idx));
            }
            obs_size = 0;
            start_idx = i;
        }
    }
    if(obs_size >= passing_value) {
        result.push_back(pair<int, int>(start_idx, ranges_size-1));
    }
    
    cout << "detected obs: ";
    int result_size = result.size();
    for(int j = 0; j < result_size; j++) {
        cout << result[j].first << "," << result[j].second << " ";
    }
    cout << endl;

    return result;
}

Vector2D get_coordinate(double angle, double dist) const {
    Vector2D coordinate;

    coordinate.x = dist * cos(angle);
    coordinate.y = dist * sin(angle);

    return coordinate;
}

bool is_neary_point(Vector2D p1, Vector2D p2, float pivot) const {
    return ((abs(p1.x - p2.x) < pivot) && (abs(p1.y - p2.y) < pivot)) ? true : false;
}
//=================================end=======================

//soomin
vector<float> trim_filter_ranges(std::vector<float> range) const {
    // auto ranges = scan_data->ranges;
    // cout << "필터링전:" << range.size() << endl;
    auto ranges = range;

    vector<float>::iterator it1 = ranges.begin();
    vector<float>::iterator it2 = ranges.begin()+149;
    ranges.erase(it1, it2);

    vector<float>::iterator it3 = ranges.end()-149;
    vector<float>::iterator it4 = ranges.end();
    ranges.erase(it3, it4);

    auto last_index = int(ranges.size()-1);
    float distance = 0;
    float max_distance = 12.5;

    for(int i = 0; i<=last_index; i++){
        distance = ranges.at(i);

        if(distance > max_distance)
            ranges.at(i) = 0;
        else
            continue;
    }
    // cout << "필터링후:" << ranges.size() << endl;
    return ranges;
}
//==========================end===========================
    // PID CONTROL PARAMS
    double kp = 3;
    double ki = 0;
    double kd = 0.1;
    double servo_offset = 0.0;
    double prev_error = 0.0;
    double error = 0.0;
    double integral = 0.0;
    double start_t = -1;
    double curr_t = 0.0;
    double prev_t = 0.0;
    
    // Topics
    std::string lidarscan_topic = "/scan";
    std::string drive_topic = "/drive";

    /// Create ROS subscribers and publishers
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    

    double get_range(const sensor_msgs::msg::LaserScan::ConstSharedPtr scan_msg, double angle)
    {
        /*
        Simple helper to return the corresponding range measurement at a given angle. Make sure you take care of NaNs and infs.

        Args:
            range_data: single range array from the LiDAR
            angle: between angle_min and angle_max of the LiDAR in radians

        Returns:
            range: range measurement in meters at the given angle
        */

        assert(angle >= scan_msg->angle_min && angle <= scan_msg->angle_max); // Angle must be within range
        int i = (angle - scan_msg->angle_min) / (scan_msg->angle_increment); // index i of closest angle
        if (std::isnan(scan_msg->ranges[i]) || scan_msg->ranges[i] > scan_msg->range_max) return scan_msg->range_max; // In case of NaNs and infinity, just return the maximum of the scan message
        return scan_msg->ranges[i];
    }
    
    double to_radians(double theta) {
        return M_PI * theta / 180.0;

    }
    
    double to_degrees(double theta) {
        return theta * 180.0 / M_PI;
    }

    // void get_error(const sensor_msgs::msg::LaserScan::ConstSharedPtr scan_msg, double dist)
    // {
    //     /*
    //     Calculates the error to the wall. Follow the wall to the left (going counter clockwise in the Levine loop). You potentially will need to use get_range()

    //     Args:
    //         range_data: single range array from the LiDAR
    //         dist: desired distance to the wall

    //     Returns:
    //         error: calculated error
    //     */

    //     double a = get_range(scan_msg, to_radians(-20.0));
    //     double b = get_range(scan_msg, to_radians(-90.0)); // 0 degrees is in front of the card.
    //     double theta = to_radians(70.0); // 90.0 - 50.0 = 40.0 degrees
    //     double alpha = std::atan((a * std::cos(theta) - b)/(a * std::sin(theta)));
    //     double D_t = b*std::cos(alpha);
    //     // double D_t_1 =  D_t + dist * std::sin(alpha);

    //     this->prev_error = this->error;
    //     this->error = dist - D_t;
    //     this->integral += this->error;
    //     this->prev_t = this->curr_t;
    //     this->curr_t = (double) scan_msg->header.stamp.nanosec * (double)10e-9 + (double) scan_msg->header.stamp.sec;
    //     if (this->start_t == 0.0) {
    //         this->start_t = this->curr_t;
    //     }
    // }
    void get_error(const sensor_msgs::msg::LaserScan::ConstSharedPtr scan_msg)
    {
        /*
        Calculates the error to the wall. Follow the wall to the left (going counter clockwise in the Levine loop). You potentially will need to use get_range()

        Args:
            range_data: single range array from the LiDAR
            dist: desired distance to the wall

        Returns:
            error: calculated error
        */

        double a_r = get_range(scan_msg, to_radians(-45.0));
        double b_r = get_range(scan_msg, to_radians(-90.0)); // 0 degrees is in front of the card.
        double theta_r = to_radians(45.0); // 90.0 - 50.0 = 40.0 degrees
        double alpha_r = std::atan((a_r * std::cos(theta_r) - b_r)/(a_r * std::sin(theta_r)));
        double D_t_r = b_r*std::cos(alpha_r);

        double a_l = get_range(scan_msg, to_radians(45.0));
        double b_l = get_range(scan_msg, to_radians(90.0)); // 0 degrees is in front of the card.
        double theta_l = to_radians(45.0); // 90.0 - 50.0 = 40.0 degrees
        double alpha_l = std::atan((a_l * std::cos(theta_l) - b_l)/(a_l * std::sin(theta_l)));
        double D_t_l = b_l*std::cos(alpha_l);
        // double D_t_1 =  D_t + dist * std::sin(alpha);

        this->prev_error = this->error;
        this->error = D_t_l - D_t_r;
        this->integral += this->error;
        this->prev_t = this->curr_t;
        this->curr_t = (double) scan_msg->header.stamp.nanosec * (double)10e-9 + (double) scan_msg->header.stamp.sec;
        if (this->start_t == 0.0) {
            this->start_t = this->curr_t;
        }
    }

    void pid_control()
    {
        /*
        Based on the calculated error, publish vehicle control

        Args:
            error: calculated error
            velocity: desired velocity

        Returns:
            None
        */
        double angle = 0.0;
        // Use kp, ki & kd to implement a PID controller
        if (this->prev_t == 0.0) return;
        angle = this->kp * this->error + this->ki * this->integral * (this->curr_t - this->start_t) + this->kd * (this->error - this->prev_error)/(this->curr_t - this->prev_t);

        auto drive_msg = ackermann_msgs::msg::AckermannDriveStamped();
        // Fill in drive message and publish
        drive_msg.drive.steering_angle = angle;
        
        // We go slower if we need to a large steering angle correction
        if (std::abs(drive_msg.drive.steering_angle) >= this->to_radians(0) && std::abs(drive_msg.drive.steering_angle) < this->to_radians(10)) {
            drive_msg.drive.speed = 1.5;
        } else if (std::abs(drive_msg.drive.steering_angle) >= this->to_radians(10) && std::abs(drive_msg.drive.steering_angle) < this->to_radians(20)) {
            drive_msg.drive.speed = 1.0;
        } else {
            drive_msg.drive.speed = 0.5;
        }
        this->publisher_->publish(drive_msg);
    }
    // void lidar_callback(const LaserScan::SharedPtr msg) const {
    //         scan_data = msg;
    //         find_gap(181);
    //     }
    // void up_FTW(const sensor_msgs::msg::LaserScan::ConstSharedPtr scan_msg){
    //     std::vector<float> ranges = scan_msg->ranges;
    //     double x_l, y_l, x_r, y_r, angle = 0.0; // 초기화 필요하나 
    //     std::pair<int, double> lidar_l = get_max_index_and_value(ranges, 540, int(ranges.size())-184);
    //     std::pair<int, double> lidar_r = get_max_index_and_value(ranges, 184, 540);
    //     x_l = lidar_l.second * std::cos(to_radians((lidar_l.first-180)/4)); // range 범위에 따른 하드코딩
    //     y_l = lidar_l.second * std::sin(to_radians((lidar_l.first-180)/4));
    //     x_r = lidar_r.second * std::cos(to_radians((lidar_r.first-180)/4));
    //     y_r = lidar_r.second * std::sin(to_radians((lidar_r.first-180)/4));
    //     angle = -std::atan((x_l + x_r)/(y_l + y_r));

    //     auto drive_msg = ackermann_msgs::msg::AckermannDriveStamped();
    //     drive_msg.drive.steering_angle = angle;
    //     drive_msg.drive.speed = 1.0;

    //     this->publisher_->publish(drive_msg);

    // }
    void scan_callback(const sensor_msgs::msg::LaserScan::ConstSharedPtr scan_msg) 
    {   
        int obstacles_cnt = get_obstacles_mod(scan_msg->ranges, scan_msg->angle_increment, scan_msg->range_max, scan_msg->angle_min).size();
        if (obstacles_cnt<3){
            cout << "w" << endl;
            // auto ranges = trim_filter_ranges(scan_msg->ranges);

            get_error(scan_msg); 
            pid_control();
        } else {
            cout << "===============gap" << endl;
            find_gap(181, scan_msg->ranges);
        }
        // find_gap(181, scan_msg->ranges);

    }
    void find_gap(int gap_size, vector<float> range) const {
            auto ranges = range;

            auto last_index = int(ranges.size()-1);

            float max_gap = 0;

            for(int i = 0; i<=last_index-(gap_size-1); i++){
                float temp_sum = 0;
                for(int j = i; j<=i+(gap_size-1); j++){
                    temp_sum = temp_sum + ranges.at(j);
                }

                if(temp_sum > max_gap){
                    max_gap = temp_sum;
                    max_gap_index = i+int(floor(gap_size/2));
                }
                else
                    continue;
            }

            // display_gap(last_index, max_gap_index);
            follow_gap(last_index, max_gap_index);
    }

    void follow_gap(int last_index, int max_gap_index) const {
            float rads = rads_to_follow(last_index, max_gap_index);

            if(abs(rads) > 0.698131701){
                rads = rads / abs(rads) * 0.698131701;
            }
            auto drive_msg = ackermann_msgs::msg::AckermannDriveStamped();
            // AckermannDriveStamped drive_cmd;
            drive_msg.drive.speed = 1.5;
            drive_msg.drive.acceleration = 0.5;
            drive_msg.drive.steering_angle = rads;
            drive_msg.drive.steering_angle_velocity = 0.05;
            // ackermann_publisher_->publish(drive_cmd);
            this->publisher_->publish(drive_msg);
    }
    // void display_gap(int last_index, int max_gap_index) const {
    //         float rads = rads_to_follow(last_index, max_gap_index);

    //         float point_location = tan(rads) * 1;

    //         Marker marker;
    //         marker.header.frame_id = "ego_racecar/base_link";
    //         marker.header.stamp = now();
    //         marker.ns = "gaps";
    //         marker.id = 0;
    //         marker.type = Marker::POINTS;
    //         marker.action = Marker::ADD;
    //         marker.frame_locked = true;
    //         marker.scale.x = 0.2;
    //         marker.scale.y = 0.2;
    //         marker.color.g = 1.0f;
    //         marker.color.a = 1.0;

    //         Point p;
    //         p.x = 1.0;
    //         p.y = point_location;
    //         p.z = 0.05;

    //         marker.pose.position = p;
    //         marker.points.push_back(p);

    //         vis_publisher_->publish(marker);
    // }
    double rads_to_follow(int last_index, int max_gap_index) const {
            double angle_increment = 0.004351851996034384;
            int relative_point = max_gap_index - int(floor((last_index+1)/2));
            float rads = angle_increment*relative_point;

            return rads;
    }



};
int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WallFollow>());
    rclcpp::shutdown();
    return 0;
}