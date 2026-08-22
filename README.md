# Group One — Task 8.2: Bare-Metal STM32 BMS

MIA Robotics Electrical Team Training 26/27 — Group Task 8.2: Bare-metal ADC-based Battery Management System on the STM32F401CC, using direct register manipulation (no HAL).

## Project Structure

```
├── src/    # Driver source files (GPIO driver, ADC driver, bit-math macros)
├── inc/    # Header files
├── docs/   # ADC register-level research documentation (PDF/MD)
└── sim/    # Proteus simulation project + files
```

- **`/src`** — All `.c` implementation files: GPIO driver, ADC driver, RCC/bit-math macros.
- **`/inc`** — All `.h` header files matching the source files above.
- **`/docs`** — Written documentation of the ADC peripheral configuration and register-level explanation (Requirement 4).
- **`/sim`** — Proteus project files (`.pdsprj` etc.) and simulation screenshots.

## Branch Workflow

- `main` — stable/final branch only.
- `dev` — active development branch. All work branches off `dev`.

To start work on a part:
```bash
git checkout dev
git pull
git checkout -b feature/your-part-name
```

When ready, push your branch and open a PR into `dev`.

## Toolchain

- STM32F401CC, bare-metal (RCC/GPIO/ADC registers, no HAL)
- ARM GNU Toolchain (`arm-none-eabi-gcc`)
- Build via `make` (see `/scripts` in the reference setup repo for build target details)

## Team

- Member 1 — Environment & Build Setup
- Member 2 — Bit-Math & Register Macros
- Member 3 — GPIO Driver
- Member 4 — ADC Research & Documentation
- Member 5 — ADC Driver
- Member 6 — Proteus Integration & Simulation
