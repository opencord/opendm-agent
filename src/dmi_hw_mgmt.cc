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

#include "dmi_hw_mgmt.h"

grpc::Status StartManagingDevice_(
              const dmi::ModifiableComponent* request,
              ServerWriter<dmi::StartManagingDeviceResponse>* write)
{
    return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
}

grpc::Status StopManagingDevice_(dmi::StopManagingDeviceResponse* response)
{
    return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
}

grpc::Status GetManagedDevices_(dmi::ManagedDevicesResponse* response)
{
    return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
}

grpc::Status GetPhysicalInventory_(dmi::PhysicalInventoryResponse* response)
{
    return Status(grpc::StatusCode::UNIMPLEMENTED, "RPC not implemented");
}


