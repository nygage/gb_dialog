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

#ifndef GRAPHDIALOGEXTRACTOR_H_
#define GRAPHDIALOGEXTRACTOR_H_

#include <ros/ros.h>
#include <ros/console.h>
#include <gb_dialog/DialogInterface.h>
#include "bica_graph/graph_client.h"
#include "graph_dialog_extractor/floorDF_lib.h"
#include "graph_dialog_extractor/orderReadyDF_lib.h"
#include "graph_dialog_extractor/confirmOrderDF_lib.h"
#include "graph_dialog_extractor/startDF_lib.h"
#include "graph_dialog_extractor/orderDF_lib.h"

#include <string>

namespace graph_dialog_extractor
{
class GraphDialogExtractor: public gb_dialog::DialogInterface
{
public:
  GraphDialogExtractor();
  void step();
  bica_graph::StringEdge* edge_;
  graph_dialog_extractor::FloorDF floorDF;
  graph_dialog_extractor::OrderReadyDF orderReadyDF;
  graph_dialog_extractor::ConfirmOrderDF confirmOrderDF;
  graph_dialog_extractor::StartDF startDF;
  graph_dialog_extractor::OrderDF orderDF;


private:
  ros::NodeHandle nh_;
  bica_graph::GraphClient graph_;
  std::string saySplit(std::string str);
};
}  // namespace graph_dialog_extractor
#endif
