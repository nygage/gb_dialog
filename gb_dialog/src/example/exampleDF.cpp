/*********************************************************************
*  Software License Agreement (BSD License)
*
*   Copyright (c) 2018, Intelligent Robotics
*   All rights reserved.
*
*   Redistribution and use in source and binary forms, with or without
*   modification, are permitted provided that the following conditions
*   are met:

*    * Redistributions of source code must retain the above copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above
*      copyright notice, this list of conditions and the following
*      disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of Intelligent Robotics nor the names of its
*      contributors may be used to endorse or promote products derived
*      from this software without specific prior written permission.

*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*   COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*   POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Jonatan Gines jginesclavero@gmail.com */

/* Mantainer: Jonatan Gines jginesclavero@gmail.com */
#include <gb_dialog/DialogInterface.h>
#include <std_msgs/Empty.h>
#include <string>

namespace gb_dialog
{
class ForwarderDF: public gb_dialog::DialogInterface
{
  public:
    explicit ForwarderDF(std::string intent): nh_(), DialogInterface(intent)
    {
      trigger_sub_ = nh_.subscribe("/listen", 1, &ForwarderDF::triggerCallback, this);
    }

    void listenCallback(dialogflow_ros_msgs::DialogflowResult result)
    {
      ROS_INFO("[ForwarderDF] listenCallback: intent %s", result.intent.c_str());
      result_ = result;
      speak(result_.fulfillment_text);
    }

    void triggerCallback(const std_msgs::Empty::ConstPtr& msg)
    {
      listen();
    }

  private:
    ros::NodeHandle nh_;
    ros::Subscriber trigger_sub_;
    dialogflow_ros_msgs::DialogflowResult result_;
};
}  // namespace gb_dialog

int main(int argc, char** argv)
{
  ros::init(argc, argv, "example_df_node");
  gb_dialog::ForwarderDF forwarder("[[:print:]_]*.info");
  ros::spin();
  return 0;
}
