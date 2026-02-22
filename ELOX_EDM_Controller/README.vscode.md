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
