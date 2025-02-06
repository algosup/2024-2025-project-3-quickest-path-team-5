# User Manual for 2024-2025 Project 3: Quickest Path

| Name           | date      | role |
| -------------- | --------- |------|
| Alexandre Bopp | 1/13/2025 | Technical Writer |
| Robin Goumy    |     -     | Program Manager |
| Jason Grosso   |     -     | Quality Assurance |

<img src="images/map2.jpg" alt="GPS Navigation" height="100%" width="100%" style="display: block; margin: auto; object-fit:cover;">

---

## 1. Introduction

### **Project Overview**

This user manual provides guidance on how to operate and interact with the **Quickest Path Calculator** software. It calculates the fastest road between two landmarks in the United States using a large dataset of connected nodes. Its primary applications include trip planning, route optimization, and travel time reporting.

### **Audience**

This user manual is designed for everyone, no technical requirements or computer-related background are expected. The software is built to be easy to use, with a simple interface that doesn't require technical knowledge. Once installed, the tool is ready for use and allows you to perform your tasks without needing to understand complex systems.

#### **Key Points for the Audience**:

| **Feature**             | **Description**                                                                          |
| ----------------------- | ---------------------------------------------------------------------------------------- |
| **User-friendly**       | The software is simple to use, with a clean interface and no technical jargon.           |
| **Easy setup**          | The software can be set up quickly with easy-to-follow instructions.                     |
| **Straightforward use** | After installation, using the software is intuitive and requires no technical knowledge. |

### **Scope**

The software provides a **REST API** that allows users to find travel times and calculate optimal routes between landmarks. By using a CSV dataset of road connections, the API processes user inputs and returns travel data in both XML and JSON formats. This enables easy integration with other systems and allows users to retrieve and interpret travel information in a way that suits their needs.

## 2. Prerequisites

- **Basic Requirements**:

  - Input: Keyboard and mouse/trackpad.
  - Device: PC or laptop.
  - Power: Electricity or battery.
  - Network: Internet for initial setup.

- **Minimum System Requirements**:

  | **Configuration**    | **Windows**                                                                           | **Mac**                                                                               |
  | -------------------- | ------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
  | **Operating System** | Windows 10 (64-bit) or later                                                          | macOS Mojave (10.14) or later                                                         |
  | **Processor**        | Intel Core i3 (8th Gen) or AMD Ryzen 3                                                | Apple M1 or Intel Core i5                                                             |
  | **RAM**              | 4 GB minimum, 8 GB recommended for smooth performance                                 | 4 GB minimum, 8 GB recommended for smooth performance                                 |
  | **Storage**          | 100 MB of free space for software and dataset; SSD recommended for faster performance | 100 MB of free space for software and dataset; SSD recommended for faster performance |
  | **Graphics**         | Integrated graphics card (no dedicated GPU required)                                  | Integrated graphics (Apple M1 has integrated GPU)                                     |
  | **Network**          | Stable internet connection for API calls and software setup                           | Stable internet connection for API calls and software setup                           |
  | **Additional Notes** | Software installation and dataset management may require admin privileges             | Software installation and dataset management may require admin privileges             |

- **How to Check Your PC Components**

  - **Windows**:

    1. Press `Windows + R` to open the Run dialog.
    2. Type `dxdiag` and press Enter.
    3. In the DirectX Diagnostic Tool, you can find your **Processor**, **Memory (RAM)**, and **Graphics** listed.

  - **Mac**:

    1. Click the Apple logo in the top-left corner.
    2. Select **About This Mac**.
    3. The window that appears will show details about your **Processor**, **Memory (RAM)**, **Storage**, and **Graphics**.

  These steps will help you confirm your system's specifications for ensuring compatibility with the software.

- **Software Requirements**:

  - **C++ Compiler**:  
    You will need a program called GCC to run the software. This is a tool that helps your computer understand and execute the code.

    - To install it, just click [here to download GCC](https://gcc.gnu.org/) and follow the easy steps on the website.

  - **HTTP Server**:  
    An HTTP server is needed to make the software work on your computer. If you don't already have one, we suggest using **Apache** or **Nginx**.

    - Don’t worry, these servers are widely used and have easy-to-follow [guides](https://www.ionos.fr/digitalguide/serveur/configuration/installer-un-serveur-apache-nos-conseils/). 

- **Data File**:

  - **USA-roads.csv**:  
    This is a file that contains information about roads and travel times between landmarks. It’s very important for the software to work correctly.
    - You can download it [here](#). Once you have it, keep it in the same folder as the software.

## 3. Installation Guide

### 1. **Download the Software**

To start, you need to get the software on your computer. There are two options for this:

#### Case 1: **Using Git** (recommended if you have Git installed):

1. Open the **Command Prompt** (Windows) or **Terminal** (Mac).
2. Type the following command to download the software:

   ```bash
   git clone https://github.com/algosup/2024-2025-project-3-quickest-path-team-5
   ```

   Tip: If you don’t have Git installed, please visit this [link](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) to install Git.

#### Case 2: **Manual** Download:

Go to the [GitHub repository](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5) and click Download ZIP. Extract the ZIP file to a location on your computer.
Note: Make sure the folder you download is <strong>easy</strong> to access.

### 2. Setting up the Environment

To run the software, you need a C++ compiler installed on your system. Follow these steps:

| **Operating System** | **Instructions**                                                                                                                                         |
|-----------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Windows (Install MinGW)** | MinGW is a lightweight tool to compile C++ code. <br> 1. [Download MinGW here](https://ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html). |
| **Mac (Install GCC)**       | Use Homebrew, a package manager for Mac, to install the compiler. <br> 1. Open Terminal. <br> 2. Run this command: `brew install gcc` <br> *(If Homebrew isn’t installed, follow the instructions here: [Homebrew](https://brew.sh/))* |

---

- Install CMake (Required)

  CMake is a tool that simplifies the compilation of complex projects.

  - Visit the official website: [CMake Download](https://cmake.org/download).  
  - Download and install the version suitable for your system (Windows, Mac, Linux).

### 3. Compile the Software

- **Before You Start: Open Your Terminal**

  Open your terminal application:

  - **Windows:** Search for "Command Prompt" or "PowerShell" in the Start Menu.
  - **Mac/Linux:** Open the Terminal app from the Applications folder or search for it.

- **Step 1: Navigate to the Project Folder**
  
    Use the `cd` command to go to the folder where you downloaded the software.
  
    ```bash
    cd /path/to/your/folder/2024-2025-project-3-quickest-path-team-5
    ```

    ![Navigate to Project Folder](images/path-folder.png)

- **Step 2: Create a Build Directory**
  
    Create a separate folder for the build process and move into it.

    ```bash
    mkdir build
    cd build
    ```

    Result in the terminal:

    ![Create Build Directory](images/mkdir.png)

- **Step 3: Generate Makefiles**
  
    Use CMake to generate the necessary build files.

    ```bash
    cmake ..
    ```

- **Step 4: Build the Software**

    Compile the software using the `make` command.

    ```bash
    make
    ```

- **Step 5: Run the software**

     ADD description

    ```bash
    // add command line
    ```

- **Tip:**
    If you prefer not to use CMake, ensure the project includes a Makefile or other build instructions.

## 4. Tests

### Overview

The test suite verifies the correctness, performance, and compliance of the software. It ensures the application meets all defined requirements, including validating the dataset and adhering to the 10% approximation rule.

### Running Tests

Follow these steps to run the test suite and verify the dataset:

- Step 1: Navigate to the Test Directory
    Move into the `bin` directory where the test executable is located.

    ```bash
    cd ../bin
    ```

- Step 2: Run the Test Suite

    Execute the test program to validate the software.

    ```bash
    ./test
    ```

- Step 3: Verify the Dataset

    Use the dataset verification tool to ensure proper setup.

    ```bash
    ./dgv
    ```

### Results

#### ./Test Result

The `./test` program outputs the following:

- Validation of travel times and paths.
- Checks for performance requirements.

#### Dataset Verification Result

The `./dgv` program confirms:

- The dataset's correctness.
- Readiness for the application.

## 5. Usage Instructions

### Finding the Quickest Path

- **How It Works**  
   The software calculates the shortest route between two landmarks using the provided road network data.

- **Understanding the Output**

  - Travel Time: Displays the estimated time to traverse the path.
  - Path: Lists the sequence of landmarks to follow for the route.

- **The interface is easy to use, and takes the form of a single page containing all the information.**

  1. Enter your two landmarks, your source and your destination

      ![alt text](images/source_destination.png)

  2. Choose your download format

      ![alt text](images/response_format.png)

  3. Submit your request

      ![alt text](images/submit.png)

  4. Waiting to access the travel times and the steps

      ![alt text](images/travel_time_and_steps.png)

- **Example of a response**:

    // Add screenshots.

## 6. Troubleshooting

### Common Issues

| **Issue**                          | **Problem**                                                                 | **Solution**                                                                                           |
|------------------------------------|-----------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------|
| **Missing or Incorrect `USA-roads.csv` File** | The file is missing or doesn't match the required format.                  | 1. Ensure the file is in the same folder as the software. <br> 2. The file should look like: `Landmark_A_ID, Landmark_B_ID, Time`. <br>  |
| **API Not Responding**             | The server is not running.                                                 | 1. Check if the server is running by typing: <br> `curl http://localhost:<PORT>/api/path?source_id=1&destination_id=5` <br> 2. Ensure the server is on port 8080. <br> 3. Ensure no other program is using the same port. |
| **Unexpected Results**             | The API is giving wrong results.                                           | 1. Double-check the IDs you're using. <br> 2. Ensure the dataset is correct.                          |
| **400 (Bad Request)**              | Missing or incorrect data in your request.                                 | 1. Ensure you include both `source_id` and `destination_id`. <br> 2. Example: <br> `http://localhost:<PORT>/api/path?source_id=1&destination_id=5` |
| **404 (Not Found)**                | The requested resource doesn't exist.                                      | 1. Verify the URL and endpoint are correct.                                                            |
| **500 (Internal Server Error)**   | Something went wrong on the server.                                        | 1. Check the server logs for specific errors. <br> 2. Ensure the `USA-roads.csv` file is correct.    |
| **Server Fails to Start**          | The server won't run.                                                      | 1. Check that you have installed all required dependencies. <br> 2. Look at error messages for missing files or libraries. |
| **Slow API Response**              | The response takes too long.                                               | 1. Ensure your dataset doesn't have unnecessary data. <br> 2. Try limiting how many requests are being made at once. |
| **Permission Denied Errors**       | You can't access files or run commands.                                    | 1. Run the software as an administrator (use `sudo` on Linux). <br> 2. Ensure the `USA-roads.csv` file can be read. |

## 7. FAQs

### **Common Questions**

- **Q: How does the software handle invalid inputs?**  
  - **A:** Returns an error message indicating the issue.

- **Q: Can additional data be added to **USA-roads.csv**?**  
  - **A:** Yes, but it must follow the required format.

- **Q: What format should the input data files follow?**  
  - **A:** All input files must be CSV files with specific columns: `StartNode`, `EndNode`, and `Distance`. Refer to the provided `USA-roads.csv` for an example.

- **Q: What happens if the data file is missing or corrupted?**  
  - **A:** The software will notify the user and exit gracefully with an error message.

- **Q: Can I run the program on systems other than Linux?**  
  - **A:** Yes, the program is compatible with Windows, macOS, and Linux, but you need to ensure you have the necessary build tools installed (e.g., CMake and a compatible compiler).

- **Q: How are performance metrics calculated?**  
  - **A:** The program calculates the total travel time, shortest path, and compliance with the 10% approximation rule during the testing phase.

- **Q: Is it possible to visualize the generated paths?**  
  - **A:** Currently, the program does not include visualization, but you can export the results for use in third-party tools.

- **Q: Can I add more test cases?**  
  - **A:** Yes, you can modify the test suite by editing the corresponding test files in the source code.

- **Q: Does the software support weighted graphs with different cost metrics?**  
  - **A:** Yes, you can modify the input data to include weights (e.g., distance, time, cost) as long as it aligns with the required format.

- **Q: How do I reset or rebuild the project?**  
  - **A:** Delete the `build` directory and rerun the following commands:
  
    ```bash
    cmake -S . -B build
    cd build
    make
    ```

- **Q: Where can I report bugs or request features?**  
  - **A:** Please use the project's GitHub repository issue tracker or contact the development team directly.

## 8. Legal Mentions

### 1. Copyright  

  All content within this document, including text, images, and code snippets, is the property of Team 5 and is protected under applicable copyright laws. Unauthorized reproduction, distribution, or modification of this document is strictly prohibited.

  © 2025 Team 5. All rights reserved.

### 2. License & Usage  

This document is provided for informational purposes only. It may not be copied, shared, or used for commercial purposes without prior written consent from Team 5.

  For more information on copyright and usage, you may refer to the following legal articles:

- **Berne Convention for the Protection of Literary and Artistic Works** 
- **EU Directive 2001/29/EC**
  
### 3. Liability Disclaimer  

  Team 5 provides this software free of charge, without collecting personal data. The software is offered "as is," with no express or implied warranties. While we strive for accuracy and reliability, we do not guarantee uninterrupted or error-free operation. Users are responsible for their own use of the software. Team 5 shall not be liable for any indirect or incidental issues arising from its use, except in cases of gross negligence or willful misconduct.

### 4. Modifications & Updates  

  Team 5 reserves the right to modify, update or delete any part of its services, whether documents or software.

### 5. Contact Information  

  | **Category**        | **Details**                                                 |
  |---------------------|-------------------------------------------------------------|
  | **Email**          | team_5@algosup.com                                   |
  | **Company Name**   | Team 5                                                       |
  | **Response Time**  | We aim to respond within 24-48 hours.                        |
  | **Work Time**      | Monday to Friday, 9 AM - 5 PM (CET - Central European Time). |
  | **Support Topics** | Bugs, Feature Requests, General Inquiries, Setup Assistance. |

## 9. Appendix

### Glossary:

- **Landmark**: A point of interest in the graph (e.g., city, intersection). It’s like a location or stop along your journey.

- **CSV (Comma-Separated Values)**: A simple text file format where data is stored in rows and columns. Each value is separated by a comma. It’s similar to a spreadsheet, but without the rows and columns you see in Excel.

- **API (Application Programming Interface)**: A set of rules that lets different software applications talk to each other. It’s like a menu at a restaurant where the software makes a request and gets a response back.

- **Build Directory**: A folder where temporary files are stored during the process of making a program. Think of it as a workspace where all the pieces of your program come together.

- **Makefiles**: A set of instructions that tell the computer how to compile (build) the software. They’re like a recipe with step-by-step instructions on how to make the program.

- **HTTP Server**: A program that allows other software, like a web browser, to interact with your system. It’s like a waiter that brings requests from the internet and delivers responses back.

- **Git**: A tool that helps manage and track changes in software. It’s like a time machine for your code, allowing you to go back to earlier versions if something goes wrong.

- **Dataset**: A collection of information or data that the software uses to calculate routes or times. It’s like a map with all the road information you need for your trip.

- **Compile**: The process of turning the code you’ve written into a program that can be run on your computer. It’s like putting ingredients together to make a meal.

- **Terminal**: A program where you type commands to interact with your computer. It’s like talking directly to your computer using text.

- **Executable File**: A type of file that contains a program that can be run on your computer. It’s like a machine that performs a task when you click it.

- **Environment Variables**: Special settings that help your system know where to find certain tools or files. They’re like a map that tells your computer where to look for things it needs.
