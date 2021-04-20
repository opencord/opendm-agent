/*
 * Copyright 2021-present Open Networking Foundation
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DMI_HW_MGMT_H_
#include "dmi_hw_mgmt.h"
#endif

#include "dmi_sw_mgmt.h"
#include "dmi_events_mgmt.h"
#include "dmi_metrics_mgmt.h"

#define GRPC_ADDRESS "0.0.0.0:9292"

using namespace std;

void RunGrpcServer() {
    const char* address = GRPC_ADDRESS;
    HWMgmtService        &HWMgmtSrv     = HWMgmtService::getHWInstance();
    SWMgmtService        &SWMgmtSrv     = SWMgmtService::getSWInstance();
    HWEventsMgmtService  &EventMgmtSrv  = HWEventsMgmtService::getHwEventMgmtInstance();
    HWMetricsMgmtService &MetricMgmtSrv = HWMetricsMgmtService::getHwMetricMgmtInstance();

    ServerBuilder builder;

    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&HWMgmtSrv);
    builder.RegisterService(&SWMgmtSrv);
    builder.RegisterService(&EventMgmtSrv);
    builder.RegisterService(&MetricMgmtSrv);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "opendm-agent GRPC server listening on port: " << address << std::endl;

    server->Wait();
}
