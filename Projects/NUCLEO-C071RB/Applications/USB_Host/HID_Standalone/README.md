## HID_Standalone Application Description

This application is a part of the USB Host Library package using STM32Cube firmware. It describes how to use
USB host application based on the Human Interface Class (HID) on the STM32C0xx devices.

This is a typical application on how to use the STM32C0xx USB DRD Host peripheral to interact with an USB
HID Device such as a Mouse or a Keyboard.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config()
function to configure the system clock (SYSCLK).
The Full Speed (FS) USB module uses a 48-MHz clock, which is generated from HSE.

#### <b>Expected success behavior</b>

When a HID device is plugged to NUCLEO-C071RB board, a message will be displayed on the UART HyperTerminal showing
the Vendor ID and Product ID of the attached device.
After enumeration phase, a message will indicate that the device is ready for use.
The host must be able to properly decode HID reports sent by the corresponding device and display those information on the HyperTerminal.

The received HID reports are used by host to identify:
- in case of a mouse
   - (x,y) mouse position
   - Wheel position
   - Pressed mouse buttons

- in case of a keyboard
   - Pressed key

#### <b>Error behaviors</b>

  - Errors are detected (such as unsupported device, enumeration fail) and the corresponding message is displayed on the HyperTerminal.

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 "Universal Serial BUS" specification and HID class specification.

#### <b>Known limitations</b>

None

#### Notes
1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

2. The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

3. In case of using an AZERTY keyboard, user should add "AZERTY_KEYBOARD" define to ensure correct
      displaying taped characters.

It is possible to fine tune needed USB Host features by modifying defines values in USBH configuration
file "usbh_conf.h" available under the project includes directory, in a way to fit the application
requirements, such as:
- Level of debug: USBH_DEBUG_LEVEL
                  0: No debug messages
                  1: Only User messages are shown
                  2: User and Error messages are shown
                  3: All messages and internal debug messages are shown
   By default debug messages are displayed on the debugger IO terminal; to redirect the Library
   messages to uart terminal, stm32c0xx_hal_uart.c driver needs to be added to the application sources.
   Debug messages are displayed on the uart terminal using ST-Link.

For more details about the STM32Cube USB Host library, please refer to UM1720
"STM32Cube USB Host library".

### Keywords

Connectivity, USB_Host, USB, HID, Human Interface, Mouse, Keyboard

### Hardware and Software environment

  - This application runs on STM32C071xx devices.
  - This application has been tested with STMicroelectronics NUCLEO-C071RB board MB2046 Rev. B01 and can be easily tailored to any other supported device and development board.
  - NUCLEO-C071RB set-up:
    - Plug the USB HID device into the NUCLEO-C071RB board through 'USB micro A-Male to A-Female' cable to the connector:
      - CN13 : to use USB High Speed DRD IP.
    - Connect ST-Link cable to the PC USB port to display data on the HyperTerminal.

    A virtual COM port will then appear in the HyperTerminal:
     - Hyperterminal configuration
       - Data Length = 8 Bits
       - One Stop Bit
       - No parity
       - BaudRate = 115200 baud
       - Flow control: None

### How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain.
 - Rebuild all files and load your image into target memory.
 - Open the configured uart hyperterminal in order to display debug messages.
 - Run the application.
 - Open the configured uart hyperterminal in order to display debug messages.


#### Notes
The user has to check the list of the COM ports in Device Manager to find out the number of the COM ports that have been assigned (by OS) to the Stlink VCP.
The application uses the HSE clock as USB source clock.