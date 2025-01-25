#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
  // Set Wine prefix path
  std::string winePrefix = "~/.wine";

  // Create Wine prefix directory
  std::string cmd = "proot -p " + winePrefix;
  system(cmd.c_str());

  // Set Wine architecture (32-bit or 64-bit)
  std::string wineArch = "win32"; // "win64"

  // Set Wine version (optional)
  std::string wineVersion = "wine-9.2"; // adjust as needed

  // Run Winecfg to configure Wine
  cmd = "WINEPREFIX=" + winePrefix + " winecfg";
  system(cmd.c_str());

  // Install required Wine dependencies (optional)
  // cmd = "winetricks -q dotnet40"; // example
  // system(cmd.c_str());

  return 0;
}
