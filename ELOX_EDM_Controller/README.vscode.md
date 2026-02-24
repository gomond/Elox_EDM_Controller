# VS Code setup for ELOX_EDM_Controller

## Prerequisites
- ARM GNU Toolchain (13.3.rel1 recommended). Set `ARM_GNU_TOOLCHAIN` to the bin directory that contains `arm-none-eabi-gcc.exe`.
- CMake 3.21+ and Ninja in `PATH`.
- OpenOCD with `OPENOCD_SCRIPTS` pointing to its `scripts` directory (e.g., `C:/ST/OpenOCD/scripts`).
- VS Code extensions: CMake Tools, Cortex-Debug, C/C++.

## Configure and build
```cmd
cmake --preset arm-gcc-debug
cmake --build build
```
Artifacts: `build/ELOX_EDM_Controller.elf`, `ELOX_EDM_Controller.bin`, and `ELOX_EDM_Controller.map`.

## Flash (OpenOCD)
```cmd
openocd -f %OPENOCD_SCRIPTS%/interface/stlink.cfg -f %OPENOCD_SCRIPTS%/target/stm32h7x.cfg -c "program build/ELOX_EDM_Controller.elf verify reset exit"
```
The VS Code task **Flash (OpenOCD)** does the same after a build.

## Debug
Use the **Debug (OpenOCD)** launch config (Cortex-Debug). It will build, start OpenOCD with ST-Link, and attach to `build/ELOX_EDM_Controller.elf`.

## Post-CubeMX clock sanity check
After re-generating code from STM32CubeMX, verify these values to keep the display stable:

- In `ELOX_EDM_Controller.ioc`:
	- `RCC.DIVN3=44`
	- `RCC.DIVR3=4`
	- `RCC.DIVR3Freq_Value=22000000`
	- `RCC.LTDCFreq_Value=22000000`
	- `RCC.FMCFreq_Value=200000000`
- In generated code:
	- `Core/Src/ltdc.c`: `PLL3M=4`, `PLL3N=44`, `PLL3R=4`
	- `Core/Src/fmc.c`: `FmcClockSelection = RCC_FMCCLKSOURCE_D1HCLK`

If CubeMX changes these, restore them and rebuild.
