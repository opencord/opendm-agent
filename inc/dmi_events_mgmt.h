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

#include "hw_events_mgmt_service.grpc.pb.h"
#include "hw_events_mgmt_service.pb.h"
#include "dmi_common.h"

class HWEventsMgmtService final : public dmi::NativeEventsManagementService::Service
{
    public:
        static HWEventsMgmtService& getHwEventMgmtInstance()
        {
            static HWEventsMgmtService HwEventInstance;
            return HwEventInstance;
        }

        grpc::Status ListEvents(
                ServerContext* context,
                const dmi::HardwareID* request,
                dmi::ListEventsResponse* response)
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status UpdateEventsConfiguration(
                ServerContext* context,
                const dmi::EventsConfigurationRequest* request,
                dmi::EventsConfigurationResponse* response )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

    private:
        HWEventsMgmtService()
        {
        }

        ~HWEventsMgmtService()
        {
        }
};

#endif
