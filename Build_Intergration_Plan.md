# DigitalHome Build and Integration Plan

## Increment Definition

The DH will be separated into two increments so it can be developed and tested in smaller and more manageable sections. 

### Increment 1: Device Control
The first increment will include the controller, device interfaces, lighting, thermostat, humidity, and appliance control components. The class specifications, attributes, methods, preconditions, postconditions, will be defined before the components are implemented

The controller and interfaces need to be completed first because the individual devices rely on them to receive commands and report their status. 

Increment 1 should take approximately three to four days to implement and another one or two days for unit and integration testing. 

Unit testing will verify the device control functions, including temperature and humidity limits and on off functions for lights and appliances. 

Integration testing will confirm that each component follows the commands sent through the interface and displays the correct status information. 

### Increment 2: User, Scheduling, and Security Features
The second increment will include user accounts, the MonthPlan scheduling component, security monitoring, alarms, and security based lighting controls. 

The MonthPlan component depends on the lighting and device interfaces created during the first increment so it can send scheduled commands to the correct devices.

The user account component must be completed before testing so that authorized users will be allowed access and unauthorized users are denied access.

Increment 2 should take approximately three to four days to implement and two days for unit and integration testing.

Unit testing will verify user permissions, MonthPlan schedules, and alarm functions using valid and invalid inputs. 

Integration testing will verify that MonthPlan sends the scheduled command to the correct device and that device carries out the action at the specific time. 

## GitHub Collaboration Strategy

Since I am the only group member, I will keep stable code in the main branch and devlop each increment on its own separate branch. This will prevent unfinished changes from affecting the stable version.

Before merging a pull request, I will verify that all unit and integration tests pass and review the changes against the project requirements.

If a merge conflict occurs, I will compare the conflicting change codes, keep the correct code, remove the conflicting code, and rerun tests before finishing the merge. 

