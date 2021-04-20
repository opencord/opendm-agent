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

#ifndef DMI_SW_MGMT_H_
#define DMI_SW_MGMT_H_

#include "sw_management_service.grpc.pb.h"
#include "sw_management_service.pb.h"
#include "dmi_common.h"

using grpc::ServerWriter;

grpc::Status GetSoftwareVersion_(const dmi::HardwareID* request,
             dmi::GetSoftwareVersionInformationResponse* response);

class SWMgmtService final : public dmi::NativeSoftwareManagementService::Service
{
    public:
        static SWMgmtService& getSWInstance()
        {
            static SWMgmtService swinstance;
            return swinstance;
        }

        grpc::Status GetSoftwareVersion(
                ServerContext* context,
                const dmi::HardwareID* request,
                dmi::GetSoftwareVersionInformationResponse* response )
        {
            return GetSoftwareVersion_(request, response);
        }

        grpc::Status DownloadImage(
                ServerContext* context,
                const dmi::DownloadImageRequest* request,
                ServerWriter<dmi::ImageStatus>* writer )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status ActivateImage(
                ServerContext* context,
                const dmi::HardwareID* request,
                ServerWriter<dmi::ImageStatus>* writer )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status RevertToStandbyImage(
                ServerContext* context,
                const dmi::HardwareID* request,
                ServerWriter<dmi::ImageStatus>* writer )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status UpdateStartupConfiguration(
                ServerContext* context,
                const dmi::ConfigRequest* request,
                ServerWriter<dmi::ConfigResponse>* writer )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }

        grpc::Status GetStartupConfigurationInfo(
                ServerContext* context,
                const dmi::StartupConfigInfoRequest* request,
                dmi::StartupConfigInfoResponse* response )
        {
            //TODO write an internal API to handle the request
            return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
        }
    private:
        SWMgmtService()
        {
        }

        ~SWMgmtService()
        {
        }
};
#endif
