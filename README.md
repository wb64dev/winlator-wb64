<p align="center">
	<a href="https://github.com/winebox64/winlator/releases">
	<img src="logo.png" height="128" width="376" alt="Winlator Logo" />  
</p>

 
# Winlator WB64

Winlator is an Android application that lets you run Windows (x86_64) applications and games with Wine and Box86/Box64.

✅ __[WINLATOR.ORG](https://winlator.org) is the original site.__ 

⚠️ __while [~WINLATOR.COM~](https://github.com/winebox64/winlator/releases), [~WINLATOR.APP~](https://github.com/winebox64/winlator/releases) and others are fake.__

⚠️ __Never share your E-mail address or any other personal information with them.__ 

----
# Installation

1. Download and install the APK (Winlator_latest.apk) from here [![winlator winebox64 apk](https://img.shields.io/badge/%20Download%20-wb64?style=for-the-badge-plastic&logo=Androids&logoColor=green&logoSize=14&label=%20&labelColor=golden&color=66BA32)](https://github.com/winebox64/winlator/releases)

2. Launch the app

3. Wait for the installation process to finish

----
# Useful Tips

- If you are experiencing performance issues, try changing the Box64 preset to `Performance (Gaming Mode)` in Container Settings -> Advanced Tab.
- For applications that use .NET Framework, try installing `Wine Mono` found in Start Menu -> System Tools.
Which may potentially improve game performance
- If some older games don't open, try adding the environment variable `MESA_EXTENSION_MAX_YEAR=2003` in Container Settings -> Environment Variables. Fix game launch and crash issues
- Try running the games using the shortcut on the Winlator home screen, there you can define individual settings for each game.
- To display low resolution games correctly, try to enabling the `Force Fullscreen` option in the shortcut settings -> Advanced Tab.
- To improve stability in games that uses Unity Engine, try changing the Box64 preset to `Stability (Unity Games)` or in the shortcut settings -> Advanced Tab, add the exec argument `-force-gfx-direct`.

----

## Vortek Driver (Experimental)

The Vortek driver is for processors that are incompatible with the Turnip (Adreno) driver.

[![Qualcomm](https://img.shields.io/badge/Snapdragon%208%20Elite-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%207s%20Gen%203-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%207%20Gen%203-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%207s%20Gen%202-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%206%20Gen%203-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%206%20Gen%201-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%20860-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

[![Qualcomm](https://img.shields.io/badge/Snapdragon%20735-grey?style=plastic&logo=snapdragon&logoColor=red)](https://github.com/winebox64/winlator)

----

# Information

This project has been in constant development since version 1.0, the current app [![source code](https://img.shields.io/badge/%20Source%20Code-wb64?style=for-the-badge-plastic&logo=&logoColor=red&logoSize=14&label=%20&labelColor=golden&color=red)](https://github.com/winebox64/winlator/tree/main/(1)_WINLATOR_v8.0%2B_SOURCE_CODE%3F) is up to version 7.1, I do not shared or update this repository frequently precisely to avoid unofficial releases before the official releases of Winlator.

----

# Minimum System Requirements (WineBox64):
- __OS (Operating System):__ Android 9.0 or later
- __Processor/CPU (Central Processing Unit):__ Qualcomm Snapdragon 460 or higher
- __GPU (Graphics Processing Unit):__ Adreno 610 or higher 
- __Graphics API:__ Vulkan 1.1 or higher
- __Internal Storage/ROM:__ At least 2GB of free space
- __RAM (Random Access Memory):__ At least 1GB of free RAM available, depending on the game requirments
- __Root Access:__ Not required
- __Gamepad:__ Optional (xinput/xbox recommended)


__Results can vary based on the device used, environmental conditions, and other factors, such as simultaneous processing, and different processor capabilities.__

 
----
# Credits and Third-party apps
- Ubuntu RootFs ([Focal Fossa](https://releases.ubuntu.com/focal))
- Wine ([winehq.org](https://www.winehq.org/))
- Box86/Box64 by [ptitseb](https://github.com/ptitSeb)
- PRoot ([proot-me.github.io](https://proot-me.github.io))
- Mesa (Turnip/Zink/VirGL) ([mesa3d.org](https://www.mesa3d.org))
- DXVK ([github.com/doitsujin/dxvk](https://github.com/doitsujin/dxvk))
- VKD3D ([gitlab.winehq.org/wine/vkd3d](https://gitlab.winehq.org/wine/vkd3d))
- D8VK ([github.com/AlpyneDreams/d8vk](https://github.com/AlpyneDreams/d8vk))
- CNC DDraw ([github.com/FunkyFr3sh/cnc-ddraw](https://github.com/FunkyFr3sh/cnc-ddraw))

Many thanks to [ptitSeb](https://github.com/ptitSeb) (Box86/Box64), [Danylo](https://blogs.igalia.com/dpiliaiev/tags/mesa/) (Turnip), [alexvorxx](https://github.com/alexvorxx) (Mods/Tips) and others.<br>
Thank you to all the people who believe in this project.

