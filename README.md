# GC9A01 Display Library

This repository contains a comprehensive library for interfacing with the GC9A01 circular LCD display. Designed for ease of use, this library facilitates the integration of the GC9A01 display into your projects, providing vibrant and dynamic graphical capabilities for various applications.

## Versions

- [**Version 1**](https://github.com/embeddedalpha/GC9A01/tree/main/V1)

- [**Version 2**](https://github.com/embeddedalpha/GC9A01/tree/main/V2)

## Features

- **High-Resolution Display**: Supports the full-color circular 240x240 pixel GC9A01 LCD.
- **SPI Communication**: Efficient communication with the display via the SPI interface.
- **Graphic Functions**: Draw text, shapes, and images with ease.
- **Display Rotation**: Support for different display orientations.
- **Configurable Settings**: Adjust brightness, color modes, and other display parameters.
- **Example Code**: Includes example sketches to help you get started quickly.

## Getting Started

### Prerequisites

- STM32F40x
- GC9A01 circular LCD display module
- SPI connection capability

### Installation

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/GC9A01-Display-Library.git
    ```
2. Include the library in your project by adding the source files to your development environment.
<!-- 
### Usage

1. Initialize the display and SPI communication:
    ```cpp
    #include <GC9A01.h>

    GC9A01 display;

    void setup() {
        display.begin();
        display.setRotation(0);
        display.fillScreen(0x0000); // Clear screen with black color
    }
    ```

2. Draw graphics on the display:
    ```cpp
    void loop() {
        display.setTextColor(0xFFFF); // White color
        display.setCursor(20, 40);
        display.print("Hello, GC9A01!");

        display.drawCircle(120, 120, 50, 0xF800); // Draw a red circle
        delay(1000);
    }
    ``` -->

### Example Projects

- **Digital Clock**: Create a real-time clock with a sleek circular display.
- **Sensor Dashboard**: Display sensor data dynamically on the GC9A01.
- **Game Interface**: Develop simple games with vibrant graphics.

## Contributing

Contributions are welcome! Please fork this repository, create a new branch for your feature or bugfix, and submit a pull request. Make sure to follow the coding standards and include relevant tests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

Special thanks to the community and contributors who have helped improve this library.

## Contact

For support or inquiries, please open an issue on this repository or contact [kunalsalvius@gmail.com](mailto:kunalsalvius@gmail.com).

---

Explore the documentation and source code to leverage the full potential of the GC9A01 circular LCD display in your projects. Happy coding!