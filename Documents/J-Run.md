# Automate test runs on real hardware (J-Run)

SEGGER J-Run V8.18 Command Line Version
Compiled Mar  5 2025 14:47:49
(c) 2019-2024 SEGGER Microcontroller GmbH    www.segger.com

Syntax:
  JRun [option option ...] elf-file

  Option                     Default       Description
  --usb <SerialNo>           not set       Set serial number of J-Link to connect to via USB.
  --ip <str>                 not set       Set host name of J-Link to connect to via TCP/IP.
  --device <str>, --d <str>  STM32F407IE   Set device name to str.
  --if SWD | JTAG            SWD           Select SWD or JTAG as target interface.
  --speed <kHz>              4000          Set interface speed to n kHz.
  --rtt                      Auto          Explicitly enable RTT.
  --nortt                    Auto          Explicitly disable RTT.
  --semihost                 Auto          Explicitly enable semihosting.
  --nosemihost               Auto          Explicitly disable semihosting.
  --args <args>              not set       Arguments passed to target application via semihosting and RTT
  --wargs <str>              *ARGS*        Set RTT getargs wildcard to str.
  --wexit <str>              *STOP*        Set RTT exit wildcard to str.
  --wait                     Off           Wait for key press on application exit.
  --2, --stderr              Off           Also send target output to stderr.
  --s, --silent              Off           Work silently.
  --v, --verbose             Off           Increase verbosity.
  --dryrun                   Off           Dry run. Parse elf-file only.
  --jlinkscriptfile <str>    not set       Set path of J-Link script file to use to str.
                                           Further info : wiki.segger.com / J - Link_script_files
  --pc <mode> | 0xXXXXXXXX  vec            Initialize PC before start (according to <mode> or fixed address).
                                           <mode>: vec - Vector table, elf - ELF start address, off - do not init.
  --sp <mode> | 0xXXXXXXXX  vec            Initialize SP before start (according to <mode> or fixed address).
                                           <mode>: vec - Vector table, off - do not init.
   --log <file>             Off            Write output to logfile.
   --fileonly               Off            Write output _only_ to logfile.