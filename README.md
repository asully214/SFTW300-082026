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

## Module 4: Project Planning and Managment

### Project Planning 
The DigitalHome Project will use a Work Breakdown Structure (WBS) that divides development into smaller manageable tasks connected to the four increments defined earlier in this README file.

1. **Requirements and Planning - 3 effort points:** Review requirements, identify steak holders, assign responsibilities, and establish acceptance criteria. This task is low complexity but requires participation from the whole team.

2. **Core System Development - 8 effort points:** Develop basic user interface, authentication functions, master control system, database connection, and sensor/controller connection. This is a high effort task because it established the architecture used by the remaining components.

3. **Environmental Controls - 5 effort points:** Implement temperature, humidity, lighting, scheduling, and sensor monitoring features.

4. **Appliance and Security Controls - 8 effort points:** Implement appliance switches, contact sensors, alarms. access controls, and security notifications. This receives a higher estimate because failures could affect safety and privacy.

5. **System Integration and Testing - 8 effort points:** Connect all components and conduct unit, integration, system, security and acceptance testing. Team coordination will be needed and testing resources will be required.

6. **Documentation and Release - 3 effort points:** Update technical documentation, user instructions, test results and information regarding release. 

The estimates use relative effort points based on the task complexity, security risk, team experience, and available resources. The team will refine the estimates as information is learned during each increment.    
### Risk Management 

The team will maintain a risk register and review it during each project increment. Risks will be classified as project, technical or business risk and evaluated accordingly.

| Risk | Category | Likelihood | Impact | Response |
|---|---|---|---|---|
| Tasks take longer than estimated | Project | Medium | High | **Control:** Monitor the Kanban board, identify delays early, and reassign work when necessary. |
| Team members or resources become unavailable | Project | Medium | Medium | **Assumption:** Include scheduling flexibility and maintain documentation so another team member can continue the work. |
| Components or connected devices fail to communicate | Technical | Medium | High | **Control:** Define component interfaces early and perform incremental integration testing. |
| Unauthorized access exposes user or household information | Technical | Medium | High | **Avoidance and control:** Use authentication, access controls, encryption, code reviews, and security testing. |
| A third-party network or cloud service becomes unavailable | Business | Low | High | **Transfer and control:** Use agreements with service providers and design basic local functions to continue during an outage. |

High-impact risks will receive priority even when their likelihood is low. The team will assign an owner to each risk, document warning signs, and monitor whether the selected response is reducing the risk. The risk register will be updated whenever requirements, resources, or system conditions change.

### Configuration Management

Configuration management will ensure that the team can identify, control and reproduce each version of the system. The following configuration items will be managed:

-**Source code:** User interface, authentication, master control, environmental control, appliance control, security, communications and database components.
-**Requirements and design documents:** System requirements, context diagrams, architecture descriptions, interface specifications, and the Requirements Traceability Matrix. 
-**Test materials:** Unit, integration, system, security, and acceptance test plans, test data, and results.
-**Environment and dependency files:** Build instructions, software libraries, dependency versions, database configurations, and deployment settings. 
-**Project documentation:** The README, user instructions, risk register, schedules and release notes. 

### Quality Planning

The primary quality goals for the DigitalHome project will be reliability, security, usability, maintainability, and requirements compliance. The system should perform it required functions consistently, protect the user and household information, provide an easy to navigate interface, and allow component to be modified without creating defects elsewhere. 

Configuration items will be identified by descriptive file names, branches, commits, and version tags. Proposed changes will be documented, reviewed, tested on a separate branch, and merge only if approved. 

Progress towards these goals will be measured using the following metrics:

- Percentage of requirements connected to test cases in the Requirements Traceability Matrix.
- Percentage of unit, integration, system, security, and acceptance tests passed.
- Number and severity of unresolved defects.
- Percentage of defects discovered before release.
- Number of unauthorized access attempts are successfully blocked.
- Average time required to correct defects and security vulnerabilities.
- Number of customer reported defects after release.

Quality activities will begin during the planning and continue throughout development. Requirements and designs will be reviewed before coding begins. Devlopers will follow agreed coding standards, perform peer code reviews, and use static analysis and unit testing. Integration testing will be preformed after components are combined, followed by system, performance, security, and usability testing. The customer or representative will conduct acceptance testing to confirm that the system meets the user's needs. 

