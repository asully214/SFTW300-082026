# Digital Home Software Design Document

## 1. Introduction

### 1.1 Purpose

This document describes the software design for the DH system. It explains the systems architecture, components, interface, design decisions, and plans for implementation and testing.

### 1.2 Scope

The DH system allows authorized users to monitor and manage compatible home devices. It functions include temperature and humidity monitoring and control, lighting and appliance control, appliance power monitoring, security alerts, scheduling, and account management. This document describes how the design will support the requirements in 'Module-9-SRS.md'.

### 1.3 Definitions and Abbreviations

-**DH:** Digital Home. 
-**SRS:** Software Requirements Specification.
-**SDD** Software Design Document.
-**Gateway:** The component that communicates with connected system sensors and devices.
-**Layered Architecture:** An organization in which each layer has a defined responsibility and communicates through interfaces.

### 1.4 Related Documents

- 'Module-9-SRS.md' - DH functional and non functional requirements.

## 2. System Overview

The DH system connects a user interface to home devices and sensors through system services and gateway. Users can see device status and readings, change device settings, manage schedules, and receive security alerts. The design must support access control, valid temperature and humidity ranges, and update sensors in given time frame. 

The main design goals are to: 

- Support the functions set out in the SRS.
- Protect device controls and user account information.
- Keep system components focused on specific responsibilities.
- Allow a device or component to be updated with minimal impact on other components.

## 3. Architectural Design

### 3.1 Architectural View Approach 

The design uses **Kruchten's 4+1 view model**. It gives different stakeholders views of the systems logical structure, processes, development components, physical deployment, and user scenarios. 

### 3.2 Architectural Styles

The design combines **client server** and **layered** styles. 

- **Client server:** The user interface sends request to DH services, which check permissions and communicate with devices through the gateway. This supports the remote controls and sensor updates.
- **Layered architecture:** The presentation, service, domain, and data/device communication layers have separate responsibilities. This makes the design easier and to test and maintain.

### 3.3 Major Components

-**User interface:** Displays readings, controls, schedules and alerts. 
-**Account and authentication service:** Verifies the user and permissions. 
-**Device service:** Sends authorized commands to supported devices and retrieves readings.
-**Scheduling service:** Stores and applies device schedules.
-**Security and notification service:** Process door and window sensors and sends security alerts.
-**Data storage:** Stores account information, device settings, schedules, and event records.
-**Device gateway:** Communicates with compatible sensors and devices.

### 3.4 Component Diagram

The components interact as follows:

- The **User Interface** sends sign-in requests to the **Account and Authentication Service**.
- The **User Interface** sends authorized requests to the **DH Services**.
- **DH Services** coordinate device control, scheduling, and security notifications.
- The **Device Control**, **Scheduling**, and **Security and Notification** services communicate with the **Device Gateway**.
- The **Device Gateway** communicates with compatible sensors and home devices.
- The **Account and Authentication Service** and **DH Services** use **Data Storage** to retrieve or save system information.
### 3.5 Deployment Diagram

The system is deployed across these nodes:

- A user accesses the system through a browser on a computer or mobile device.
- The browser communicates over a network with the DH application server.
- The application server runs the user interface services, authentication, device control, scheduling, security notifications, and data storage.
- The application server communicates with the home device gateway over the home network.
- The gateway communicates with compatible sensors and devices, such as thermostats, lights, appliances, and door or window sensors.

## 4. Design Constraints

- The system will be implemented in C++.
- Device control depends on compatible devices, sensors, and network connection.
- Device control commands must require authentication and authorization.
- Temperature targets must remain in the range of 60 - 80 degrees, and humidity 30 - 60%.
- The design must support the SRS performance goal for displaying new readings within 2 seconds after gateway receipt.

## 5. Detailed Design

### 5.1 Subsystems and Interfaces

| Subsystem | Responsibility | Example interface |
|---|---|---|
| Account service | Authenticate users and check permissions | `authenticateUser()` |
| Device service | Validate and send device commands | `setTemperature()` |
| Scheduling service | Create, edit, disable, and apply schedules | `saveSchedule()` |
| Security service | Process sensor events and issue alerts | `processSensorEvent()` |
| Data storage | Save and retrieve accounts, settings, schedules, and events | `saveSetting()` |

The user interface will call service interface instead of communicating directly with devices. The device service will check user permissions and validate requested values before sending a command through the gateway.

### 5.2 Data Model

The main data objects are:

-**User:** User ID, account name, and assigned roles.
-**Device:** Device ID, name, device type, and connection status.
-**Schedule:** Schedule ID, device ID, active days/times, and action to be scheduled. 
-**SensorReading:** Device ID, reading type, value, and time received.
-**SecurityEvent:** Sensor ID, event type, time received, and notification status.

### 5.3 Sequence: Setting a Temperature

When a user enters a temperature target, the system verifies the user’s identity and permission. It checks that the target is within the allowed range of 60°F to 80°F. If the target is valid, the device service sends the command through the gateway to the thermostat. The system then displays whether the change succeeded or produced an error.

### 5.4 Class Diagram

The main classes are **User**, **Device**, **Schedule**, and **SensorReading**. A **User** has an assigned role and can control authorized devices. A **Device** has a type, connection status, and current state. A **Schedule** stores the times and actions for a device. A **SensorReading** records the device ID, reading type, value, and time received.

## 6. Design Considerations

### 6.1 Design Principles

-**Modularity:** Account, device, scheduling, security and storage functions are divided into separate components. 
-**Abstraction:** The interface uses service operations such as 'setTemperature()' without exposing the gateway details to the user interface. 
-**Encapsulation:** Device and account data will be private to their own classes and accessed through defined functions.
-**High cohesion:** Each component focuses on one area.
-**Low coupling:** Components communicate through interfaces, so a change to scheduling does not require rewriting account authentication.

### 6.2 Alternatives and Trade Offs

A single monolithic design would have fewer components at start, but changes to device control could affect scheduling, security, and the user interface. The layered design requires clear interface between components, but it makes testing and later maintenance easier.

A direct connection between the user interface and each device would make the design harder to secure and maintain. The gateway and device service provide a controlled path for device communication. 

## 7. User Interface Design

The main screen will show current temperature and humidity, device status, power readings, active schedules, and security alerts. Users will select a device to view its status or issue a command. Master users will also have account and permission controls.

A temperature change interaction will follow this sequence:

1. The user selects a thermostat and enters the desired value.
2. The system checks the users permission and validates the value.
3. The device service sends the command through the gateway.
4. The interface will display the result or if an error occurs.

## 8. Implementation Plan

Implementation will proceed in small increments:

1. Define the core classes and service interfaces.
2. Implement account authentication and permission checks.
3. Implement device status and temperature/humidity validation.
4. Add lighting, appliance and power monitoring functions.
5. Add schedules and manual overrides.
6. Add security event handling and notifications,
7. Integrate the user interface, services, storage and gateway.
8. Run system and acceptance tests against the SRS.

The project will use GitHub branches and commits to track design and implementation and challenges. This keeps changes organized and increase traceability. 

## 9. Testing and Validation

-**Unit testing:** Test account permissions, value validation, schedule operations, and device service behavior separately.
-**Integration testing:** Verify that the interface, services, storage, and gateway share data properly.
-**Boundary testing:** Test temperature and humidity ranges.
-**Security testing:** Verify that unauthorized and unauthenticated users can not change device settings or gain access to the system. 
-**Performance Testing:** Measure whether new readings display within the SRS two second target. 
-**System and acceptance testing:** Verify that complete user tasks meet the functional requirements defined in the SRS.

## 10. Glossary

-**Authentication:** Verifying a users identity.
-**Authorization:** Checking what an authenticated user is allowed to do.
-**Gateway:** The system component that communicates with devices and sensors.
-**Interface:** A defined way for one component to request a service from another component. 
-**Manual override:** A users direct device command to ignore or modify a schedule that is still active.

## 11. Appendices 

### Appendix A: C++ Implementation Considerations
- Use `std::string` for user, device, and schedule IDs.
- Use enumerations such as `UserRole`, `DeviceType`, and `ReadingType` for fixed categories.
- Use `double` for temperature, humidity, and power readings; validate each value before use.
- Use `std::unordered_map<std::string, Device>` when devices need to be retrieved by ID.
- Use `std::vector<Schedule>` for a user’s schedules when schedules are processed as a collection.
- Use C++ standard-library containers and RAII to manage resources. If polymorphic device classes are needed, use smart pointers such as `std::unique_ptr` rather than owning raw pointers. This reduces the risk of memory leaks and makes ownership clearer.

### Appendix B: Requirement Traceability Examples

| SRS requirement | Design components | Verification |
|---|---|---|
| FR-02: Set temperature within the allowed range | User interface, account service, device service, gateway | Boundary and integration tests |
| FR-05: Manage device schedules | User interface, scheduling service, storage, gateway | Schedule unit and system tests |
| FR-07: Notify users of a security breach | Security service, gateway, notification interface | Sensor-event integration test |
| FR-09: Reject unauthorized commands | Account service, device service | Security test |
| NFR-01: Display new readings within two seconds | Gateway, device service, user interface | Performance test |
