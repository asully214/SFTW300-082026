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

## Module 3: Software Quality Assurance

### Security Threats

Because the DigitalHome includes controls for lighting, temperature, appliances, and security, a software defect or security weakness could affect the privacy and safety of the home. Software quality assurance should be used throughout the development instead of only at the end. 
One of the biggest threats to the DH system is unauthorized access. An attacker could gain access to the home network and control devices, disarm security devices, or access personal information of the homeowner. Weak passwords and poor user authentication could allow someone to disguise themselves as authorized users. The system needs strong authentication, secure password storage, and limits for failed login attempts.
Data security is another concern because the system could collect information about device usage, temperature settings, security status, and if the home is occupied. This data access by malicious actors, could threaten the security of the home. Encryption should protect sensitive information while it is stored and transmitted.

### V-Model Mitigation
The V-Model can improve DH quality and security because it connects each development phase with a testing phase. As the team refines requirements, it also plans the system and acceptance tests. Architectural design is tied to integration testing, and detailed design is tied to unit testing. This guarantees that testing is planned before the code is finished. 
Security requirements should also produce corresponding security tests. Unit testing can evaluate individual authentication and access control functions. Intergation testing can decide if authentication works properly across the user interface, network, and connected devices. System and acceptance testing will then confirm the system prevents unauthorized access while meeting the owners needs. 

### Quality Measurement Strategy

The first goal is to minimize the number of defects found after the release of the product.

**Questions:**
- Which defects occur most frequently?
- How effective are the current reviews and tests?
- What percentage of defects are detected before release?

**Metrics:**
- Number of defeats found during each stage of development.
- Percentage of tests passed.
- Percentage of code or requirements covered by tests.
- Number of customer reported defects after release.

The second goal is to improve the security of the DH system.

**Questions:**
- How many unauthorized access attempts are blocked?
- Does every protected function require authentication?
- How fast are security weaknesses corrected?

**Metrics:**
- Percentage of authentication test passed.
- Number of unresolved security vulnerabilities.
- Percentage of protected functions covered by access control tests.
- Average time required to correct a security threat or defect.

### QA Activities 
**Project Launch and Planning** The project manager and SQA team will develop the Software Quality Assurance Plan (SQAP), assign responsibilities, set standards, and establish security and quality goals. The outcome should be a documented plan explaining how quality will be achieved and measured. 

**Requirement Analysis** Developers, testers, security team, and customer or representatives will inspect the software requirements and create the system test plan and Requirements Traceability Matrix. The outcome should be an approved set of requirements connected to specific tests.

**Architectural and Detailed Design** Technical reviews will examine component interfaces, access control, and potential security weaknesses. The developments and testing teams will create unit and integration test plans. The outcome should be a design that meets the requirements and can be tested effectively. 

**Construction** Developers will perform code reviews, static analysis, white box testing, and unit testing. The expected outcome is reviewed and tested source code with identified defects corrected and documented. 

**Integration and System Testing** Testers will use black box and white box methods to evaluate component interactions, system functions, performance, and security. The expected outcome is an integrated system that performs correctly and meets the requirements. 

**Acceptance Testing** The customer or their representatives will conduct an acceptance test to validate that the product meets the homeowners needs. The team will then perform a postmortem to analyze the quality of the product and efectivness. The expected outcome is an accepted system and documented information that will be used to improve future work. 

### Benefits and Challenges 
The benefit of these QA activities is earlier defect detection. Correcting a problem during a requirement or design review is often easier and less expensive than correcting once the software is released. The V-Model improves traceability since certain requirements are connected to specific test. Security reviews and testing can minimize risks to users privacy and the systems integrity. 
The biggest challenges are the required time, cost, resources, and experience, sometimes are not always properly accounted for. Reviews, documentation, testing environments, and data collection could pressure the projects schedule. The team could also lack experience with specific needs.
To mitigate these, the team should prioritize high risk features, automate appropriate test, and assign quality responsibilities. 
