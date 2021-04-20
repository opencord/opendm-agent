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
#define DMI_PHYCOMP_FACTORY_H_

#include "hw_management_service.grpc.pb.h"
#include "hw_management_service.pb.h"
#include <iostream>
#include <string>
/*
 * PhyComponent
 * PhyComponent implement the same interface so that the classes can refer
 * to the interface not the concrete Component
 */
class PhyComponent
{
    public:
        dmi::Component comp;
        uint8_t comp_number;

        /*Interfaces where each subclasses implements thier specific details*/
        virtual uint8_t UpdateComp(uint8_t comp_number) = 0;
        virtual uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields) = 0;

        virtual ~PhyComponent() {}
};


/*
 * Concrete Component
 * define Component to be created
 */
class FanComp : public PhyComponent
{
	public:
  	FanComp()
  	{
        /*Fill the default/common parameters here*/
		this->comp.set_class_( dmi::ComponentType::COMPONENT_TYPE_FAN);
		this->comp.set_is_fru( 1 );
  	}

	uint8_t UpdateComp(uint8_t comp_number);
	uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields);
	~FanComp() {}
};



/*
 * Concrete Component
 * define Component to be created
 */
class DiskComp : public PhyComponent
{
    public:
        DiskComp()
        {
            this->comp.set_class_( dmi::ComponentType::COMPONENT_TYPE_STORAGE);
            this->comp.set_is_fru( 0 );
        }

        uint8_t UpdateComp(uint8_t comp_number);
        uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields);
        ~DiskComp() {}
};


/*
 * Concrete Component
 * define Component to be created
 */
class ContainerComp : public PhyComponent
{
    public:
        ContainerComp()
        {
            this->comp.set_class_( dmi::ComponentType::COMPONENT_TYPE_CONTAINER);
            this->comp.set_is_fru( 0 );
            //set the container attribute
        }

        uint8_t UpdateComp(uint8_t comp_number);
        uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields);
        ~ContainerComp() {}
};



/*
 * Concrete Component
 * define Component to be created
 */
class PortComp : public PhyComponent
{
    public:
        PortComp()
        {
            this->comp.set_class_( dmi::ComponentType::COMPONENT_TYPE_PORT );
            this->comp.set_is_fru( 0 );
        }

        uint8_t UpdateComp(uint8_t comp_number);
        uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields);
        ~PortComp() {}
};


/*
 * Concrete Component
 * define Component to be created
 */
class CPUComp : public PhyComponent
{
    public:
        CPUComp()
        {
            this->comp.set_class_( dmi::ComponentType::COMPONENT_TYPE_CPU );
            this->comp.set_is_fru( 0 );
        }

        uint8_t UpdateComp(uint8_t comp_number);
        uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields);
        ~CPUComp() {}
};

/*
 * Concrete Component
 * define Component to be created
 */
class TransceiverComp : public PhyComponent
{
    public:
        TransceiverComp()
        {
            this->comp.set_class_( dmi::ComponentType::COMPONENT_TYPE_TRANSCEIVER );
            this->comp.set_is_fru ( 1 );
        }

        uint8_t UpdateComp(uint8_t comp_number);
        uint8_t SetModifiableCompFields(dmi::ModifiableComponent mod_fields);
        ~TransceiverComp() {}
};


/*
 * Creator
 * contains the implementation for all of the methods
 * to manipulate products except for the factory method
 */
class Creator
{
    public:

        virtual PhyComponent* CreateFanCompInst()         = 0;
        virtual PhyComponent* CreateDiskCompInst()        = 0;
        virtual PhyComponent* CreateContainerCompInst()   = 0;
        virtual PhyComponent* CreatePortCompInst()        = 0;
        virtual PhyComponent* CreateCPUCompInst()         = 0;
        virtual PhyComponent* CreateTransceiverCompInst() = 0;
        virtual void removeComponent( PhyComponent *comp ) = 0;
        virtual ~Creator() {}
};

/*
 * Concrete Creator
 * implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the products
 */
class ConcreteComp : public Creator
{
    public:
        ~ConcreteComp() {}

        PhyComponent* CreateFanCompInst()
        {
            return new FanComp();
        }

        PhyComponent* CreateDiskCompInst()
        {
            return new DiskComp();
        }

        PhyComponent* CreateContainerCompInst()
        {
            return new ContainerComp();
        }

        PhyComponent* CreatePortCompInst()
        {
            return new PortComp();
        }

        PhyComponent* CreateCPUCompInst()
        {
            return new CPUComp();
        }

        PhyComponent* CreateTransceiverCompInst()
        {
            return new TransceiverComp();
        }

        void removeComponent( PhyComponent *comp )
        {
            delete comp;
        }
};
#endif

