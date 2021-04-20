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

#include "hw_management_service.grpc.pb.h"
#include "hw_management_service.pb.h"
#include "dmi_common.h"

using grpc::ServerWriter;

grpc::Status StartManagingDevice_(
             const dmi::ModifiableComponent* request,
             ServerWriter<dmi::StartManagingDeviceResponse>* writer
             );
grpc::Status StopManagingDevice_(dmi::StopManagingDeviceResponse* response);
grpc::Status GetManagedDevices_(dmi::ManagedDevicesResponse* response);
grpc::Status GetPhysicalInventory_(dmi::PhysicalInventoryResponse* response);

class HWMgmtService final : public dmi::NativeHWManagementService::Service
{
    public:
        static HWMgmtService& getHWInstance()
        {
            static HWMgmtService hwinstance;
            return hwinstance;
        }

        grpc::Status StartManagingDevice(
                ServerContext* context,
                const dmi::ModifiableComponent* request,
                ServerWriter<dmi::StartManagingDeviceResponse>* writer
                )
        {
            return StartManagingDevice_(request, writer);
        }

        grpc::Status StopManagingDevice(
                ServerContext* context,
                const dmi::StopManagingDeviceRequest* request,
                dmi::StopManagingDeviceResponse* response
                )
        {
            return StopManagingDevice_(response);
        }

        grpc::Status GetManagedDevices(
                ServerContext* context,
                const google::protobuf::Empty* request,
                dmi::ManagedDevicesResponse* response
                )
        {
            return GetManagedDevices_(response);
        }

        grpc::Status GetPhysicalInventory(
                ServerContext* context,
                const dmi::PhysicalInventoryRequest* request,
                dmi::PhysicalInventoryResponse* response
                )
        {
            return GetPhysicalInventory_(response);
        }

    private:
        HWMgmtService()
        {
        }

        ~HWMgmtService()
        {
        }
};

#endif
