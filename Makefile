#Copyright 2021-present Open Networking Foundation
#
#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.
#You may obtain a copy of the License at
#
#http://www.apache.org/licenses/LICENSE-2.0
#
#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions and
#limitations under the License.

##################################################################################

# This makefile builds a opendm-agent and libdmi_grpc library
# Please refer ./README.md and ./BUILDING.md file for more details

CURDIR := $(shell pwd)
TARCHDIR ?= x86_64
BUILD_DIR := build
OBJDIR := $(CURDIR)
DMI_SOURCE_DIR := $(BUILD_DIR)/device-management-interface/

ifeq ($(DEB_CODENAME),jessie)
CXX = g++-4.9
else
CXX = g++
endif

DOCKER                     ?= docker
DOCKER_REGISTRY            ?=
DOCKER_REPOSITORY          ?= voltha/
DOCKER_EXTRA_ARGS          ?=
DOCKER_TAG                 ?= 2.1.1
IMAGENAME                  = ${DOCKER_REGISTRY}${DOCKER_REPOSITORY}openolt-test:${DOCKER_TAG}

# Version of Open Network Linux (ONL).
ONL_KERN_VER_MAJOR = 4.19

CXXFLAGS += -ggdb -Werror -Wall -std=c++11
CXXFLAGS += $(shell pkg-config --cflags-only-I grpc++)
GRPCFLAGS += `pkg-config --libs grpc++ grpc`
CXXFLAGS += -std=c++11 -fpermissive -Wno-write-strings -Wno-literal-suffix -I/usr/local/lib/
LDFLAGS += -L./build/
LDFLAGS += -lgrpc++_reflection -Wl,--as-needed -ldmi_grpc -lprotobuf -lpthread -ldl

DMIAGENT_SRCS =	src/main.cc 				\
                src/dmi_phycomp_factory.cc  \
				src/dmi_hw_mgmt.cc			\
				src/dmi_sw_mgmt.cc			\
				src/dmi_server.cc

DMIAGENT_INC =	-I./inc/                  \
                -I./protos/     \
                -I./protos/dmi/


DMIAGENT_OBJS = $(DMIAGENT_SRCS:.cc=.o)

all: onl opendm-agent
	mv opendm-agent $(BUILD_DIR)

opendm-agent: protos-lib $(DMIAGENT_OBJS)
	$(CXX) $(CXXFLAGS) $(DMIAGENT_OBJS) $(GRPCFLAGS) $(LDFLAGS) -o $@

src/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(DMIAGENT_INC) -c $< -o $@

protos-lib: prereq
	echo "Creating the libdmi_grpc.so using auto generated cpp-protos"
	if [ ! -e "$(OBJDIR)/protos/" ]; then \
		mkdir -p $(OBJDIR)/protos/; \
		cp -r $(DMI_SOURCE_DIR)/cpp/dmi $(OBJDIR)/protos; \
		g++ -shared -fPIC -g -ggdb -std=c++11 `pkg-config --cflags protobuf grpc` -I$(OBJDIR)/protos/ `find $(OBJDIR)/protos/ -name "*.cc"` -o $(OBJDIR)/$(BUILD_DIR)/libdmi_grpc.so; \
		cp $(OBJDIR)/$(BUILD_DIR)/libdmi_grpc.so /usr/local/lib/; \
	fi;

prereq: device-management-interface

device-management-interface:
	if [ ! -e "$(DMI_SOURCE_DIR)" ]; then \
		git clone https://github.com/opencord/device-management-interface.git $(DMI_SOURCE_DIR); \
	fi;

#########################################################################
##
##
##        ONL Target refered from openolt agent
##
###
ONL_REPO = onl
ONL_DIR = $(BUILD_DIR)/$(ONL_REPO)

onl:
	if [ ! -d "$(ONL_DIR)/OpenNetworkLinux" ]; then \
		mkdir -p $(ONL_DIR); \
		git clone https://github.com/opencomputeproject/OpenNetworkLinux.git $(ONL_DIR)/OpenNetworkLinux; \
		cp download/Makefile.onl $(ONL_DIR)/Makefile; \
		install -m 755 download/build-onl.sh $(ONL_DIR)/OpenNetworkLinux; \
		make -C $(ONL_DIR) onl-$(ONL_KERN_VER_MAJOR) INBAND=n; \
	else \
		if [ "$(INBAND)" = n -a "$$(grep "inband" $(ONL_DIR)/onl_build.mode | cut -d= -f 2)" = y ]; then \
			make -C $(ONL_DIR) onl-$(ONL_KERN_VER_MAJOR) INBAND=n; \
		fi; \
	fi;

test:
	${DOCKER} run --rm -v $(shell pwd):/app $(shell test -t 0 && echo "-it") ${IMAGENAME} make -C unit_test test

clean:
	rm -rf $(OBJDIR)/protos/
	rm -rf $(OBJDIR)/src/*.o
	rm -rf $(BUILD_DIR)/*.so
	rm -rf $(BUILD_DIR)/opendm-agent
	rm -rf $(DMIAGENT_OBJS)
