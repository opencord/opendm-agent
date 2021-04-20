## System Requirements

**Hardware** :

CPU: Dual-core (4 Threads) up.

Memory: 6GB

Storage: 50GB of free space.

**Software** :

1. opendm-agent builds on Debian GNU/Linux 8.11.1 (jessie)* . The ISO installer image is downloadble from [here](https://cdimage.debian.org/cdimage/archive/8.11.1/amd64/iso-cd/debian-8.11.1-amd64-netinst.iso)


2. At least 4G of ram and 4G of swap - compilation is memory intensive

3. Essential tools for building packages

Install the following packages

    `sudo apt-get update && sudo apt-get install -y git pkg-config build-essential autoconf libgflags-dev clang libc++-dev unzip libssl-dev gawk debhelper debhelper dh-systemd init-system-helpers curl cmake ccache g++-4.9 wget ca-certificates lcov libgoogle-glog-dev libpcap-dev`

Run the below commands to ensure that g++-4.9 and gcc-4.9 are default g++ and gcc compiler versions.

```shell
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 20
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 20
```

Follow the instructions  [here](https://docs.docker.com/engine/install/debian/) to install `docker-ce`. It is not necessary to install `docker-ce-cli` and `containerd.io`.

4. Install cmake version 3.5.1 or above.

```shell
cd /tmp
git clone -b v3.5.1 https://gitlab.kitware.com/cmake/cmake.git
cd /tmp/cmake
./bootstrap
make
sudo make install
```
5. Install gRPC version v1.31.1

```shell
cd /tmp
git clone -b v1.31.1  https://github.com/grpc/grpc
cd /tmp/grpc
git submodule update --init
mkdir -p cmake/build
cd cmake/build
cmake ../.. -DgRPC_INSTALL=ON                \
            -DCMAKE_BUILD_TYPE=Release       \
            -DgRPC_ABSL_PROVIDER=module     \
            -DgRPC_CARES_PROVIDER=module    \
            -DgRPC_PROTOBUF_PROVIDER=module \
            -DgRPC_RE2_PROVIDER=module      \
            -DgRPC_SSL_PROVIDER=module      \
            -DgRPC_ZLIB_PROVIDER=module
make
sudo make install
# copy library and grpc_cpp_plugin to path below.
sudo cp `find . -name "*.a"` /usr/local/lib/
sudo cp `find . -name grpc_cpp_plugin` /usr/local/bin/
```
6. Install latest version of Git (optional)

By default the apt-get install an older version of git (2.1.4) on debian jessie 8.11.1. This older version does not support some of the latest git options. You may want to install a later version of git using procedure below.

```shell
sudo apt-get remove --purge git ## Removes older verion of git
sudo apt update
sudo apt install make libssl-dev libghc-zlib-dev libcurl4-gnutls-dev libexpat1-dev gettext unzip
wget https://github.com/git/git/archive/v2.18.0.zip -O git.zip
unzip git.zip
cd git-*
make prefix=/usr/local all
sudo make prefix=/usr/local install
```

## Build procedure

clone `opendm-agent`:

```shell
git clone "https://gerrit.opencord.org/opendm-agent"
cd opendm-agent
make
```

NOTE: The above make build the ONL image well as docker, opendm-agent will be built on top of this.

## Cleanup

To cleanup the repository and start the build procedure again, run:

```shell
make clean
```
