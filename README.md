# SFTW300-082026
SFTW300 starting in August 2026

## Development Strategy

The DH team will use an incremental, risk first development strategy. The system will be divided into smaller increments, with each increment producing tested functionality that can be integrated with the previous work.

The first increment will create a basic end to end structure connecting the user interface, master control system, database and a few sensors and controllers. It will also address high risk functions like user authentication, wireless communication, and device control. Addressing those difficult components early will give enough time to identify and solve problems before it affects the entire system.

Later increments will add environmental controls, appliance management, security functions, data storage and other features. This reduces complexity, supports early testing and feedback, and allows the ability to later improve estimates using results from earlier increments.

## Development Increments

1. **Increment 1 - Core Systems** Authentication, basic user interface, master control system, database connection, and one sensor/controller connection.
2. **Increment 2 - Environmental Control** Temperature, humidity, lighting, scheduling, and sensor monitoring.
3. **Increment 3 - Appliance and Security Control** Appliance switches, contact sensors, and alarms.
4. **Increment 4 - Integration and Refinement** System integration, testing, additional device support, and user interface refinement.

## Contex Diagram

User["Homeowner/ User"]
Technician["DH Technician"]
DH["DigitalHome System"]
Devices["Household Devices"]
Sensors["Sensors and controllers"]
Web["Internet"]

User -->|"Monitor and control home"| DH
DH-->|"Status and notifications"| User
Technician-->|"Configure and maintain"| DH
DH-->|"Control commands"| Devices
Devices-->|"Device status"| DH
Sensors-->|"Sensor data"| DH
DH-->|"Configuration and control signals"| Sensors
DH<-->|"Remote Communication"| Web

The contex diagram places the DigitalHome System inside the system boundary and shows its interactions with external entities. Homeowners use the system to monitor and control their homes, and technicians configure and maintain it. The system exhacnges information with household devices, sensors, and controllers, and internet services. 

## Conceptual design

The conceptual design separates the DigitalHome System into the following components:

-**User Interface** Allows users to monitor and make changes to the home remotely.
-**Authentication and User Management** Verifies the uses and controls access to system functions.
-**Master Control Component** Coordinates communication between system components.
-**Environmental Control Component** Manages temperature, humidity, and lighting.
-**Appliance Control Component** Monitors and controls the supported appliances.
-**Security Component** Processes data from security sensors and triggers alarm or notification.
-**Communication Component** Manages communication between all components of the system.
-**Database Component** Stores the user profiles, settings, schedule, and device status

