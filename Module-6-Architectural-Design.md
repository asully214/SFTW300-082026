# Module 6: DigitalHome Architectural Design

## 1. Architectural View Approach
### Kruchten's 4+1 View Model

Kruchten's 4+1 architectural view model is the best approach for the DH system because it provides different perspectives for the system's stakeholders. A single view may not represent the needs or concerns of homeowners, technicians, and developers. The five views will represent the system in the following ways:

- **Logical View:** Shows the main components, to include user accounts, environmental controls, lighting and appliances, scheduling and security. 
- **Process View:** Shows how the components communicate while the system is operating, such as processing sensor data, sending commands and activating alarms.
- **Development View:** Shows how the source code will be divided into modules so developers can build, test and maintain each part of the system.
- **Physical View:** Shows where the software and devices are placed, to include the users device to control the system, the DH server, environmental sensors, lights, appliances, and security devices.
- **Use-Case View:** Shows how normal users, master users, and technicians interact with the system to complete tasks.

This approach supports both the functional and nonfunctional requirements set out in Module 5. Owners can focus on system use, developers can understand the software components, technicians can examine the devices, and security personnel can evaluate authentication, communication, and data protection.
## 2. Architecture Styles
### Client Server Style

The client server style will be used for communication between the homeowner and the DH system. A phone (or other web connectable device) will act as the client and sent request to the DH server. The server will authenticate the user, verify their access level, process the commands, and return the current status of the home

### Layered Style

The server side system will use a layered architecture consisting of a user interface layer, control logic layer, device communication layer, and data storage layer. The user interface layer will display information and receive commands. The control logic layer will validate requests, process schedules, and apply security rules. The device communication layer will communicate with environmental sensors, lights, appliances, and security features. The data storage layer will maintain user accounts, settings, schedules and system records.

Separating these responsibilities will improve maintainability since a change to one layer will be less likely to affect the entire system. It also supports system security by preventing the user interface from accessing stored data or physical devices. Each layer can be tested separately, which will help improve reliability and make future expansion easier. 
## 3. Design Principles
### Modularity

The DH will be divided into separate modules for environmental monitoring, lighting, appliances, security, scheduling, and user accounts. Each module will be responsible for a specific group of system functions. This allows one feature to be updated or tested without having to redesign the whole system.  

### Abstraction

Abstraction will hide the detailed steps required to complete an action. A homeowner could select "turn on living room lights" without needing to understand the code, communication, or device commands used to perform the action. The user interface will allow simple controls for the user while the lower levels address the more technical details. 

### Encapsulation

Each module will protect its internal data and allow access only through defined operations. 

### High Cohesion and Low Coupling

Each module will maintain high cohesion by focusing on one main responsibility. 

Low coupling will be maintained by allowing modules to communicate through small interfaces. If the security module needs the lights during an alarm, it can request the light modules turnOn() operation instead of changing the modules data. This allows the design of a module to change without forcing the rest of the system to change. 
## 4. Requirements Traceability
### Functional Requirements

| ID | Requirement | Responsible Component | Architectural Support |
|---|---|---|---|
| FR-1 | Monitor Environmental Conditions | Environmental Monitoring Module | The device communication layer receives temperature and humidity readings, and the user interface displays them. |
| FR-2 | Adjust Temperature and Humidity | Environmental Control Module | The control logic validates temperature settings from 60°F to 80°F and humidity settings from 30% to 60% before sending commands to the devices. |
| FR-3 | Control Lights and Appliances | Lighting and Appliance Module | The client-server style allows authorized users to remotely send on-and-off commands through the server. |
| FR-4 | Detect Security Breaches | Security Module | The security module monitors door and window sensors and activates light and sound alarms when a breach is detected. |
| FR-5 | Schedule and Override Settings | Scheduling Module | The control logic processes hourly schedules, while the user interface allows users to manually override them. |
| FR-6 | Manage User Accounts | User Account Module | The server authenticates users, while master users and technicians can add, modify, or delete accounts based on their access level. |

### Nonfunctional Requirements

| Quality Attribute | Requirement | Architectural Support |
|---|---|---|
| Performance | Environmental conditions will be displayed every two seconds. | The process view will show the continuous flow of readings from the sensors through the server to the user interface. |
| Security | Users will log in with an account name and password, and Internet communication will be encrypted. | The client-server style centralizes authentication and access control, while encryption protects communication between the client and server. |
| Reliability | The system will have no more than one failure per 10,000 operations and will support backup and restoration. | The server and data-storage layer will use error handling, activity records, backups, and restoration procedures to protect system data. |
