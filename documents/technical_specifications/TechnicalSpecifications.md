# Technical Specifications

<details>
    <summary>Table of contents</summary>

- [Technical Specifications](#technical-specifications)
  - [Project Overview](#project-overview)
  - [1. Introduction](#1-introduction)
    - [1.1 Purpose](#11-purpose)
    - [1.2 Scope](#12-scope)
    - [1.3 Audience](#13-audience)
    - [1.4 Convention](#14-convention)
      - [1.4.1 File tree and documents](#141-file-tree-and-documents)
      - [1.4.2 Code](#142-code)
        - [Quick Reminder](#quick-reminder)
          - [C Naming](#c-naming)
          - [C++ Naming](#c-naming-1)
  - [2. System Requirements](#2-system-requirements)
    - [2.1 Functional Requirements](#21-functional-requirements)
      - [2.1.1 Data Checker](#211-data-checker)
      - [2.1.2 REST API](#212-rest-api)
    - [2.2 Non-Functional Requirements](#22-non-functional-requirements)
      - [2.2.1 Data Checker](#221-data-checker)
      - [2.2.2 REST API](#222-rest-api)
  - [3. System Architecture](#3-system-architecture)
    - [3.1 Overview](#31-overview)
      - [3.1.1 Key Design Considerations](#311-key-design-considerations)
    - [3.2 Flow Chart](#32-flow-chart)
    - [3.3 Data Flow Diagram](#33-data-flow-diagram)
  - [4. Detailed Design](#4-detailed-design)
    - [4.1 User Interface Design](#41-user-interface-design)
    - [4.2 Backend Design](#42-backend-design)
      - [4.2.1. REST API Endpoint](#421-rest-api-endpoint)
      - [4.2.2. Request Handling Layer](#422-request-handling-layer)
      - [4.2.3. Pathfinding Engine](#423-pathfinding-engine)
      - [4.2.4. Data Validation Tool Integration](#424-data-validation-tool-integration)
      - [4.2.5. Security Layer](#425-security-layer)
      - [4.2.6. Response Serialization](#426-response-serialization)
      - [4.2.7. Scalability Design](#427-scalability-design)
      - [4.2.8. Testing and Monitoring](#428-testing-and-monitoring)
    - [4.3 Data Structure](#43-data-structure)
      - [4.3.1 Graph Characteristics](#431-graph-characteristics)
      - [4.3.2 Graph Properties](#432-graph-properties)
      - [4.3.3 Data Representation](#433-data-representation)
      - [4.3.4 Data Integrity Validation](#434-data-integrity-validation)
    - [4.3.5 Usage in Pathfinding](#435-usage-in-pathfinding)
  - [5. Development Approach](#5-development-approach)
    - [5.1 Methodology](#51-methodology)
    - [5.2 Tools and Technologies](#52-tools-and-technologies)
  - [Glossary](#glossary)

</details>


## Project Overview

The application is designed to determine the shortest path from Point A to Point B. It provides users with detailed step-by-step instructions for the journey, including intermediate landmarks and the estimated travel time for each segment[.][3]

## 1. Introduction

<br>

### 1.1 Purpose

The purpose of this document is to define the technical specifications for developing the pathfinding application. It offers a detailed overview of the system's requirements, architecture, core functionalities, and the development methodology to be followed[.][3]

### 1.2 Scope

The project encompasses the following key components, each tailored for cross-platform compatibility and developed using industry-standard technologies:

1. **Data Checker**
   - **Name:** `NAME`
   - **Type:** Desktop Application
   - **Technology:** Developed in [C][2]
   - **Supported Platforms:** Linux, Windows, and macOS
2. **REST API**<sup>[2](#glossary-2)</sup>
   - **Name:** `NAME`
   - **Type:** Web API
   - **Technology:** Developed in [C++][1]
   - **Supported Platforms:** Platform-agnostic<sup>[3](#glossary-3)</sup>

### 1.3 Audience

This document is intended for the following audiences:

- `Project Managers:` To understand the scope, requirements, and technical details of the project for effective planning and coordination.
- `Software Engineers:` To gain detailed insights into the system architecture, design, and coding standards required for development.
- `UI/UX Designers:` To align their designs with the technical capabilities and limitations outlined in the specifications.
- `Quality Assurance Testers:` To prepare test plans and cases that ensure the application meets the outlined technical requirements.
- `Stakeholders:` To provide an overview of the project's technical aspects, ensuring alignment with business goals and expectations.

### 1.4 Convention



#### 1.4.1 File tree and documents

The naming conventions should be as follows:

| type    | convention     |
| ------- | -------------- |
| Folders | **snake_case** |
| Files   | **PascalCase** |

```md
2024-2025-project-3-quickest-path-team-5
└───documents
    ├───functional
    │   └─── FunctionalSpecifications.md
    ├───quality
    └───technical
        └─── TechnicalSpecifications.md
```

#### 1.4.2 Code

Our coding conventions are aligned with the standard practices and guidelines recommended for each programming language used in this project[.][3] By adhering to language-specific conventions and widely accepted best practices, we ensure code that is consistent, readable, and maintainable[.][3]

For this project, we have established a detailed set of coding conventions tailored to meet our specific requirements and promote collaboration across the team[.][3] These conventions cover aspects such as naming conventions, formatting rules, error handling, and use of language features[.][3]

You can find the full coding convention guidelines in the [Coding Conventions document](CodingConventions.md "Coding Conventions")[.][3]

##### Quick Reminder

###### C Naming
[<img height="48px" width="48px" alt="Icone C" src="https://skillicons.dev/icons?i=c"/>][2]

<hr>

| Type              | Convention       |
| ----------------- | ---------------- |
| `Variables`       | snake_case       |
| `Constants`       | UPPER_SNAKE_CASE |
| `Functions`       | camelCase        |
| `Structs & Enums` | PascalCase       |

###### C++ Naming
[<img height="48px" width="48px" alt="Icone C++" src="https://skillicons.dev/icons?i=cpp"/>][1]
<hr>

| Type        | Convention       |
| ----------- | ---------------- |
| `Variables` | camelCase        |
| `Constants` | UPPER_SNAKE_CASE |
| `Functions` | camelCase        |
| `Class`     | PascalCase       |

## 2. System Requirements

<br>

### 2.1 Functional Requirements  

#### 2.1.1 Data Checker  

- **CSV File Import**  
  - Users should be able to import a CSV file into the application for validation. Supported formats should be clearly documented, and the system should reject invalid files with detailed feedback.  

- **Error Reporting**  
  - The application will display detailed error messages in the terminal, including row and column numbers, to help users identify and correct issues in the CSV file.  

- **Visual Representation of Linked Nodes**  
  - The application will generate a visual diagram displaying each node and its connections, using color-coded indicators for errors or anomalies in the data.  

- **Node and Connection Validation**  
  - The application will verify the integrity of the imported data, ensuring all nodes and connections are valid and consistent with the required format.  

- **Export Corrected Data**  
  - Users should be able to export corrected or validated data to a new CSV file for further use.  

#### 2.1.2 REST API  

- **Endpoint for Shortest Path Calculation**  
  - Provide an endpoint that accepts input parameters (e.g., start point, end point) and returns the shortest path, including intermediate steps and estimated travel times.  

- **Error Handling and Status Codes**  
  - Ensure all API endpoints return appropriate HTTP status codes and detailed error messages for invalid requests or server errors.  

- **Authentication and Authorization**  
  - Secure the API using authentication (e.g., OAuth 2.0, API keys) and enforce role-based access control to restrict sensitive operations.

### 2.2 Non-Functional Requirements  

#### 2.2.1 Data Checker  

- **Compatibility**  
  - The application should be compatible with Linux, Windows, and macOS, supporting version 12 and the latest releases of each operating system.  

- **Usability**  
  - The interface should provide clear feedback during file imports and error highlighting to minimize user confusion.  
  - A help section or documentation link should be accessible from the interface for troubleshooting.  

- **Performance**  
  - The application should process CSV files and provide error feedback within 1 second for standard datasets.  

#### 2.2.2 REST API  

- **Performance**  
  - The REST API should respond to requests within 200ms under normal conditions and support high throughput.  

- **Scalability**  
  - The backend should be designed to scale horizontally to handle a growing number of concurrent users efficiently.  

- **Compatibility**  
  - The REST API should be platform-agnostic and deployable on any server environment that supports the required C++ runtime and dependencies.  

- **Security**  
  - All endpoints should enforce authentication and authorization protocols to protect sensitive data.  
  - The API must adhere to industry-standard practices such as HTTPS for secure communication.  

- **Documentation**  
  - Comprehensive API documentation must be provided, including endpoint details, example requests/responses, and error codes.

## 3. System Architecture

<br>

### 3.1 Overview  

The system architecture is designed to ensure seamless functionality, high performance, and a user-friendly experience across all supported platforms. It consists of the following key components:   

- **Desktop Application (Data Checker)**  
  - **Technology**: Developed using [C][2] for it performance in handling data integrity checks.  
  - **Purpose**: A utility application used to validate the integrity of the dataset (e.g., CSV file) by verifying graph properties such as connectivity and absence of loops.  
  - **Supported Platforms**: Compatible with Linux, Windows, and macOS.  

- **REST API**  
  - **Technology**: Developed using [C++][1] to ensure platform-agnostic deployment.  
  - **Purpose**: Exposes core functionality through an HTTP server, providing endpoints for calculating shortest paths, managing data, and retrieving results in multiple formats (e.g., JSON and XML).  
  - **Compatibility**: Designed to be deployable on any server environment that supports the required C++ runtime.  

- **Authentication Service**  
  - **Technology**: Integrated with the REST API, potentially using industry-standard authentication methods (e.g., OAuth 2.0, API keys).  
  - **Purpose**: Ensures secure access to the REST API by validating user credentials and managing authorization.  
  - **Scalability**: Supports role-based access control for future scalability and extended functionality.  

#### 3.1.1 Key Design Considerations

- **Modular Design**: Each component is designed to operate independently, ensuring maintainability and ease of updates.  
- **High Performance**: The architecture prioritizes efficiency to handle large datasets and complex computations within the defined performance constraints.  
- **Cross-Platform Support**: Desktop applications and the REST API are built to function seamlessly across Linux, Windows, and macOS.  
- **Extensibility**: The system is designed to accommodate future enhancements, such as adding new endpoints, improving UI/UX, or integrating with external services.  

<!-- TODO: Change the name and link of this section -->
### 3.2 Flow Chart

<!-- TODO: Add a flow chart -->

### 3.3 Data Flow Diagram

<!-- TODO: [Insert Data Flow Diagram Here] -->

## 4. Detailed Design

<br>

### 4.1 User Interface Design

<!-- TODO: Have to decide if we do a UI -->

### 4.2 Backend Design

The backend is structured to handle multiple requests efficiently and securely. Key components include:

#### 4.2.1. REST API Endpoint
- **Purpose**: Provides access to the core functionality of the application through a single GET endpoint.  
- **Input**: Accepts source and destination landmark IDs as query parameters.  
- **Output**: Returns the travel time and the ordered list of landmarks in the shortest path in both `XML` and `JSON` formats.  
- **Design**: Built using C++ for high performance, leveraging lightweight HTTP server libraries such as `Boost.Beast`, `cpp-httplib` or `Pistache`.

#### 4.2.2. Request Handling Layer
- **Purpose**: Parses incoming requests, validates inputs, and routes them to the appropriate modules.  
- **Error Handling**: Ensures that invalid or incomplete requests return descriptive error messages (e.g., `400 Bad Request`).  
- **Concurrency**: Supports handling multiple requests simultaneously using threading or asynchronous techniques.

#### 4.2.3. Pathfinding Engine
- **Purpose**: Implements the core algorithm for finding the shortest path between two landmarks.  
- **Algorithm**: Utilizes Dijkstra’s or A* algorithm for optimal performance with heuristics to meet the 10% approximation rule.  
- **Data Loading**: Reads the graph data (from `USA-roads.csv`) into memory during initialization to optimize query response times.  
- **Performance Goals**: Ensures responses within 1 second for typical requests.

#### 4.2.4. Data Validation Tool Integration
- **Purpose**: Verifies the integrity of the graph data before it is loaded into memory.  
- **Functionality**: Ensures that the dataset forms a fully connected graph and is free of loops.  
- **Implementation**: Operates as a pre-processing step, run infrequently but essential for ensuring data accuracy.

#### 4.2.5. Security Layer
- **Purpose**: Protects the REST API from unauthorized access.  
- **Implementation**:  
  - API key-based authentication for identifying and authorizing clients.  
  - Input sanitization to prevent injection attacks.  
  - Rate limiting to mitigate DoS (Denial of Service) attacks.

#### 4.2.6. Response Serialization
- **Purpose**: Converts the output of the pathfinding engine into the requested format (XML or JSON).  
- **Design**: Utilizes lightweight serialization libraries to minimize overhead while maintaining compatibility with modern REST standards.

#### 4.2.7. Scalability Design
- **Purpose**: Prepares the backend for increasing traffic and data loads.  
- **Techniques**:  
  - Modular architecture to allow easy scaling of individual components.  
  - Potential integration with a load balancer for distributed deployments in production environments.

#### 4.2.8. Testing and Monitoring
- **Unit Testing**: Comprehensive test suite to validate the correctness of each backend component.  
- **Performance Testing**: Ensures the API meets the 1-second response time requirement under normal conditions.  
- **Logging and Monitoring**: Captures API usage and performance metrics to diagnose issues and optimize performance over time.

### 4.3 Data Structure

The application relies on a **weighted, undirected graph** to model the road network of landmarks and travel times. This graph structure serves as the foundation for implementing efficient pathfinding algorithms and ensuring accurate results within the defined performance constraints.

#### 4.3.1 Graph Characteristics

- **Nodes (Vertices):**  
  Represent landmarks in the road network. Each node is uniquely identified by a landmark ID.

- **Edges:**  
  Represent bidirectional roads connecting two landmarks. Each edge has a weight, which corresponds to the travel time between the two connected landmarks.

- **Weights:**  
  Edge weights are integer values representing travel time in an unspecified unit. Lower weights indicate shorter travel times.

#### 4.3.2 Graph Properties

- **Weighted:**  
  Each edge has a numerical value (weight) representing travel time.

- **Undirected:**  
  Roads are bidirectional. If an edge exists from landmark A to landmark B, the reverse is also true.

- **Cyclic:**  
  The graph inherently contains cycles, as multiple paths often connect landmarks.

- **Sparse Graph:**  
  Since real-world road networks are typically sparse (many fewer edges than the maximum possible), efficient data structures are used to optimize memory and runtime performance.

#### 4.3.3 Data Representation

The graph will be implemented using the following data structures for optimal performance and scalability:

1. **Adjacency List:**  
   - Used for representing the graph. Each node maintains a list of its neighbors and associated weights (travel times).  
   - Efficient for sparse graphs, as it minimizes memory usage.

   **Example:**  
   ```text
    Node A: [(B, 5), (C, 10)]  
    Node B: [(A, 5), (C, 3)]  
    Node C: [(A, 10), (B, 3)]
   ```  
2. **Hash Map for Node Lookup:**
   - A hash map (or dictionary) is used for fast lookup of nodes by their landmark IDs.

   **Example:**
    ```cpp
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
    Priority Queue (for Pathfinding):
    ```

3. **Priority Queue (for Pathfinding):**
   - Utilized in algorithms like Dijkstra or A* to efficiently retrieve the next node with the shortest travel time.
   - Typically implemented as a min-heap.

   **Example:**
    ```cpp
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
    ```
#### 4.3.4 Data Integrity Validation
To ensure the correctness of the graph structure, the following validation steps are performed during the data import phase:

1. **Self-Loop Check:**
   - Ensure no edge connects a node to itself (e.g., `A -> A`).

2. **Duplicate Edge Check:**
   - Verify that no duplicate edges exist between two nodes with differing weights.

3. **Connectivity Check:**
   - Confirm the graph is fully connected, ensuring all nodes are reachable from any other node.

4. **Symmetry Check:**
   - Ensure bidirectionality of all edges (e.g., if `A -> B` exists, `B -> A` must also exist with the same weight).

### 4.3.5 Usage in Pathfinding
The weighted, undirected graph is optimized for algorithms like **Dijkstra** and **A\*** to calculate the shortest path efficiently. These algorithms leverage the adjacency list and priority queue to balance performance and memory usage, ensuring the application meets its response time requirements.


## 5. Development Approach

<br>

### 5.1 Methodology

The project will follow the Agile methodology, with development broken down into sprints. Each sprint will focus on specific features and improvements, allowing for iterative development and continuous feedback.

### 5.2 Tools and Technologies

| Category                            | Tools/Technologies used                                                                                        |
| ----------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| Data Checking Application           | C<sup>99</sup> to keep a fast runtime but using a mastered language of our software engineer.                               |
| REST API<sup>[2](#glossary-2)</sup> | C++<sup>14</sup> to keep a fast runtime and not using to many unnecessary language keeping the project easily maintainable. |
| Response Format                     | JSON but we want to implement the possibility to get XML also                                                  |
| Version Control                     | Git with GitHub.                                                                                               |
| CI/CD<sup>[1](#glossary-1)</sup>    | GitHub Actions for continuous integration and deployment.                                                      |

## Glossary

| Id                       | Term              | Definition                                                                                                                                                                                                        |
| ------------------------ | ----------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <p id="glossary-1">1</p> | CI/CD             | Continuous Integration/Continuous Deployment, a software development practice.                                                                                                                                    |
| <p id="glossary-2">2</p> | REST API          | A REST API (also called a RESTful API or RESTful web API) is an application programming interface (API) that conforms to the design principles of the representational state transfer (REST) architectural style. |
| <p id="glossary-3">3</p> | Platform agnostic | Platform agnostic refers to software, applications, or services designed to operate across various operating systems, device types, web browsers, or other foundational technologies.                             |

<!-- LINKS -->
[1]: https://en.wikipedia.org/wiki/C%2B%2B "C++ Wikipedia"
[2]: https://en.wikipedia.org/wiki/C_(programming_language) "C Wikipedia"
[3]: https://www.youtube.com/watch?v=tas0O586t80 "Program in C"
[4]: https://en.wikipedia.org/wiki/JSON "JSON Wikipedia"
[5]: https://en.wikipedia.org/wiki/XML "XML Wikipedia"