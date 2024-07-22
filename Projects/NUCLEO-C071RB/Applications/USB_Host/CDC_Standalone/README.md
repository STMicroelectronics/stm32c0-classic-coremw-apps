## <b>CDC_Standalone Application Description</b>

This application is a part of the USB Host Library package using STM32Cube firmware. It describes how to use
USB host application based on the Communication Class (CDC) on the stm32c0xx devices.

This is a typical application on how to use the stm32c0xx USB DRD Host peripheral to operate with an USB
CDC device application based on the two CDC transfer directions with a dynamic serial configuration:

 - Transmission:
   by pressing the user button a message "USB_STM32_Host_CDC_ACM" will be sent from the host to a device and this message will be displayed in the hyper terminal of the device in hyperterminal
   The data to be transmitted is stored in the CDC_TX_Buffer and can be viewed via the Hyperterminal.

 - Reception:
   The data entered by the user using the Hyperterminal in ASCII format is transferred by the device board
   to the host board and displayed on the hyperterminal on the host side.
   The CDC_RX_Buffer is the buffer used for receiving data.

####  <b>Expected success behavior</b>

- When plugged to PC host, the NUCLEO-C071RB must be properly enumerated as an USB Serial device and an STlink Com port.
During the enumeration phase, the device must provide host with the requested descriptors (Device descriptor, configuration descriptor, string descriptors).

- Those descriptors are used by host driver to identify the device capabilities. Once NUCLEO-C071RB USB device successfully completed the enumeration phase,
Open two hyperterminals (USB com port and UART com port(USB STLink VCP)) to send/receive data to/from host from/to device.

#### <b>Error behaviors</b>

- Host PC shows that USB device does not operate as designed (CDC Device enumeration failed, PC and Device can not communicate over VCP ports).

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 “Universal Serial BUS” Specification and CDC class Specification.

#### <b>Known limitations</b>
None.

### <b>Keywords</b>

Connectivity, UART/USART, Type C, USB, CDC

### <b>Hardware and Software environment</b>

  - This application runs on STM32C07xx devices.
  - This application has been tested with STMicroelectronics NUCLEO-C071RB board revision MB2046-C071RB-B01
    and can be easily tailored to any other supported device and development board.

  - Connect ST-Link cable to the PC USB port to display data on the HyperTerminal.
  - NUCLEO-C071RB Set-up
      - Plug the USB CDC device into the NUCLEO-C071RB board through 'Type A  to Type C' cable to the connector:
        - CN13 : to use USB DRD IP in full speed (FS)

    A virtual COM port will then appear in the HyperTerminal:
     - Hyperterminal configuration
       - Data Length = 8 Bits
       - One Stop Bit
       - No parity
       - BaudRate = 115200 baud
       - Flow control: None

  - The USART2 interface available on PA2 and PA3 of the microcontroller are connected to ST-LINK MCU.
  - By default the USART2 communication between the target MCU and ST-LINK MCU is enabled. It's configuration is as following:
    - BaudRate = 115200 baud
    - Word Length = 8 Bits
    - Stop Bit = 1
    - Parity = None
    - Flow control = None

### <b>How to use it ?</b>

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application

<b>Note</b>

- The user has to check the list of the COM ports in Device Manager to find out the number of the COM ports that have been assigned (by OS) to the Stlink VCP.
- The application uses the HSE clock as USB source clock.
