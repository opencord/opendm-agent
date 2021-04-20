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

#ifndef DMI_PHYCOMP_FACTORY_H_
#include "dmi_phycomp_factory.h"
#endif



uint8_t FanComp::UpdateComp(uint8_t comp_number)
{
    return 0;
}

uint8_t FanComp::SetModifiableCompFields(dmi::ModifiableComponent mod_fields)
{
	/*Set the Component feilds sent from the NEM/DM in mod_fields */
    return 0;
}

uint8_t DiskComp::UpdateComp(uint8_t comp_number)
{
	/*Fetch the particular fan details from the onlp array and update the object*/
    /*Update ComponentSensorData*/
	return 0;
}

uint8_t DiskComp::SetModifiableCompFields(dmi::ModifiableComponent mod_fields)
{
	/*Set the Component feilds sent from the NEM/DM in mod_fields */
    return 0;
}

uint8_t ContainerComp::UpdateComp(uint8_t comp_number)
{
	/*Fetch the particular fan details from the onlp array and update the object*/
    /*Update ComponentSensorData*/
	return 0;
}

uint8_t ContainerComp::SetModifiableCompFields(dmi::ModifiableComponent mod_fields)
{
	/*Set the Component feilds sent from the NEM/DM in mod_fields */
    return 0;
}

uint8_t PortComp::UpdateComp(uint8_t comp_number)
{
	/*Fetch the particular fan details from the onlp array and update the object*/
    /*Update ComponentSensorData*/
	return 0;
}

uint8_t PortComp::SetModifiableCompFields(dmi::ModifiableComponent mod_fields)
{
	/*Set the Component feilds sent from the NEM/DM in mod_fields */
    return 0;
}

uint8_t CPUComp::UpdateComp(uint8_t comp_number)
{
	/*Fetch the particular fan details from the onlp array and update the object*/
    /*Update ComponentSensorData*/
	return 0;
}

uint8_t CPUComp::SetModifiableCompFields(dmi::ModifiableComponent mod_fields)
{
	/*Set the Component feilds sent from the NEM/DM in mod_fields */
    return 0;
}

uint8_t TransceiverComp::UpdateComp(uint8_t comp_number)
{
	/*Fetch the particular fan details from the onlp array and update the object*/
    /*Update ComponentSensorData*/
	return 0;
}

uint8_t TransceiverComp::SetModifiableCompFields(dmi::ModifiableComponent mod_fields)
{
	/*Set the Component feilds sent from the NEM/DM in mod_fields */
    return 0;
}

