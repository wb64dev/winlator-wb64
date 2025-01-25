EXAMPLE ONLY !!!!







const childProcess = require('child_process');

// Set Wine prefix path
const winePrefix = '~/.wine';

// Create Wine prefix directory
childProcess.execSync(`proot -p ${winePrefix}`);

// Set Wine architecture (32-bit or 64-bit)
const wineArch = 'win32'; // 'win64'

// Set Wine version (optional)
const wineVersion = 'wine-9.2'; //

// Run Winecfg to configure Wine
childProcess.execSync(`WINEPREFIX=${winePrefix} winecfg`);

// Install required Wine dependencies (optional)
// childProcess.execSync('tinyproot -q winlator'); // 
