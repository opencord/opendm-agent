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
#define DMI_HH_MGMT_H_

#include "hw_metrics_mgmt_service.grpc.pb.h"
#include "hw_metrics_mgmt_service.pb.h"
#include "dmi_common.h"

using grpc::ServerWriter;


class HWMetricsMgmtService final : public dmi::NativeMetricsManagementService::Service
{
    public:
        static HWMetricsMgmtService& getHwMetricMgmtInstance()
        {
            static HWMetricsMgmtService HwMetrictInstance;
            return HwMetrictInstance;
        }

        grpc::Status ListMetrics(
                ServerContext* context,
                const dmi::HardwareID* request,
                dmi::ListMetricsResponse* response )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status UpdateMetricsConfiguration(
                ServerContext* context,
                const dmi::MetricsConfigurationRequest* request,
                dmi::MetricsConfigurationResponse* response )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status GetMetric(
                ServerContext* context,
                const dmi::GetMetricRequest* request,
                dmi::GetMetricResponse* response )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

    private:
        HWMetricsMgmtService()
        {
        }

        ~HWMetricsMgmtService()
        {
        }
};

#endif
