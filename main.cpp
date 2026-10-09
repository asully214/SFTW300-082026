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
return "Unknown"
  }

class User {
public: 
User(std::string id, std::string name, UserRole role)
: id_(id), name_(name), role_(role){}

std::string name() const { return name; }
UserRole() const { return role_; }

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

private:
std::string id_;
std::string name_;
bool connected_;
};

int main() {
  User user("user-001", "Alex", UserRole::General);
Device thermostat("device-001", "Living Room Thermostat", true);

std::cout << "Digital Home starter program/n;
  std::cout << "User: " << user.name() << " (" << roleName(user.role()) << ")/n";
  std::cout << "Device: " << thermostat.name() << " - " << (thermostat.isConnected() ? "connected" : "disconnected") << /n;

return 0;
}
