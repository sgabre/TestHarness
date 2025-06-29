# Scope

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
