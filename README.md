# opendm-agent
The Open DM Agent runs on the OLT device and implements the below functionalities:

Implementation of the gRPC Server on ONF/SEBA community defined DMI towards Open Device Manager/Operator NEM components.
a. Hardware Management
b. Software Management
c. Events Management
d. Metrics Management

Implementation of the Device Context Management (Configuration, UUID generation, Inventory, States)
Implementation of the FSM for pOLT Software upgrades
Consume the Threshold configuration and generation of threshold based (TCA) events
Send the Events, Metrics on GRPC Streams, if GRPC Streams RPC is performed
Publish the Events, Metrics on Message Bus (Kafka) if Message Bus endpoint is configured
Persistency of the northbound configuration and restoration of the configuration after device reboot

```text
Option 1:
 +---------------------------------+
 |                                 |
 |          Operator NEM           |
 |          Components             |
 |                                 |
 +-------+--------+---------+------+
                   |    |
      dmi gRPC API |    |Kafka
                   |    |
                   |    |
                   |    |
+--------------------- ---------------+
|                  |                  |
|         +------------------+        |
|         |   OpenDM  agent  |        |
|         |                  |        |
|         +--------+---------+        |
|                  |                  |
|        onlp API  | Linux utils      |
|                  |                  |
|                  |                  |
|         +---------+  +----------+   |
|         |         |  |          |   |
|         |ONL/ONLP |  |Linux cmds|   |
|         +---------+  +----------+   |
|                                     |
|           White box OLT             |
+-------------------------------------+

```

```text
Option 2:

 +---------------------------------+
 |                                 |
 |          Operator NEM           |
 |          Components             |
 |                                 |
 +-------+--------+---------+------+
                   |    |
      dmi gRPC API |    |Kafka
                   |    |
  +---------------------------------+
  |       Open Device Manager       |
  |                                 |
  |       +------------------+      |
  |       | OpenDM adapter   |      |
  +-------+--------+---------+------+
                   |    |
      dmi gRPC API |    |grpc stream
                   |    |
+--------------------- ---------------+
|                  |                  |
|         +------------------+        |
|         |   OpenDM  agent  |        |
|         |                  |        |
|         +--------+---------+        |
|                  |                  |
|        onlp API  | Linux utils      |
|                  |                  |
|                  |                  |
|         +---------+  +----------+   |
|         |         |  |          |   |
|         |ONL/ONLP |  |Linux cmds|   |
|         +---------+  +----------+   |
|                                     |
|           White box OLT             |
+-------------------------------------+
```

## How to Install:
Copy the build/opendm-agent and build/libdmi_grpc.so to target.

## How to Run:
Run ./opendm-agent
