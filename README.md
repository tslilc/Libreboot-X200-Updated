# Libreboot-X200-Updated
Libreboot for the X200 with an updated version of coreboot and libreboot, fixing bugs and security issues.

## Information
The build is using coreboot stable version 4.12 and a recent version of GRUB 2.05 that has the patches for the "boothole" vulnerability. The resulting bios should be free of many minor bugs presnet in older versions of libreboot. I have personally Tested it on two x200s and am very pleased with the results. The user experience is EXACTlY the same as previous versions of libreboot: same grub configruation, same familiar background.

## IMPORTANT: To microcode or not?
In this repository, there are build wihtout any proprietary blobs, in the folder **roms/free** and there are builds that only have the microcode for the CPU as a proprietary blob in the **roms/microcode** foler. I would personally recommend users to first try and install on their machines the completely free rom, as it is in the original spirit of the libreboot project to have no blobs at all. However, I have experienced random crashes after long periods of use on both my test machines when the microcode isn't present. These crashes are also present on the builds from the official libreboot website. If this happens on your computer, and you want to make a small compromise when it comes to free software, the microcode buils will eliminate those crashes.

## Further improvements
By default, all the builds allocate slightly more vram to the integrated GPU: 352M. This is slightly more than the 256M on official librbeoot builds. I have personally found that this tweak makes 1080p video playback even smoother, and very feasible even within a browser. Also, I have disabled the beep noises when a charger is plugged in and when there is a low battery. I personally found those to be distracting, especially when the information can be found on the indicator leds. All of these settings can be modified without recompiling the rom using the `nvramtool` command.

# Installation
## Download
Select your rom within the **roms/free** directory for builds without microcode, and select your rom in the **roms/microcode** directory for builds with microcode. Make sure that the size of the rom corresponds to your chip size.
## Flashing
If libreboot is not currently installed on the target computer, the flashing proceedure is detailed very well on the libreboot website. Simply use the rom from this repository instead of the one from the website.<br><br>
If libreboot is currently installed on the system: boot the computer with the following linux kernel parameter: `iomem=relaxed`.<br>
Then, once inside of the operating system, make sure that a recent version of `flashrom` is installed, finally run the following command:<br>
`sudo flashrom -c "chip_name" -p internal:boardmismatch=force,laptop=force_I_want_a_brick -w name_of_selected_rom`
