#include <iostream>
#include <string>

enum class UserRole {
General, Master, Technician
};

std::string roleName(UserRole role) {
  switch (role){
case UserRole::General: return "General";
case UserRole::Master: return "Master";
case UserRole::Technician: return "Technician";
  }
return "Unknown";
  }

class User {
public: 
User(std::string id, std::string name, UserRole role)
: id_(id), name_(name), role_(role){}

std::string name() const { return name_; }
UserRole role() const { return role_; }

bool canControlDevices() const {
  return role_ == UserRole::Master ||role_ == UserRole::Technician;
}

private:
std::string id_;
std::string name_;
UserRole role_;
};

class Device {
public: 
Device(std::string id, std::string name, bool connected)
: id_(id), name_(name), connected_(connected) {}

std::string name() const { return name_;}
bool isConnected() const { return connected_;}

bool setTemperature(double target) {
  if (!connected_ || target < 60.0 || target > 80.0){
    return false;
  }
  targetTemperature_ = target;
  return true;
}

bool setHumidity(double humidity) {
    if (!connected_ || humidity < 30.0 || humidity > 60.0) {
        return false;
    }
    humidity_ = humidity;
    return true;
}

private:
std::string id_;
std::string name_;
bool connected_;
double targetTemperature_ = 72.0;
double humidity_ = 45.0;
};

class Schedule {
public:
    Schedule(std::string name, double targetTemperature)
        : name_(name), targetTemperature_(targetTemperature), enabled_(true) {}

    void enable() { enabled_ = true; }
    void disable() { enabled_ = false; }
    bool isEnabled() const { return enabled_; }

    std::string name() const { return name_; }
    double targetTemperature() const { return targetTemperature_; }

    bool setTargetTemperature(double target) {
    if (target < 60.0 || target > 80.0) {
        return false;
    }

    targetTemperature_ = target;
    return true;
}

private:
    std::string name_;
    double targetTemperature_;
    bool enabled_;
};

int main() {
  User user("user-001", "Alex", UserRole::Technician);
  User user1("user-002", "Joey", UserRole::General);
  std::cout << " Joey can control devices: " << (user1.canControlDevices() ? "yes" : "no") << '\n';
Device thermostat("device-001", "Living Room Thermostat", true);

std::cout << "60 degrees accepted: "
          << (thermostat.setTemperature(60.0) ? "yes" : "no") << '\n';
std::cout << "80 degrees accepted: "
          << (thermostat.setTemperature(80.0) ? "yes" : "no") << '\n';
std::cout << "59 degrees rejected: "
          << (!thermostat.setTemperature(59.0) ? "yes" : "no") << '\n';
std::cout << "81 degrees rejected: "
          << (!thermostat.setTemperature(81.0) ? "yes" : "no") << '\n';

std::cout << "30% humidity accepted: "
          << (thermostat.setHumidity(30.0) ? "yes" : "no") << '\n';
std::cout << "60% humidity accepted: "
          << (thermostat.setHumidity(60.0) ? "yes" : "no") << '\n';
std::cout << "29% humidity rejected: "
          << (!thermostat.setHumidity(29.0) ? "yes" : "no") << '\n';
std::cout << "61% humidity rejected: "
          << (!thermostat.setHumidity(61.0) ? "yes" : "no") << '\n';

Device offlineThermostat("device-002", "Offline Thermostat", false);
std::cout << "Disconnected temperature rejected: "
          << (!offlineThermostat.setTemperature(70.0) ? "yes" : "no") << '\n';
std::cout << "Disconnected humidity rejected: "
          << (!offlineThermostat.setHumidity(45.0) ? "yes" : "no") << '\n';


Schedule eveningSchedule("Evening", 70.0);
std::cout << "Schedule: " << eveningSchedule.name()
          << " - " << eveningSchedule.targetTemperature()
          << " degrees, "
          << (eveningSchedule.isEnabled() ? "enabled" : "disabled")
          << '\n';

  eveningSchedule.disable();
std::cout << "After disabling: "
          << (eveningSchedule.isEnabled() ? "enabled" : "disabled")
          << '\n';

eveningSchedule.enable();
std::cout << "After enabling: "
          << (eveningSchedule.isEnabled() ? "enabled" : "disabled")
          << '\n';
    
    if (eveningSchedule.setTargetTemperature(68.0)) {
    std::cout << "Schedule temperature updated to "
              << eveningSchedule.targetTemperature()
              << " degrees\n";
} else {
    std::cout << "Schedule temperature update failed\n";
}

if (!eveningSchedule.setTargetTemperature(85.0)) {
    std::cout << "Out-of-range schedule temperature rejected\n";
}

std::cout << "Current schedule temperature: "
          << eveningSchedule.targetTemperature()
          << " degrees\n";

if (user.canControlDevices()) {
    if (thermostat.setTemperature(eveningSchedule.targetTemperature())) {
        std::cout << "Temperature change succeeded\n";
    } else {
        std::cout << "Temperature change failed\n";
    }

    if (thermostat.setHumidity(50.0)) {
    std::cout << "Humidity change succeeded\n";
} else {
    std::cout << "Humidity change failed\n";
}

} else {
    std::cout << "Permission denied\n";
}

std::cout << "Digital Home starter program\n";
  std::cout << "User: " << user.name() << " (" << roleName(user.role()) << ")\n";
  std::cout << "Device: " << thermostat.name() << " - " << (thermostat.isConnected() ? "connected" : "disconnected") << '\n';

std::cout << "Joey can control devices: "
          << (user1.canControlDevices() ? "yes" : "no") << '\n';

return 0;
}
