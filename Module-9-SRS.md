# Digital Home System Requirements Specification

## 1. Introduction

### 1.1 Purpose 

This document defines the functional and non functional requirements for the DH system. It gives users, developers, and testers a understanding of what the system must do and how its requirements can be verified.

### 1.2 Scope

The DH system will allow authorized users to monitor and control supported household devices. It will allow temperature monitoring and control, lighting and appliance control, security alerts, scheduling, and account management. 

The system is designed to make home devices easier to monitor and control from inside and outside the home, and monitor security conditions. 

### 1.3 Intended Users

-**General users** can monitor home conditions, controls supported devices, and manages device scheduling.
-**Master users** can manage user accounts and permissions.
-**Technicians** can access the system or devices information needed to perform maintenance.

## 2. System Overview

The DH system connects users with compatible sensors and devices. Its main functional areas are user accounts, device control, scheduling, security and data storage.

## 3. Functional Requirements

| ID | Requirement | User need | Verification |
|---|---|---|---|
| FR-01 | The system shall display the current temperature and humidity reported by each connected sensor to an authorized user. | Monitor home conditions. | Compare displayed readings with sensor readings. |
| FR-02 | The system shall allow an authorized user to set a temperature target from 60°F through 80°F. | Control home temperature. | Test values at and outside the allowed range. |
| FR-03 | The system shall allow an authorized user to set a humidity target from 30% through 60%. | Control home humidity. | Test values at and outside the allowed range. |
| FR-04 | The system shall allow an authorized user to remotely turn supported lights and appliances on or off. | Control devices remotely. | Test the on and off command for each supported device. |
| FR-05 | The system shall allow an authorized user to create, edit, and disable schedules for supported devices. | Schedule device operation. | Create, edit, and disable a schedule, then verify the device response. |
| FR-06 | The system shall allow an authorized user to manually change a device’s state while a schedule is active. | Use manual control when needed. | Change the device state during an active schedule and verify the result. |
| FR-07 | The system shall notify authorized users when a connected door or window sensor reports a security breach. | Receive security alerts. | Trigger a sensor event and verify that an authorized user receives an alert. |
| FR-08 | The system shall allow a master user to create, update, and disable user accounts and assign permissions. | Manage account access. | Test each account action and verify the assigned permissions. |
| FR-09 | The system shall reject device-control commands from unauthenticated or unauthorized users and leave the device setting unchanged. | Protect device access. | Attempt a command without the required access and verify that no setting changes. |
| FR-10 | The system shall display reported power consumption for each connected appliance that provides power data. | Monitor appliance power use. | Compare the displayed value with the appliance’s reported reading. |
| FR-11 | The system shall display an error when a requested temperature or humidity setting is outside its allowed range and shall leave the existing setting unchanged. | Prevent invalid settings. | Submit out-of-range values and verify the error and unchanged setting. |

## 4. Non Functional Requirements

| ID | Requirement | Verification |
|---|---|---|
| NFR-01 Performance | The system shall display a new temperature or humidity reading within two seconds after the gateway receives it. | Measure the time from gateway receipt to display. |
| NFR-02 Security | The system shall require authentication before a user can issue device-control commands. | Attempt a command while signed out and with accounts having different permissions. |
| NFR-03 Security | The system shall encrypt data transmitted between the user interface and the home system. | Inspect network traffic during a test session. |
| NFR-04 Reliability | In a test of 10,000 valid system operations, no more than one operation shall fail because of a system error. | Run and record the 10,000-operation test. |
| NFR-05 Input handling | The system shall validate temperature and humidity values before sending them to a device. Invalid values shall not change the saved target. | Test values below, within, and above each allowed range. |
| NFR-06 Maintainability | The system shall provide documented interfaces for its user account, device control, scheduling, security, and data-storage areas. | Review the documentation against the implemented interfaces. |

## 5. Assumptions and Constraints

- The home systems has compatible sensors and devices connected.
- Device control depends on the device and available network connection.
- Users must have an account and the required permissions to view or make changes to a homes status.
- The allowed temperature target range is 60 - 80 degrees F, and humidity range is 30% - 60%.

## 6. Traceability 

| User need or project goal | Related requirements |
|---|---|
| Monitor and manage home conditions | FR-01, FR-02, FR-03, NFR-01, NFR-05 |
| Control devices remotely and by schedule | FR-04, FR-05, FR-06 |
| Monitor home security | FR-07 |
| Protect account and device access | FR-08, FR-09, NFR-02, NFR-03 |
| Monitor appliance power | FR-10 |
| Support dependable, maintainable operation | NFR-04, NFR-06 |

## 7. Glossary

-**DH:** Digital Home.

-**Functional requirement:** A behavior or service the system must provide. 

-**Non functional requirement:** A quality attribute or constraint the system must meet. 

-**Traceability:** The link between a requirement, the user need it supports, and how it will be verified.  
