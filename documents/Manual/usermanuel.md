# User Manual for 2024-2025 Project 3: Call for Tender

| Name | date |
|------|------|
|Alexandre Bopp| 1/13/2025 |

<img src="intro.jpg" alt="GPS Navigation" height="100%" width="100%" style="display: block; margin: auto; object-fit:cover;">

---

## 1. Introduction

### **Project Overview**  
This user manual provides guidance on how to operate and interact with the **Quickest Path Calculator** software. It calculates the fastest road between two landmarks in the United States using a large dataset of connected nodes. Its primary applications include trip planning, route optimization, and travel time reporting.


### **Audience**  
This manual is intended for everyday workers with limited experience in informatics or technical systems. The software is designed to be user-friendly, offering a simple interface for non-technical users. However, installation and initial setup may require the assistance of an IT professional. Once set up, the tool’s regular use is straightforward and requires minimal technical knowledge. Instructions are provided in an easy-to-follow manner to support users throughout their experience.

#### **Key Points for the Audience**:

| **Feature**                     | **Description**                                                                 |
|----------------------------------|---------------------------------------------------------------------------------|
| **Designed for non-technical users** | The software is easy to use, with a simple interface and minimal technical jargon. |
| **Requires IT help for setup**    | Initial installation and configuration may require assistance from an IT professional. |
| **User-friendly after setup**     | Once installed, the tool is simple to use for everyday tasks, requiring minimal technical knowledge. |


### **Scope**  
The software provides a **REST API** that allows users to find travel times and calculate optimal routes between landmarks. By using a CSV dataset of road connections, the API processes user inputs and returns travel data in both XML and JSON formats. This enables easy integration with other systems and allows users to retrieve and interpret travel information in a way that suits their needs.

## 2. Prerequisites

  - **Minimum System Requirements**:

    | **Configuration**    | **Windows**                              | **Mac**                                       |
    |----------------------|------------------------------------------|-----------------------------------------------|
    | **Operating System**  | Windows 10 (64-bit) or later             | macOS Mojave (10.14) or later                 |
    | **Processor**         | Intel Core i3 (8th Gen) or AMD Ryzen 3   | Apple M1 or Intel Core i5                     |
    | **RAM**               | 4 GB minimum, 8 GB recommended for smooth performance | 4 GB minimum, 8 GB recommended for smooth performance |
    | **Storage**           | 100 MB of free space for software and dataset; SSD recommended for faster performance | 100 MB of free space for software and dataset; SSD recommended for faster performance |
    | **Graphics**          | Integrated graphics card (no dedicated GPU required) | Integrated graphics (Apple M1 has integrated GPU) |
    | **Network**           | Stable internet connection for API calls and software setup | Stable internet connection for API calls and software setup |
    | **Additional Notes**  | Software installation and dataset management may require admin privileges | Software installation and dataset management may require admin privileges |

  - **Basic Requirements**:
    - Input: Keyboard and mouse/trackpad.
    - Device: PC or laptop.
    - Power: Electricity or battery.
    - Network: Internet for initial setup.


  - **Software Requirements**:
    - **C++ Compiler**: GCC ([download here](https://gcc.gnu.org/))
    - HTTP Server: (e.g., Apache or Nginx; installation instructions may vary)
    - Additional Tools: Any required libraries for compilation and server setup.

  - **Data File**:  
    `USA-roads.csv` containing road connections and travel times in the format:  
    `Landmark_A_ID,Landmark_B_ID,Time`.
    
    Available for download [here](#).

## 3. Installation Guide

1. **Clone or Download the Repository**:  
   ```bash
   git clone https://github.com/algosup/2024-2025-project-3-quickest-path-team-5
   cd /2024-2025-project-3-quickest-path-team-5
   ```

2. **Set up Environment**:
    
    Ensure that you have the necessary tools and dependencies installed for both the software and the HTTP server.
      - C++ Compiler: Ensure that you have a working C++ compiler, such as GCC, installed. You can install GCC on your system using the appropriate package manager for your operating system:
        - Windows: Install MinGW (Minimalist GNU for Windows) or use the WSL (Windows Subsystem for Linux).
        - MacOS: GCC can be installed through Homebrew with the command brew install gcc.
      - HTTP Server: Ensure that you have a basic HTTP server set up. You can use any HTTP server like Apache or Nginx. For simplicity, this guide assumes a built-in HTTP server will be used when running the program.

3. **Compile the Software**:
    ```bash
    g++ -o main main.cpp -std=c++17
    ```

4. **Run the HTTP Server**:
    Start the server to expose the REST API:
    ```bash
    ./main
    ```

## 4. API Documentation
<strong>Endpoint Overview</strong>

- Base URL: http://localhost:PORT/api/path
- Method: GET
  
### Input Parameters : 
| Parameter	|Type	| Description|
|-----------|-----|------------|
|source_id	| integer	| Landmark ID of the starting point.|
|destination_id	| integer |	Landmark ID of the destination.|

### Response Formats
- JSON Example:
    ```json
    {
      "travel_time": 120,
      "path": ["Landmark_A", "Landmark_B"]
    }
    ```

- XML Example:
    ```xml
    <response>
      <travel_time>120</travel_time>
      <path>
        <landmark>Landmark_A</landmark>
        <landmark>Landmark_B</landmark>
      </path>
    </response>
    ```

### Sample Query

- URL Format:
    ```bash
    GET http://localhost:PORT/api/path?source_id=1&destination_id=5
    ```

## 5. Usage Instructions

- <strong>Sending API Requests:</strong>
Use tools like **curl**, **Postman**, or a browser:

    ```bash
    curl "http://localhost:PORT/api/path?source_id=1&destination_id=5"
    ```

- <strong>Interpreting the Response:</strong>
  - travel_time: The time required to travel between landmarks.
  - path: An ordered list of landmarks representing the route.

## 6. Algorithm Explanation
  
  - <strong>Overview:</strong>
      The software uses graph traversal algorithms (e.g., Dijkstra's or A* with heuristics) to calculate paths.

  - <strong>Time and Space Complexity:</strong>
    - Graph Traversal: O(V + E)
    - Heuristic Estimation: O(1)

  - <strong>Accuracy:</strong>
      Results are guaranteed to be within 10% of the shortest possible path to prioritize speed.

## 7. Data Integrity Validation

  - <strong>Graph Validation:</strong>
      Ensures the data forms a Directed Acyclic Graph (DAG) and is free of loops.

  - <strong>Connectivity Check:</strong>
      Confirms all landmarks in the graph are reachable.


## 8. Troubleshooting

  <strong>Common Issues</strong>
    1. Missing or Incorrect **USA-roads.csv** File:
       - Ensure the file is in the correct directory.
    2. API Not Responding:
       - Verify the HTTP server is running on the specified port.
    3. Unexpected Results:
       - Check the input IDs and ensure they exist in the dataset.

## 9. Test Suite

  - <strong>Overview:</strong>
      Includes tests for correctness, performance, and compliance with the 10% approximation rule.
  - <strong>Running Tests:</strong>
      ```bash
      ./run_tests
      ```

  - <strong>Sample Results:</strong>
    Outputs the expected travel time and path for predefined test cases.

## 10.  FAQs

  <strong>Common Questions</strong>
  - Q: How does the software handle invalid inputs?
    - A: Returns an error message indicating the issue.
  
  - Q: Can additional data be added to **USA-roads.csv**?
    - A: Yes, but it must follow the required format.

## 11.  Contact Information

  - For support or to report issues, contact:
    - Email: support@example.com
    - GitHub Issues: <repository_url>/issues

## 12.  Appendix

  - Glossary:
    - Landmark: A point of interest in the graph (e.g., city, intersection).
    - Travel Time: The time required to travel between two connected landmarks.
  - References:
    - STL Documentation: <link>
    - REST API Standards: <link>