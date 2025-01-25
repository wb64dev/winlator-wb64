EXAMPLE ONLY !!!





#import <winlator/tinyproot.h>
#import <wine.h>

int main() {
  // Set Wine prefix path
  NSString *winePrefix = @"~/.wine";

  // Create Wine prefix directory
  NSString *cmd = [NSString stringWithFormat:@"proot -p %@", winePrefix];
  system([cmd UTF8String]);

  // Set Wine architecture (32-bit or 64-bit)
  NSString *wineArch = @"win32"; // @"win64"

  // Set Wine version (optional)
  NSString *wineVersion = @"wine-9.2"; // adjust as needed

  // Run Winecfg to configure Wine
  cmd = [NSString stringWithFormat:@"WINEPREFIX=%@ winecfg", winePrefix];
  system([cmd UTF8String]);

  // Install required Wine dependencies (optional)
  // cmd = [NSString stringWithFormat:@"wineprefix -q winlator"]; //a
  // system([cmd UTF8String]);

  return 0;
}
