#### Play your favorite games, Anywhere, Anytime.

<p align="center">
	<a href="https://github.com/winebox64/winlator/releases">
	<img src="logo.png" height="128" width="376" alt="Winlator Logo" />  
</p>


# Winlator 
<p align="left">
	<a href="https://github.com/winebox64/winlator/releases">
	<img src="https://img.shields.io/badge/Android%2010M+%20-winebox64?style=for-the-badge&logo=android&logoColor=green&logoSize=14&label=%20&labelColor=gray&color=66BA32" height="24" width="128" />  
</p>

Winlator is an Android application that lets you run Windows (x86_64) applications and games with Wine and Box86/Box64.

----
# Installation

1. Download and install the APK (Winlator_9.1.1.apk) from here [![Download Apk](https://img.shields.io/badge/%20DOWNLOAD%20-wb64?style=plastic&logo=&logoColor=green&logoSize=14&label=%20&labelColor=golden&color=66BA32)](https://github.com/winebox64/winlator/releases)


3. Launch the app and wait for the installation process to finish

----
# Useful Tips

- If you are experiencing performance issues, try changing the Box64 preset to __`Performance (Gaming Mode)`__ in Container Settings -> Advanced Tab.
- For applications that use .NET Framework, try installing __`Wine Mono`__ found in Start Menu -> System Tools.
__(Potencially improve game performance)__
- If some older games don't open, try adding the environment variable __`MESA_EXTENSION_MAX_YEAR=2003`__ in Container Settings -> Environment Variables. __(Fix game launch and crash issues)__
- Try running the games using the shortcut on the Winlator home screen, there you can define individual settings for each game.
- To display low resolution games correctly, try to enabling the __`Force Fullscreen`__ option in the shortcut settings -> Advanced Tab.
- To __improve stability in games that uses Unity Engine__, try changing the Box64 preset to __`Stability (Unity Games)`__ or in the shortcut settings -> Advanced Tab, add the exec argument __`-force-gfx-direct`__.

----

## Vortek Driver (Experimental)

List:

![Qualcomm](https://img.shields.io/badge/Snapdragon%208%20Elite-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%207s%20Gen%203-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%207%20Gen%203-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%207s%20Gen%202-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%206%20Gen%203-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%206%20Gen%201-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%20860-grey?style=plastic&logo=snapdragon&logoColor=red)

![Qualcomm](https://img.shields.io/badge/Snapdragon%20735-grey?style=plastic&logo=snapdragon&logoColor=red)

----

# Information

**This project has been in constant development since version 1.0, the current app** [![Download Apk](https://img.shields.io/badge/%20Source%20Code-wb64?style=plastic&logo=&logoColor=red&logoSize=14&label=%20&labelColor=golden&color=purple)](https://github.com/winebox64/winlator/tree/main/(1)_WINLATOR_v8.0%2B_SOURCE_CODE%3F) **is up to version 7.1, I do not update this repository frequently precisely to avoid unofficial releases before the official releases of Winlator.**


# Minimum System Requirements:
- Operating System (OS): Android 9.0 __or later__
- Processor: Qualcomm Snapdragon 460 __or higher__
- Graphics Processing Unit (GPU): Adreno 610 __or higher__ 
- Graphics API: __Vulkan 1.1 or higher__
- Internal Storage: At least __2GB of free space__
- Memory RAM: At least __1GB of free space, depending on the games__ (1GB or more recommended for game titles released before 2010 or DX9-based games)
- __Note: Some games may experience performance issues.__
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

<p align="center">
	<a href="https://github.com/winebox64/winlator/releases">
	<img src="logo.png" height="128" width="376" alt="Winlator Logo" />  
</p>
