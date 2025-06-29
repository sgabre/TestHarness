# Scope (Draft)

The Raspberry Pi will serve as a **deported (remote) computer** responsible for managing the entire test and deployment process of the embedded software. Its role will span from pulling the latest code from the repository to producing and releasing the final software image.

## The Raspberry Pi shall be able to:

1. **Access the Code Repository**  
   - Clone, fetch, and pull the latest commits from a Git repository (e.g., GitHub, GitLab)  
   - Manage multiple branches and tags

2. **Build the Software**  
   - Configure and run CMake-based builds  
   - Cross-compile embedded firmware (e.g., using `arm-none-eabi-gcc`)  
   - Support both Debug and Release configurations

3. **Run Automated Tests**  
   - Execute unit tests using frameworks such as Unity and CMock  
   - Run integration and system tests if applicable  
   - Validate test results and generate reports

4. **Perform Static Analysis**  
   - Run tools like `cppcheck`, `clang-tidy`, or integrate with SonarQube  
   - Produce and store static analysis reports

5. **Manage Build Artifacts**  
   - Archive binaries, map files, logs, and test results  
   - Generate `.hex` or `.bin` files for firmware deployment

6. **Flash Devices**  
   - Flash the generated firmware to connected target boards (e.g., via ST-Link, J-Link)  
   - Verify successful flashing

7. **Host a Local Dashboard (optional)**  
   - Serve a web interface or dashboard summarizing the build and test status

8. **Trigger Processes Automatically**  
   - Integrate into a CI/CD pipeline (e.g., through Git hooks or scheduled jobs)  
   - React to new commits or tags in the repository

9. **Ensure Environment Consistency**  
   - Use Docker containers or Python virtual environments to ensure toolchain and dependency isolation  
   - Automatically set up build environments for repeatability

10. **Manage Logs and Reports**  
    - Organize logs, test reports, coverage data, and code metrics for review  
    - Optionally push reports to a central server or cloud storage
   
# System Software Environment

The Raspberry Pi will be configured with a lightweight, maintainable, and fully automated software environment to support embedded software development, testing, and deployment.

## Operating System

- **OS:** Raspberry Pi OS (Lite) or Ubuntu Server for ARM
- **Architecture:** 64-bit preferred for better performance and tool compatibility
- **Remote Access:** Enabled via SSH and/or VNC

## Core Software Stack

| Category            | Tool/Technology                 | Description |
|---------------------|----------------------------------|-------------|
| **Version Control** | `git`                            | For cloning, pulling, and managing code from repositories |
| **Build System**    | `CMake`, `Make`                  | Configure and automate the build process |
| **Toolchain**       | `arm-none-eabi-gcc`              | Cross-compiler for ARM Cortex-M microcontrollers |
| **Scripting**       | `bash`, `python3`, `pip`         | Automation of tasks and workflows |
| **Containerization**| `Docker` (optional)              | Isolate and reproduce build/test environments |
| **CI Tools**        | `cron`, `Git hooks`, `Jenkins` (optional) | Automate build and test pipelines |
| **Testing**         | `Unity`, `CMock`, `Ceedling`     | Embedded unit testing framework |
| **Static Analysis** | `cppcheck`, `clang-tidy`         | Identify bugs, style issues, and inefficiencies |
| **Flashing Tools**  | `st-flash`, `JLinkExe`, `openocd`| Flash firmware to devices |
| **Reporting**       | `gcov`, `lcov`, `genhtml`        | Code coverage reports |
| **Documentation**   | `Doxygen`                        | Generate code documentation |
| **Web/Dashboard**   | `nginx`, `lighttpd`, or others   | Serve status pages and reports locally |
| **Database (optional)** | `sqlite3`, or CSV            | Store metrics, logs, and test results |

## Folder Structure

```
/home/pi/TestHarness/
├── repo/ # Cloned embedded project repositories
├── build/ # Output of build system
├── logs/ # Test and build logs
├── reports/ # Coverage, static analysis, etc.
├── scripts/ # Bash/Python scripts to automate tasks
├── tools/ # Custom tools, compilers, debug tools
└── dashboard/ # Web UI or dashboards (optional)
```

## Network Requirements

- Access to Git repositories (e.g., GitHub, GitLab)
- SSH/SCP access to deploy firmware or fetch logs from other devices
- Optional internet access for package and toolchain updates

## Security Considerations

- Disable password-based SSH login (use keys)
- Limit sudo access
- Use firewalls and restrict external access as needed

# Installation/setup 

The following Bash scripts automate the setup of the Raspberry Pi to serve as a remote test and deployment manager for embedded software.

## Folder Structure

```
TestHarness/
├── setup/
│   ├── setup-system.sh
│   ├── setup-python.sh
│   ├── setup-docker.sh
│   ├── setup-ci.sh
│   └── install-all.sh
```

---

## ✅ setup/setup-system.sh

```bash
#!/bin/bash
set -e

echo "[INFO] Updating system packages..."
sudo apt update && sudo apt upgrade -y

# Core build utilities
sudo apt install -y git
sudo apt install -y cmake
sudo apt install -y make
sudo apt install -y ninja-build
sudo apt install -y build-essential
sudo apt install -y gcc
sudo apt install -y g++

# Debugging tools
sudo apt install -y gdb

# ARM embedded toolchain
sudo apt install -y gcc-arm-none-eabi
sudo apt install -y gdb-multiarch

# USB development support
sudo apt install -y libusb-1.0-0-dev
sudo apt install -y libudev-dev

# General dev utilities
sudo apt install -y pkg-config
sudo apt install -y curl
sudo apt install -y wget
sudo apt install -y unzip

# Extras for system management and scripts
sudo apt install -y vim
sudo apt install -y htop
sudo apt install -y screen
sudo apt install -y jq

echo "[INFO] System package setup complete."
```

## ✅ setup/setup-python.sh

```bash
#!/bin/bash
set -e

echo "[INFO] Installing Python and pip..."
sudo apt install -y python3 python3-pip

echo "[INFO] Installing Python packages..."
pip3 install --user \
    requests \
    flask \
    psutil \
    pandas \
    matplotlib \
    rich

echo "[INFO] Python environment setup complete."
```

## ✅ setup/setup-docker.sh (optional)

```bash
#!/bin/bash
set -e

echo "[INFO] Installing Docker..."
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

echo "[INFO] Adding current user to docker group..."
sudo usermod -aG docker "$USER"

echo "[INFO] Docker installed. Log out and back in to apply group changes."
```

## ✅ setup/setup-ci.sh

```bash
#!/bin/bash
set -e

echo "[INFO] Installing cron..."
sudo apt install -y cron

echo "[INFO] Setting up daily cron job for builds..."
CRON_JOB="@daily /home/pi/TestHarness/scripts/run-daily-build.sh >> /home/pi/TestHarness/logs/cron.log 2>&1"
( crontab -l 2>/dev/null; echo "$CRON_JOB" ) | crontab -

echo "[INFO] Cron job installed."
```

## ✅ setup/install-all.sh

```bash
#!/bin/bash
set -e

echo "[INFO] Running full setup for TestHarness..."
./setup/setup-system.sh
./setup/setup-python.sh
./setup/setup-docker.sh
./setup/setup-ci.sh
echo "[INFO] Full environment setup complete."

```
