## 1. Project Goal
The DigitalHome (DH) project aims to provide homeowners with a centralized system for monitoring and controlling their home environment. Through a web-connected device, users can adjust temperature and humidity settings, control lights and small appliances, monitor security sensors, and schedule automated settings. The system is intended to make home management more convenient while maintaining security, reliability, and the ability for users to take manual control.
## 2. Target Users
General User: A homeowner or resident who needs to monitor environmental conditions, control connected devices, manage security features, and adjust scheduled settings.
Master User: A homeowner or resident with additional permissions who needs to manage user accounts, access restrictions, default settings, and system operations.
DH Technician: A trained technician who needs to install, configure, troubleshoot, and maintain the DigitalHome system and its connected devices.

## 3. Functional Requirements

### 1: Monitor Enviromental Condititons
The DH shall display the temperature and humidity readings for each connected sensor. 

**Rationale:** This allows the user to monitor climate conditions throughout the home. 

### 2: Adjust Temperature and Humididty
The DH shall allow authorized users to set the temperature betwee 60 and 80 degreese and humidity between 30 and 60%.

**Rationale:** These ranges give specific and measurable bondaries for system operation and testing. 

### 3: Control lights and Appliances
The DH shall allow users to configure connected lights and appliences on and off remotely.

**Rationale:** This allows the users to control devices inside or away from the home.

### 4: Detect Security Breaches
The DH shall detect a security breach from connected window or door sensors and activate the lights and sound the alarm. 

**Rationale:** This provides the homeowner with automatic security monitoring. 

### 5: Schedule and Bypass Settings
The DH shall allow users to scedule climate, lighting, appliance and security settings by the hour and allow a manual overide if unwanted for a specific time. 

**Rationale:** This gives the users the ability to automatically control the system, while still having the ability to bypass manually if desired. 

### 6: Manage User Accounts
The DH shall allow a master user or technician to add and delete user accounts to the system.

**Rationale:** This allows authorized users to control who has access to the system.

## 4. Nonfunctional Requirements

### 1: Performance
The DH shall update the displayed climate, power, and lighting condidtons once every 2 seconds. 

**Rationale:** Users should have accurate real time information to monitor and respond to changes.

### 2: Security
The DH shall require an account name and password for access to the system and shall encrypt all information passed over the internet.

**Rationale: Authentication and encryption protect the security of the home by only allowing authorized users to access home information. 

### 3: Reliability
The DH shall experience failure no more than once per 10,000 operations.

**Rationale:** The system controls home and security functions, so it must operate reliably to protect the home owner.

## 5. Use Case Model 

The use case mode identifies the main actors and how they interact with the DH system.

### UC-1: Monitor and Control the Home

**Primary Actor:** General User

**Goal:** View environmental conditions and control connected devices.

**Precondition:** The user is logged into an authorized account.

**Main Scenario:**
1. The user opens the DH dashboard.
2. The system displays the current temperature, humidity, lighting, appliance, and security information.
3. The user selects a setting or connected device.
4. The user enters the desired change.
5. The system sends the command to the appropriate controller.
6. The system displays the updated condition.

**Postcondition:** The requested change is completed and displayed to the user.

**Exception:** If the controller cannot be reached, the system displays an error message and does not show the request as completed.

### UC-2: Manage Scheduled Settings

**Primary Actor:** General User

**Goal:** Create or override scheduled home settings.

**Precondition:** The user is logged in and has permission to manage schedules.

**Main Scenario:**
1. The user opens the scheduling page.
2. The user selects a date and time.
3. The user selects the temperature, humidity, lighting, appliance, or security settings.
4. The system validates and saves the schedule.
5. The system applies the settings at the scheduled time.
6. The user may manually override a scheduled setting.

**Postcondition:** The schedule is saved or overridden, and the current setting is recorded.

**Exception:** If a setting is missing or outside an allowed range, the system displays an error and does not save the schedule.

### UC-3: Manage User Accounts

**Primary Actors:** Master User and DH Technician

**Goal:** Add, modify, or delete a user account.

**Precondition:** The master user or technician is logged in with account-management permission.

**Main Scenario:**
1. The actor opens the account-management page.
2. The actor selects the option to add, modify, or delete an account.
3. The actor enters or updates the account information.
4. The system validates the information.
5. The system saves the change.

**Postcondition:** The account information is added, updated, or removed.

**Exception:** If required information is missing or a username already exists, the system displays an error and does not save the change.

### UC-4: Respond to a Security Breach

**Primary Actor:** Door or Window Sensor

**Goal:** Detect and report unauthorized entry.

**Precondition:** The DH security system is active.

**Main Scenario:**
1. A door or window sensor detects a security breach.
2. The sensor sends the event to the DH system.
3. The system activates the light and sound alarms.
4. The system records the event.
5. The system displays a security alert to the user.

**Postcondition:** The alarms are active and the security event is recorded.

**Exception:** If communication with a sensor fails, the system records the failure and displays an error to the user.

## 6. Rationale and Challanges

A rationale sentence was included in each functional and nonfunctional requirement. 
The biggest challange was seperating functional requirements from nonfunctional requirements. 

## 7. Connection to Module 4 WBS

The requirments in this document will help guide the design and devlopment tasks set out in the module 4 WBS. 

| Requirements | WBS Area | Design, Development, and Testing Connection |
|---|---|---|
| Temperature and humidity monitoring and control | Environmental Controls | Develop the sensor and controller components and test the allowed temperature and humidity ranges. |
| Lighting and appliance control | Appliance and Security Controls | Develop the power-switch controls and verify that authorized users can turn connected devices on and off. |
| Security monitoring and alarms | Appliance and Security Controls | Connect door and window sensors to the alarm functions and test both normal and failure scenarios. |
| Scheduling and manual overrides | Core System Development | Develop the scheduling functions and verify that users can create and override scheduled settings. |
| User-account management | Core System Development | Develop account and permission functions and test access for general users, master users, and technicians. |
| Performance, security, and reliability | Integration and Testing | Measure update times, test authentication and encryption, and verify system behavior during failures. |
| Requirements and use cases | Requirements and Planning | Use the documented requirements and scenarios as the basis for system design and acceptance testing. |

These connections provide traceability between the requirements and the project tasks. Each function can be connected to a design component and a test case, which will make it easier to confirm that the completed DigitalHome system meets the identified user needs.



