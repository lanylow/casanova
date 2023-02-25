# Casanova
Casanova is a simple internal mod menu for Geometry Dash. It has a Click GUI which contains all settings, it can be toggled by pressing TAB. The code is quite old, so don't expect high quality, but I'm sure it can help some people with their own mods.

## How to use
After building the project, you'll have a .dll file that you have to inject into `GeometryDash.exe`. After that, a debug console will pop-up, unless you've undefined the `_CONSOLE` macro. The main initialization routine starts when opening the in-game main menu for the first time, if you injected after that, just go into any other menu and then go back to the main menu.

## Compiling
To compile this project you can use Visual Studio, but first you need to install a few dependencies from [vcpkg](https://vcpkg.io/en/index.html):
- `fmt:x86-windows-static-md`
- `minhook:x86-windows-static-md`
- `discord-rpc:x86-windows-static-md`

## Pictures
![casanova](https://user-images.githubusercontent.com/31806776/221366249-10037123-9384-4a0c-8abb-6bd1b672196c.png)

## Credits
- [Absolute](https://github.com/absoIute) for MegaHack V6 and V7.
- [qimiko](https://github.com/qimiko) for [gdrpc](https://github.com/qimiko/gdrpc).
