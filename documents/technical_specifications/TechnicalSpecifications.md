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
      - [2.1.2 REST API2](#212-rest-api2)
    - [2.2 Non-Functional Requirements](#22-non-functional-requirements)
      - [2.2.1 Data Checker](#221-data-checker)
      - [2.2.2 REST API2](#222-rest-api2)
  - [3. System Architecture](#3-system-architecture)
    - [3.1 Overview](#31-overview)
      - [3.1.1 Key Design Considerations](#311-key-design-considerations)
    - [3.2 Pathfinding4 Algorithms](#32-pathfinding4-algorithms)
      - [3.2.1 Dijkstra5's Algorithm](#321-dijkstra5s-algorithm)
      - [3.2.2 A\*6 Algorithm](#322-a6-algorithm)
      - [3.2.3 Algorithm Selection Process](#323-algorithm-selection-process)
      - [3.2.4 Integration](#324-integration)
    - [3.3 Data Flow Overview](#33-data-flow-overview)
      - [3.3.1 High-Level Data Flow Diagram](#331-high-level-data-flow-diagram)
      - [3.3.2 Shortest Path Algorithm Execution Flow](#332-shortest-path-algorithm-execution-flow)
      - [Explanation:](#explanation)
    - [3.4 Flow Chart](#34-flow-chart)
      - [Explanation:](#explanation-1)
  - [4. Detailed Design](#4-detailed-design)
    - [4.1 Backend Design](#41-backend-design)
      - [4.1.1. REST API2 Endpoint](#411-rest-api2-endpoint)
      - [4.1.2. Request Handling Layer](#412-request-handling-layer)
      - [4.1.3. Pathfinding4 Engine](#413-pathfinding4-engine)
      - [4.1.4. Data Validation Tool Integration](#414-data-validation-tool-integration)
      - [4.1.5. Security Layer](#415-security-layer)
      - [4.1.6. Response Serialization39](#416-response-serialization39)
      - [4.1.7. Scalability28 Design](#417-scalability28-design)
      - [4.1.8. Testing and Monitoring](#418-testing-and-monitoring)
    - [4.3 Data Structure](#43-data-structure)
      - [4.3.1 Graph Characteristics](#431-graph-characteristics)
      - [4.3.2 Graph Properties](#432-graph-properties)
      - [4.3.3 Data Representation](#433-data-representation)
      - [4.3.4 Data Integrity33 Validation](#434-data-integrity33-validation)
    - [4.3.5 Usage in Pathfinding4](#435-usage-in-pathfinding4)
  - [5. Development Approach](#5-development-approach)
    - [5.1 Methodology](#51-methodology)
    - [5.2 Tools and Technologies](#52-tools-and-technologies)
    - [5.3 Libraries used](#53-libraries-used)
    - [5.4 Software](#54-software)
    - [5.5 Target](#55-target)
      - [5.5.1 Desktop Platforms](#551-desktop-platforms)
      - [5.5.2 Web Server for REST API2](#552-web-server-for-rest-api2)
    - [Notes:](#notes)
  - [6. Testing](#6-testing)
    - [6.1 Testing Strategy](#61-testing-strategy)
    - [6.2 Tools](#62-tools)
  - [7. Deployment](#7-deployment)
    - [7.1 Deployment Pipeline](#71-deployment-pipeline)
    - [7.2 Maintenance](#72-maintenance)
    - [8.1 Data Security](#81-data-security)
    - [8.2 Compliance](#82-compliance)
    - [8.3 Security Best Practices](#83-security-best-practices)
    - [8.4 Secure Development Practices](#84-secure-development-practices)
  - [9. Glossary](#9-glossary)

</details>


## Project Overview

The application is designed to determine the shortest path from Point A to Point B. It provides users with detailed step-by-step instructions for the journey, including intermediate landmarks and the estimated travel time for each segment[.][3]

## 1. Introduction

<br>

### 1.1 Purpose

The purpose of this document is to define the technical specifications for developing the pathfinding<sup>[4](#glossary-4)</sup> application. It offers a detailed overview of the system's requirements, architecture, core functionalities, and the development methodology to be followed[.][3]

### 1.2 Scope

The project encompasses the following key components, each tailored for cross-platform<sup>[19](#glossary-19)</sup> compatibility and developed using industry-standard technologies:

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

- **CSV<sup>[9](#glossary-9)</sup> File Import**  
  - Users should be able to import a CSV<sup>[9](#glossary-9)</sup> file into the application for validation. Supported formats should be clearly documented, and the system should reject invalid files with detailed feedback.  

- **Error Reporting**  
  - The application will display detailed error messages in the terminal, including row and column numbers, to help users identify and correct issues in the CSV<sup>[9](#glossary-9)</sup> file.  

- **Visual Representation of Linked Nodes<sup>[14](#glossary-14)</sup>**  
  - The application will generate a visual diagram displaying each node<sup>[14](#glossary-14)</sup> and its connections, using color-coded indicators for errors or anomalies in the data.  

- **Node<sup>[14](#glossary-14)</sup> and Connection Validation**  
  - The application will verify the integrity of the imported data, ensuring all nodes<sup>[14](#glossary-14)</sup> and connections are valid and consistent with the required format.  

<!-- TODO: Modify depending of software engineers implemented algo -->
- **Algorithm Complexity**  
  - The data validation algorithm used for checks, such as graph<sup>[8](#glossary-8)</sup> validation and connectivity, will operate with a time complexity<sup>[13](#glossary-13)</sup> of **O(log n)** for most operations, ensuring efficient processing of large datasets.

#### 2.1.2 REST API<sup>[2](#glossary-2)</sup>  

- **Endpoint for Shortest Path Calculation**  
  - Provide an endpoint that accepts input parameters (e.g., start point, end point) and returns the shortest path, including intermediate steps and estimated travel times.  

- **Error Handling and Status Codes**  
  - Ensure all API endpoints return appropriate HTTP<sup>[11](#glossary-11)</sup> status codes and detailed error messages for invalid requests or server errors.  

- **Authentication and Authorization**  
  - Secure the API using authentication (e.g., OAuth<sup>[20](#glossary-20)</sup> 2.0, API keys<sup>[21](#glossary-21)</sup>) and enforce role-based access control<sup>[24](#glossary-24)</sup> to restrict sensitive operations.

### 2.2 Non-Functional Requirements  

#### 2.2.1 Data Checker  

- **Compatibility**  
  - The application should be compatible with Linux, Windows, and macOS, supporting version 12 and the latest releases of each operating system.  

- **Usability**  
  - The interface should provide clear feedback during file imports and error highlighting to minimize user confusion.  
  - A help section or documentation link should be accessible from the interface for troubleshooting.  

- **Performance**  
  - The application should process CSV<sup>[9](#glossary-9)</sup> files and provide error feedback within 1 second for standard datasets.  

#### 2.2.2 REST API<sup>[2](#glossary-2)</sup>  

- **Performance**  
  - The REST API<sup>[2](#glossary-2)</sup> should respond to requests within 200ms under normal conditions and support high throughput.  

- **Scalability<sup>[28](#glossary-28)</sup>**  
  - The backend should be designed to scale horizontally to handle a growing number of concurrent users efficiently.  

- **Compatibility**  
  - The REST API<sup>[2](#glossary-2)</sup> should be platform-agnostic<sup>[3](#glossary-3)</sup> and deployable on any server environment that supports the required C++ runtime and dependencies.  

- **Security**  
  - All endpoints should enforce authentication and authorization protocols to protect sensitive data.  
  - The API must adhere to industry-standard practices such as HTTPS for secure communication.  

- **Documentation**  
  - Comprehensive API documentation<sup>[23](#glossary-23)</sup> must be provided, including endpoint details, example requests/responses, and error codes.

## 3. System Architecture

<br>

### 3.1 Overview  

The system architecture is designed to ensure seamless functionality, high performance, and a user-friendly experience across all supported platforms. It consists of the following key components:   

- **Desktop Application (Data Checker)**  
  - **Technology**: Developed using [C][2] for it performance in handling data integrity<sup>[33](#glossary-33)</sup> checks.  
  - **Purpose**: A utility application used to validate the integrity of the dataset (e.g., CSV<sup>[9](#glossary-9)</sup> file) by verifying graph<sup>[8](#glossary-8)</sup> properties such as connectivity and absence of loops.  
  - **Supported Platforms**: Compatible with Linux, Windows, and macOS.  

- **REST API<sup>[2](#glossary-2)</sup>**  
  - **Technology**: Developed using [C++][1] to ensure platform-agnostic<sup>[3](#glossary-3)</sup> deployment.  
  - **Purpose**: Exposes core functionality through an HTTP<sup>[11](#glossary-11)</sup> server, providing endpoints for calculating shortest paths, managing data, and retrieving results in multiple formats (e.g., JSON<sup>[16](#glossary-16)</sup> and XML<sup>[17](#glossary-17)</sup>).  
  - **Compatibility**: Designed to be deployable on any server environment that supports the required C++ runtime.  

- **Authentication Service**  
  - **Technology**: Integrated with the REST API<sup>[2](#glossary-2)</sup>, potentially using industry-standard authentication methods (e.g., OAuth<sup>[20](#glossary-20)</sup> 2.0, API keys<sup>[21](#glossary-21)</sup>).  
  - **Purpose**: Ensures secure access to the REST API<sup>[2](#glossary-2)</sup> by validating user credentials and managing authorization.  
  - **Scalability<sup>[28](#glossary-28)</sup>**: Supports role-based access control<sup>[24](#glossary-24)</sup> for future scalability<sup>[28](#glossary-28)</sup> and extended functionality.  

#### 3.1.1 Key Design Considerations

- **Modular Design<sup>[27](#glossary-27)</sup>**: Each component is designed to operate independently, ensuring maintainability and ease of updates.  
- **High Performance**: The architecture prioritizes efficiency to handle large datasets and complex computations within the defined performance constraints.  
- **Cross-Platform<sup>[19](#glossary-19)</sup> Support**: Desktop applications and the REST API<sup>[2](#glossary-2)</sup> are built to function seamlessly across Linux, Windows, and macOS.  
- **Extensibility**: The system is designed to accommodate future enhancements, such as adding new endpoints, improving UI/UX, or integrating with external services.  

### 3.2 Pathfinding<sup>[4](#glossary-4)</sup> Algorithms 

To complete this project, we employ two robust algorithms, **Dijkstra<sup>[5](#glossary-5)</sup>'s Algorithm** and **A\*<sup>[6](#glossary-6)</sup>**, to balance fast runtime and accuracy in pathfinding<sup>[4](#glossary-4)</sup>.  

#### 3.2.1 Dijkstra<sup>[5](#glossary-5)</sup>'s Algorithm  
- **Purpose:**  
  Finds the shortest path between two landmarks in a graph<sup>[8](#glossary-8)</sup>.  
- **Advantages:**  
  - Guarantees the shortest path.  
  - Works well when all edge<sup>[15](#glossary-15)</sup> weights are non-negative.  
- **Usage in the Project:**  
  Dijkstra<sup>[5](#glossary-5)</sup>'s algorithm is used for cases where simplicity and guaranteed accuracy are prioritized over speed.  

#### 3.2.2 A\*<sup>[6](#glossary-6)</sup> Algorithm  
- **Purpose:**  
  An optimized version of Dijkstra<sup>[5](#glossary-5)</sup>'s algorithm that uses a <sup>[7](#glossary-7)</sup> to prioritize nodes<sup>[14](#glossary-14)</sup>, reducing computation time.  
- **Advantages:**  
  - Faster than Dijkstra<sup>[5](#glossary-5)</sup> for large graphs.  
  - Offers a good trade-off between speed and precision.  
- **Usage in the Project:**  
  A\*<sup>[6](#glossary-6)</sup> is used for most route calculations to ensure results are delivered within the project's strict performance constraints (e.g., under 1 second).  

#### 3.2.3 Algorithm Selection Process  
- **Why Two Algorithms?**  
  - **Dijkstra<sup>[5](#glossary-5)</sup>'s Algorithm:** Ensures correctness for critical paths requiring precision.  
  - **A\*<sup>[6](#glossary-6)</sup> Algorithm:** Optimized for real-time performance, especially for large-scale graphs with millions of nodes<sup>[14](#glossary-14)</sup>.  
- **<sup>[7](#glossary-7)</sup> in A\*<sup>[6](#glossary-6)</sup>:**  
  We use an admissible heuristic<sup>[7](#glossary-7)</sup> (e.g., Euclidean<sup>[25](#glossary-25)</sup> or Manhattan<sup>[26](#glossary-26)</sup> distance) to guide the search towards the target landmark while maintaining the 10% accuracy constraint.  

#### 3.2.4 Integration  
The system dynamically selects between Dijkstra<sup>[5](#glossary-5)</sup> and A\*<sup>[6](#glossary-6)</sup> based on the query complexity and time constraints. Both algorithms are implemented to handle the provided 24-million node<sup>[14](#glossary-14)</sup> dataset efficiently.  

### 3.3 Data Flow Overview

Below is a high-level representation of the data flow in the system using a Mermaid<sup>[10](#glossary-10)</sup> diagram:  

#### 3.3.1 High-Level Data Flow Diagram

```mermaid
graph TD  
  subgraph  
    A[Client Request] -->|REST API Call| B[Backend Server]  
    B -->|Validate Input| C[Input Validation Module]  
    C -->|Fetch Data| D[Graph Data Loader]  
    D -->|Process Shortest Path| E[Algorithm Selector]  
    E -->|Run Algorithm| F{Dijkstra or A*}  
    F -->|Compute Path| G[Path Result Generator]  
    G -->|Format Response 'JSON or XML'| H[Response Formatter]  
    H -->|Return Response| I[Client]  
  end
```

#### 3.3.2 Shortest Path Algorithm Execution Flow

```mermaid
flowchart TD
  A[Origin]
  B[Get the shortest path]
  C[Start a new thread]
  D[Start a new thread]
  E[Calculate the path using A*]
	F[Calculate the path using Dijkstra]
	G[End thread]
	H[End thread]
	I{Is A* done}
	J[Wait A* end]
	K{Is Dijkstra done}
	L[End Dijkstra Thread]
	M[Return Dijkstra Result]
	N[Get random key points in the A* path]
	O[Start new thread]
	P[Calculate the path using Dijkstra]
	Q[End thread]
	R[Merge path into a single one]
	S[Return complete path]
	T{Is 1s elapsed}
	U[Return A* path]

	
  subgraph  
    A --> B
    B --> C
    B --> D

    subgraph Thread 1
      direction TB
      C --> E
      E --> G
    end

    subgraph Thread 2
      direction TB
      D --> F
      F --> H
    end

    G --> I
    H --> I
    I -- No --> J
    J --> K
    I -- Yes --> K
    K -- No --> T
    K -- Yes --> M
    T -- Yes --> U
    T -- No --> L
    L --> N
    N --> O

    subgraph Number of thread base on path length and computer resources
      direction TB
      O --> P
      P --> Q
    end

    Q --> R
    R --> S
  end
```


#### Explanation:  
1. **Client Request:** The user initiates a request through the REST API<sup>[2](#glossary-2)</sup>, specifying source and destination landmarks.  
2. **Input Validation Module:** Ensures the request parameters are valid (e.g., valid IDs, non-empty input).  
3. **Graph Data Loader:** Loads graph<sup>[8](#glossary-8)</sup> data from the dataset into memory for processing.  
4. **Algorithm Selector:** Chooses between Dijkstra<sup>[5](#glossary-5)</sup> and A\*<sup>[6](#glossary-6)</sup> based on query requirements.  
5. **Algorithm Execution:** Executes the selected algorithm to compute the shortest path.  
6. **Path Result Generator:** Converts raw algorithm results into meaningful data.  
7. **Response Formatter:** Formats the response in JSON<sup>[16](#glossary-16)</sup> or XML<sup>[17](#glossary-17)</sup> as requested by the client.  
8. **Client Response:** Sends the formatted data back to the client.  

### 3.4 Flow Chart

Below is a flow chart that represents the overall process of handling a request in the system:

```mermaid  
graph TD  
    A[Start] --> B[Receive Request from Client]  
    B --> C[Validate Input Data]  
    C --> D{Is Input Valid?}  
    D -->|Yes| E[Load Graph Data]  
    D -->|No| F[Return Error Response]  
    E --> G[Select Algorithm 'Dijkstra / A*']  
    G --> H[Run Algorithm]  
    H --> I[Generate Path Result]  
    I --> J[Format Response 'JSON / XML']  
    J --> K[Send Response to Client]  
    K --> L[End]  
```

#### Explanation:  
1. **Receive Request:** The client sends a request with source and destination data.
2. **Validate Input Data:** The system checks if the input data is valid (e.g., source and destination IDs).
3. **Is Input Valid?**: A decision point to verify if the input data is valid. If it’s not, the system returns an error response.
4. **Load Graph Data:** If the input is valid, the system loads the graph<sup>[8](#glossary-8)</sup> data to process the request.
5. **Select Algorithm:** The algorithm is selected based on the input parameters (either Dijkstra<sup>[5](#glossary-5)</sup> or A*<sup>[6](#glossary-6)</sup>).
6. **Run Algorithm:** The selected algorithm is executed to find the shortest path.
7. **Generate Path Result:** The result of the algorithm is converted into a usable format.
8. **Format Response:** The path result is formatted into JSON<sup>[16](#glossary-16)</sup> or XML<sup>[17](#glossary-17)</sup> for the client.
9. **Send Response:** The formatted response is sent back to the client.
10. **End:** The process ends after the response is sent.

## 4. Detailed Design

<br>

### 4.1 Backend Design

The backend is structured to handle multiple requests efficiently and securely. Key components include:

#### 4.1.1. REST API<sup>[2](#glossary-2)</sup> Endpoint
- **Purpose**: Provides access to the core functionality of the application through a single GET endpoint.  
- **Input**: Accepts source and destination landmark IDs as query parameters.  
- **Output**: Returns the travel time and the ordered list of landmarks in the shortest path in both `XML`<sup>[17](#glossary-17)</sup> and `JSON`<sup>[16](#glossary-16)</sup> formats.  
- **Design**: Built using C++ for high performance, leveraging lightweight HTTP<sup>[11](#glossary-11)</sup> server libraries such as `Boost.Beast`, `cpp-httplib` or `Pistache`.

#### 4.1.2. Request Handling Layer
- **Purpose**: Parses incoming requests, validates inputs, and routes them to the appropriate modules.  
- **Error Handling**: Ensures that invalid or incomplete requests return descriptive error messages (e.g., `400 Bad Request`).  
- **Concurrency<sup>[32](#glossary-32)</sup>**: Supports handling multiple requests simultaneously using threading<sup>[42](#glossary-42)</sup> or asynchronous techniques.

#### 4.1.3. Pathfinding<sup>[4](#glossary-4)</sup> Engine
- **Purpose**: Implements the core algorithm for finding the shortest path between two landmarks.  
- **Algorithm**: Utilizes Dijkstra<sup>[5](#glossary-5)</sup>’s or A*<sup>[6](#glossary-6)</sup> algorithm for optimal performance with heuristics<sup>[7](#glossary-7)</sup> to meet the 10% approximation rule.  
- **Data Loading**: Reads the graph<sup>[8](#glossary-8)</sup> data (from `USA-roads.csv`) into memory during initialization to optimize query response times.  
- **Performance Goals**: Ensures responses within 1 second for typical requests.

#### 4.1.4. Data Validation Tool Integration
- **Purpose**: Verifies the integrity of the graph<sup>[8](#glossary-8)</sup> data before it is loaded into memory.  
- **Functionality**: Ensures that the dataset forms a fully connected graph<sup>[8](#glossary-8)</sup> and is free of loops.  
- **Implementation**: Operates as a pre-processing step, run infrequently but essential for ensuring data accuracy.

#### 4.1.5. Security Layer
- **Purpose**: Protects the REST API<sup>[2](#glossary-2)</sup> from unauthorized access.  
- **Implementation**:  
  - API key-based<sup>[21](#glossary-21)</sup> authentication for identifying and authorizing clients.  
  - Input sanitization<sup>[41](#glossary-41)</sup> to prevent injection attacks.  
  - Rate limiting<sup>[35](#glossary-35)</sup> to mitigate DoS (Denial of Service<sup>[52](#glossary-52)</sup>) attacks.

#### 4.1.6. Response Serialization<sup>[39](#glossary-39)</sup>
- **Purpose**: Converts the output of the pathfinding<sup>[4](#glossary-4)</sup> engine into the requested format (XML<sup>[17](#glossary-17)</sup> or JSON<sup>[16](#glossary-16)</sup>).  
- **Design**: Utilizes lightweight serialization<sup>[39](#glossary-39)</sup> libraries to minimize overhead while maintaining compatibility with modern REST standards.

#### 4.1.7. Scalability<sup>[28](#glossary-28)</sup> Design
- **Purpose**: Prepares the backend for increasing traffic and data loads.  
- **Techniques**:  
  - Modular architecture<sup>[43](#glossary-43)</sup> to allow easy scaling of individual components.  
  - Potential integration with a load balancer<sup>[40](#glossary-40)</sup> for distributed deployments in production environments.

#### 4.1.8. Testing and Monitoring
- **Unit Testing<sup>[47](#glossary-47)</sup>**: Comprehensive test suite to validate the correctness of each backend component.  
- **Performance Testing**: Ensures the API meets the 1-second response time requirement under normal conditions.  
- **Logging and Monitoring**: Captures API usage and performance metrics to diagnose issues and optimize performance over time.

### 4.3 Data Structure

The application relies on a **weighted, undirected graph<sup>[8](#glossary-8)</sup>** to model the road network of landmarks and travel times. This graph structure serves as the foundation for implementing efficient pathfinding<sup>[4](#glossary-4)</sup> algorithms and ensuring accurate results within the defined performance constraints.

#### 4.3.1 Graph Characteristics

- **Nodes<sup>[14](#glossary-14)</sup> (Vertices):**  
  Represent landmarks in the road network. Each node<sup>[14](#glossary-14)</sup> is uniquely identified by a landmark ID.

- **Edges<sup>[15](#glossary-15)</sup>:**  
  Represent bidirectional roads connecting two landmarks. Each edge<sup>[15](#glossary-15)</sup> has a weight, which corresponds to the travel time between the two connected landmarks.

- **Weights:**  
  Edge<sup>[15](#glossary-15)</sup> weights are integer values representing travel time in an unspecified unit. Lower weights indicate shorter travel times.

#### 4.3.2 Graph Properties

- **Weighted:**  
  Each edge<sup>[15](#glossary-15)</sup> has a numerical value (weight) representing travel time.

- **Undirected:**  
  Roads are bidirectional. If an edge<sup>[15](#glossary-15)</sup> exists from landmark A to landmark B, the reverse is also true.

- **Cyclic:**  
  The graph<sup>[8](#glossary-8)</sup> inherently contains cycles, as multiple paths often connect landmarks.

- **Sparse Graph:**  
  Since real-world road networks are typically sparse (many fewer edges<sup>[15](#glossary-15)</sup> than the maximum possible), efficient data structures are used to optimize memory and runtime performance.

#### 4.3.3 Data Representation

The graph<sup>[8](#glossary-8)</sup> will be implemented using the following data structures for optimal performance and scalability<sup>[28](#glossary-28)</sup>:

1. **Adjacency List<sup>[29](#glossary-29)</sup>:**  
   - Used for representing the graph<sup>[8](#glossary-8)</sup>. Each node<sup>[14](#glossary-14)</sup> maintains a list of its neighbors and associated weights (travel times).  
   - Efficient for sparse graphs, as it minimizes memory usage.

   **Example:**  
   ```text
    Node A: [(B, 5), (C, 10)]  
    Node B: [(A, 5), (C, 3)]  
    Node C: [(A, 10), (B, 3)]
   ```  
2. **Hash Map<sup>[34](#glossary-34)</sup> for Node<sup>[14](#glossary-14)</sup> Lookup:**
   - A hash map<sup>[34](#glossary-34)</sup> (or dictionary) is used for fast lookup of nodes<sup>[14](#glossary-14)</sup> by their landmark IDs.

   **Example:**
    ```cpp
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
    Priority Queue (for Pathfinding):
    ```

3. **Priority Queue<sup>[30](#glossary-30)</sup> (for Pathfinding<sup>[4](#glossary-4)</sup>):**
   - Utilized in algorithms like Dijkstra<sup>[5](#glossary-5)</sup> or A*<sup>[6](#glossary-6)</sup> to efficiently retrieve the next node<sup>[14](#glossary-14)</sup> with the shortest travel time.
   - Typically implemented as a min-heap.

   **Example:**
    ```cpp
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
    ```
#### 4.3.4 Data Integrity<sup>[33](#glossary-33)</sup> Validation
To ensure the correctness of the graph structure<sup>[8](#glossary-8)</sup>, the following validation steps are performed during the data import phase:

1. **Self-Loop Check:**
   - Ensure no edge<sup>[15](#glossary-15)</sup> connects a node<sup>[14](#glossary-14)</sup> to itself (e.g., `A -> A`).

2. **Duplicate Edge<sup>[15](#glossary-15)</sup> Check:**
   - Verify that no duplicate edges<sup>[15](#glossary-15)</sup> exist between two nodes<sup>[14](#glossary-14)</sup> with differing weights.

3. **Connectivity Check:**
   - Confirm the graph<sup>[8](#glossary-8)</sup> is fully connected, ensuring all nodes<sup>[14](#glossary-14)</sup> are reachable from any other node<sup>[14](#glossary-14)</sup>.

4. **Symmetry Check:**
   - Ensure bidirectionality of all edges<sup>[15](#glossary-15)</sup> (e.g., if `A -> B` exists, `B -> A` must also exist with the same weight).

### 4.3.5 Usage in Pathfinding<sup>[4](#glossary-4)</sup>
The weighted, undirected graph<sup>[8](#glossary-8)</sup> is optimized for algorithms like **Dijkstra<sup>[5](#glossary-5)</sup>** and **A\*<sup>[6](#glossary-6)</sup>** to calculate the shortest path efficiently. These algorithms leverage the adjacency list<sup>[29](#glossary-29)</sup> and priority queue<sup>[30](#glossary-30)</sup> to balance performance and memory usage, ensuring the application meets its response time requirements.


## 5. Development Approach

<br>

### 5.1 Methodology

The project will follow the Agile methodology, with development broken down into sprints. Each sprint will focus on specific features and improvements, allowing for iterative development and continuous feedback.

### 5.2 Tools and Technologies

| Category                            | Tools/Technologies used                                                                                                     |
| ----------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| Data Checking Application           | C<sup>99</sup> to keep a fast runtime but using a mastered language of our software engineer.                               |
| REST API<sup>[2](#glossary-2)</sup> | C++<sup>17</sup> to keep a fast runtime and not using to many unnecessary language keeping the project easily maintainable. |
| Response Format                     | JSON<sup>[16](#glossary-16)</sup> but we want to implement the possibility to get XML<sup>[17](#glossary-17)</sup> also     |
| Version Control                     | Git with GitHub.                                                                                                            |
| CI/CD<sup>[1](#glossary-1)</sup>    | GitHub Actions for continuous integration and deployment.                                                                   |

### 5.3 Libraries used

| C++ Library Name                | Version    | Description                                                                                                     | Links                                                           |
| ------------------------------- | ---------- | --------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| Standard Template Library (STL) | **C++11+** | Provides a collection of generic classes and functions, such as vectors, lists, stacks, queues, and algorithms. | [Reference](https://en.cppreference.com/w/cpp/standard_library) |

<!-- TODO: Add all used C++ libs and add a new table with C libs -->

### 5.4 Software

| Name  | Link                                               |
| ----- | -------------------------------------------------- |
| CMake | [Install](https://cmake.org/download/)             |
| Clang | [Install](https://clang.llvm.org/get_started.html) |

### 5.5 Target

We decided to target the following platforms for compatibility, performance, and user reach:

#### 5.5.1 Desktop Platforms

| Platform    | Supported Versions                             | Rationale                                                                                       |
| ----------- | ---------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| **Linux**   | Distributions with GCC/Clang and C++17 support | Ensures compatibility with the majority of modern Linux distributions.                          |
| **Windows** | Windows 10 and later                           | Covers the largest user base, with extended support for performance and compatibility.          |
| **macOS**   | macOS 14 (Sequoia) and later                   | Targets devices capable of running modern macOS features and supporting your development tools. |

#### 5.5.2 Web Server for REST API<sup>[2](#glossary-2)</sup>

| Server Type                                   | Supported Platforms      | Rationale                                                                                                |
| --------------------------------------------- | ------------------------ | -------------------------------------------------------------------------------------------------------- |
| **HTTP<sup>[11](#glossary-11)</sup> Servers** | Linux, Windows, macOS    | Platform-agnostic<sup>[3](#glossary-3)</sup> support ensures flexibility for deployment and development. |
| **Localhost**                                 | Development environments | Simplifies testing and debugging during the development phase.                                           |

---

### Notes:
1. **macOS Targeting:**  
   - **macOS 14 (Sequoia)** is the primary target version for this project.  
   - **macOS 13 (Ventura)** and **macOS 12 (Monterey)** are supported, systems running earlier versions may still work but are not officially supported.

2. **Cross-Platform<sup>[19](#glossary-19)</sup> Compatibility:**  
   - By leveraging C++ and standardized libraries, the project ensures a seamless experience across major desktop platforms.  
   - The REST API<sup>[2](#glossary-2)</sup> is developed to work with any platform hosting an HTTP<sup>[11](#glossary-11)</sup> server capable of supporting the required runtime.

## 6. Testing

<br>

### 6.1 Testing Strategy

Unit Testing<sup>[47](#glossary-47)</sup>: For individual components and functions.
Integration Testing<sup>[48](#glossary-48)</sup>: To ensure different parts of the application work together.
System Testing<sup>[49](#glossary-49)</sup>: To test the complete system as a whole.

The detailed testing strategy can be seen in the test plan: [HERE](QA/TestPlan.md)

### 6.2 Tools

Unit Testing<sup>[47](#glossary-47)</sup>: Wrote by our Quality Assurance team and ran with googleTest.
CI/CD<sup>[1](#glossary-1)</sup> Testing: Automated testing using GitHub Actions.

## 7. Deployment

<br>

### 7.1 Deployment Pipeline

Staging Environment: For pre-production testing.
Production Environment: For the live application.

### 7.2 Maintenance

Regular updates and bug fixes based on user feedback and performance metrics.

### 8.1 Data Security

Since the application is designed for local use (on a local server), the security measures will primarily focus on securing data in transit and ensuring the proper handling of the dataset. Here's how data security is managed:

- **Encryption:**
  - Communication between the client and server will be done over **HTTP<sup>[11](#glossary-11)</sup>** since the system operates in a localhost environment.
  - Although we will not implement HTTPS or SSL<sup>[12](#glossary-12)</sup> for localhost, it's highly recommended that in production environments (if the project is moved to the internet), **HTTPS** and **SSL<sup>[12](#glossary-12)</sup>/TLS** encryption will be enabled to secure the data transmitted between the client and server.
  - Since the application doesn’t store user data, encryption is not necessary for data at rest. The only data that exists is the CSV<sup>[9](#glossary-9)</sup> file, which is stored on the server.

- **Data Integrity<sup>[33](#glossary-33)</sup>:**
  - We use a **CSV file** as the primary data source (which contains nodes<sup>[14](#glossary-14)</sup> and connections). Data integrity<sup>[33](#glossary-33)</sup> checks can be implemented to ensure that the CSV<sup>[9](#glossary-9)</sup> file is properly formatted and that there are no data inconsistencies.
  - We will validate the CSV<sup>[9](#glossary-9)</sup> file’s integrity before uploading it on the live server to ensure that it is not corrupted, and we will also validate that it meets the expected structure (i.e., a **DAG** with no loops).

- **API Security:**
  - Since we are not implementing a user authentication system (e.g., no login or registration), there is no need to secure API endpoints with authentication tokens for this local version.
  - For security purposes, if this application were to move to a public server or production environment, we would recommend using API tokens or another form of authentication (such as **OAuth<sup>[20](#glossary-20)</sup>** or **Bearer Tokens**) to secure access to the endpoints.

### 8.2 Compliance

- **GDPR (General Data Protection Regulation):**
  - The application does not collect or store personal data from users. As the only data involved is the CSV<sup>[9](#glossary-9)</sup> file, there are no concerns regarding the collection of personal information.
  - Since the CSV<sup>[9](#glossary-9)</sup> file may contain geographic or landmark data, if any sensitive data were to be involved (in future versions), we would ensure compliance with GDPR, including user consent, data deletion, and data protection procedures.

- **Data Breach Notification:**
  - There is no personally identifiable information (PII) being processed or stored in this system. However, if sensitive data were to be added in the future, we would establish a process to notify users in case of any data breaches (as per GDPR guidelines).

- **Other Regulations:**
  - The current version of the system is not handling sensitive personal data, so no other regulations like **HIPAA** or **CCPA** apply. However, should the project evolve to handle user data in the future, compliance with these and other data protection regulations would be enforced.

### 8.3 Security Best Practices

- **CSV File Validation:**
  - We perform data validation checks on the CSV<sup>[9](#glossary-9)</sup> file to ensure that it contains valid and consistent data before it's processed by the application. This step helps prevent errors caused by malformed data.
  - The application will verify that the CSV<sup>[9](#glossary-9)</sup> file adheres to the expected format: **Landmark_A_ID, Landmark_B_ID, Time**. It will also check that the graph<sup>[8](#glossary-8)</sup> is valid, meaning it is a **Directed Acyclic Graph (DAG)** with no loops.

- **Localhost Environment Security:**
  - Since the system is running on localhost, it’s assumed that access is restricted to the local machine or local network.
  - We recommend ensuring that only authorized personnel can access the local server during testing and development. This can be done by restricting server access to local IP addresses (127.0.0.1) and using firewalls if necessary.
  
- **Data Storage:**
  - As the application does not store personal data, no sensitive information needs to be protected. However, for the CSV<sup>[9](#glossary-9)</sup> file stored on the server, it is important to restrict access to prevent unauthorized modifications to the file.
  - We recommend using file system permissions to restrict access to the server where the CSV<sup>[9](#glossary-9)</sup> file is stored.

### 8.4 Secure Development Practices

- **Code Review and Secure Coding:**
  - We follow secure coding practices to prevent vulnerabilities such as buffer overflows<sup>[50](#glossary-50)</sup>, code injection, and other common vulnerabilities. Any code changes are reviewed to ensure adherence to security standards.
  - Proper **input validation** is implemented to prevent issues when processing data from the CSV<sup>[9](#glossary-9)</sup> file.

- **Regular Updates:**
  - We will ensure that the system, especially the server environment, is regularly updated with security patches to minimize the risk of exploits.

- **Environment Configuration:**
  - We ensure that the development and deployment environment is configured securely. Since this application will be running on localhost, it is essential to properly configure any local servers and ensure they are only accessible from authorized machines.


## 9. Glossary

| Id                         | Term                                                                         | Definition                                                                                                                                                                                 |
| -------------------------- | ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| <p id="glossary-1">1</p>   | CI/CD (Continuous Integration/Continuous Deployment)                         | Practices that automate the integration of code changes (CI) and deployment of applications (CD) to ensure reliable, fast software delivery.                                               |
| <p id="glossary-2">2</p>   | REST API (Representational State Transfer Application Programming Interface) | A set of rules for building and interacting with web services that allow clients to communicate with the server over HTTP using methods like GET, POST, PUT, DELETE.                       |
| <p id="glossary-3">3</p>   | Platform agnostic                                                            | Platform agnostic refers to software, applications, or services designed to operate across various operating systems, device types, web browsers, or other foundational technologies.      |
| <p id="glossary-4">4</p>   | Pathfinding                                                                  | Pathfinding refers to the process of finding the shortest or most efficient route between two points in a map or network.                                                                  |
| <p id="glossary-5">5</p>   | Dijkstra's Algorithm                                                         | A well-known algorithm used to find the shortest paths between nodes in a graph, ensuring that the shortest path is found from a starting node to all other nodes in a weighted graph.     |
| <p id="glossary-6">6</p>   | A* Algorithm                                                                 | An extension of Dijkstra's Algorithm that uses heuristics to improve performance by prioritizing nodes that are more likely to lead to the destination, making it faster for large graphs. |
| <p id="glossary-7">7</p>   | Heuristic                                                                    | A problem-solving approach that uses practical methods or shortcuts to produce a solution that is not guaranteed to be optimal but is sufficient for the immediate goal.                   |
| <p id="glossary-8">8</p>   | Graph Data Structure                                                         | A collection of nodes (or vertices) and edges that connect pairs of nodes, used to represent networks such as road maps, social connections, or communication systems.                     |
| <p id="glossary-9">9</p>   | CSV (Comma-Separated Values)                                                 | A file format used to store tabular data, where each line represents a row, and each value is separated by a comma.                                                                        |
| <p id="glossary-10">10</p> | Mermaid                                                                      | JavaScript based diagramming and charting tool that renders Markdown-inspired text definitions to create and modify diagrams dynamically.                                                  |
| <p id="glossary-11">11</p> | HTTP (Hypertext Transfer Protocol)                                           | A protocol used for transferring data over the web, enabling the communication between a client (such as a web browser) and a server.                                                      |
| <p id="glossary-12">12</p> | SSL (Secure Sockets Layer)                                                   | A security protocol that establishes an encrypted link between a web server and a browser, ensuring secure data transfer over the internet.                                                |
| <p id="glossary-13">13</p> | Time Complexity (O(log n))                                                   | A way of expressing the efficiency of an algorithm, indicating how the time to run the algorithm increases as the size of the input grows.                                                 |
| <p id="glossary-14">14</p> | Node                                                                         | A fundamental unit in a graph, typically representing an entity, such as a location in a pathfinding algorithm.                                                                            |
| <p id="glossary-15">15</p> | Edge                                                                         | A connection between two nodes in a graph, often with an associated weight that represents the cost or distance between the nodes.                                                         |
| <p id="glossary-16">16</p> | JSON (JavaScript Object Notation)                                            | A lightweight data-interchange format used for transmitting data in a human-readable form, typically between a server and a client.                                                        |
| <p id="glossary-17">17</p> | XML (Extensible Markup Language)                                             | A markup language that defines rules for encoding documents in a format that is both human-readable and machine-readable.                                                                  |
| <p id="glossary-19">19</p> | Cross-Platform                                                               | Refers to software that can run on multiple operating systems, such as Windows, macOS, and Linux.                                                                                          |
| <p id="glossary-20">20</p> | OAuth                                                                        | A protocol for token-based authentication and authorization on the internet, allowing third-party services to exchange web resources on behalf of a user.                                  |
| <p id="glossary-21">21</p> | API Key                                                                      | A unique identifier used to authenticate a client when making API requests, ensuring secure communication between the client and the server.                                               |
| <p id="glossary-23">23</p> | API Documentation                                                            | A reference guide that provides detailed information about an API’s endpoints, parameters, responses, and error codes, aiding developers in using the API.                                 |
| <p id="glossary-24">24</p> | Role-Based Access Control (RBAC)                                             | A method of restricting system access based on the roles assigned to users, ensuring that users have access only to the resources necessary for their roles.                               |
| <p id="glossary-25">25</p> | Euclidean Distance                                                           | The straight-line distance between two points in Euclidean space, often used in pathfinding algorithms as a heuristic.                                                                     |
| <p id="glossary-26">26</p> | Manhattan Distance                                                           | A type of distance measurement used in pathfinding that calculates the distance between two points by only moving along grid lines (i.e., horizontal and vertical).                        |
| <p id="glossary-27">27</p> | Modular Design                                                               | A software design approach that splits a system into separate, self-contained modules, each responsible for a specific functionality, making the system easier to maintain and extend.     |
| <p id="glossary-28">28</p> | Scalability                                                                  | The capability of a system to handle a growing amount of work or to accommodate growth, especially in terms of system capacity, number of users, or data volume.                           |
| <p id="glossary-29">29</p> | Adjacency List                                                               | A way of representing a graph, where each node points to a list of all other nodes it is directly connected to by edges.                                                                   |
| <p id="glossary-30">30</p> | Priority Queue (Min-Heap)                                                    | A data structure that allows efficient retrieval of the element with the highest or lowest priority. A min-heap ensures that the smallest element is always at the top.                    |
| <p id="glossary-32">32</p> | Concurrency                                                                  | The ability of a system to handle multiple tasks or requests at the same time, often used to improve performance in multi-threaded applications.                                           |
| <p id="glossary-33">33</p> | Data Integrity                                                               | The accuracy, consistency, and reliability of data throughout its lifecycle, ensuring that it is not corrupted or altered incorrectly.                                                     |
| <p id="glossary-34">34</p> | Hash Map (Dictionary)                                                        | A data structure that stores key-value pairs, allowing for fast retrieval of values based on their corresponding keys.                                                                     |
| <p id="glossary-35">35</p> | Rate Limiting                                                                | A technique used to control the amount of incoming requests to a system in a given time period, helping to prevent overloads or abuse.                                                     |
| <p id="glossary-39">39</p> | Serialization                                                                | The process of converting an object into a format (like JSON or XML) that can be easily stored or transmitted and later reconstructed.                                                     |
| <p id="glossary-40">40</p> | Load Balancer                                                                | A system or tool used to distribute incoming network traffic across multiple servers, improving performance and reliability.                                                               |
| <p id="glossary-41">41</p> | Input Sanitization                                                           | The process of cleaning user inputs to ensure they do not contain malicious code or invalid data, helping to prevent security vulnerabilities like SQL injection.                          |
| <p id="glossary-42">42</p> | Threading                                                                    | A method of executing multiple parts of a program simultaneously in different threads, helping improve the efficiency and performance of multi-core processors.                            |
| <p id="glossary-43">43</p> | Modular Architecture                                                         | A design approach that divides a system into smaller, self-contained components, making it easier to scale, maintain, and improve individual parts of the system.                          |
| <p id="glossary-47">47</p> | Unit Testing                                                                 | A software testing method where individual components or functions are tested in isolation to verify their correctness.                                                                    |
| <p id="glossary-48">48</p> | Integration Testing                                                          | Testing the combination of multiple components of the system to ensure they work together as expected.                                                                                     |
| <p id="glossary-49">49</p> | System Testing                                                               | Testing the complete and integrated system to verify that it functions as a whole and meets the project requirements.                                                                      |
| <p id="glossary-50">50</p> | Buffer Overflow                                                              | A situation where a program writes more data to a buffer than it can hold, potentially leading to unexpected behavior or security vulnerabilities.                                         |
| <p id="glossary-52">52</p> | Denial of Service (DoS) Attacks                                              | A type of cyberattack where the attacker attempts to make a machine or network resource unavailable to its intended users by overwhelming it with requests.                                |


<!-- LINKS -->
[1]: https://en.wikipedia.org/wiki/C%2B%2B "C++ Wikipedia"
[2]: https://en.wikipedia.org/wiki/C_(programming_language) "C Wikipedia"
[3]: https://www.youtube.com/watch?v=tas0O586t80 "Program in C"
[4]: https://en.wikipedia.org/wiki/JSON "JSON Wikipedia"
[5]: https://en.wikipedia.org/wiki/XML "XML Wikipedia"