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
          - [Zig Naming](#zig-naming)
          - [C++ Naming](#c-naming)
  - [2. System Requirements](#2-system-requirements)
    - [2.1 Functional Requirements](#21-functional-requirements)
      - [2.1.1 Data Checker](#211-data-checker)
      - [2.1.2 REST API](#212-rest-api)
    - [2.2 Non-Functional Requirements](#22-non-functional-requirements)
      - [2.2.1 Data Checker](#221-data-checker)
      - [2.2.2 REST API](#222-rest-api)
  - [3. System Architecture](#3-system-architecture)
    - [3.1 Overview](#31-overview)
    - [3.1 Overview](#31-overview-1)
      - [**Key Design Considerations**](#key-design-considerations)
  - [Data Checking](#data-checking)
  - [Data Structure](#data-structure)
  - [Quick Path Algorithm](#quick-path-algorithm)
  - [API Implementation](#api-implementation)
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
   - **Technology:** Developed in [Zig][2]
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

###### Zig Naming
<hr>

| Type     | Convention |
| -------- | ---------- |
| `Variable` | snake_case |
| `Function` | camelCase  |
| `Type`     | camelCase  |

###### C++ Naming
<hr>

| Type     | Convention |
| -------- | ---------- |
| `Variable` | camelCase |
| `Constants` | UPPER_SNAKE_CASE |
| `Function` | camelCase  |
| `Class`     | PascalCase  |

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

The system architecture is designed to ensure a seamless and efficient user experience across all platforms. It comprises the following components:

Desktop Application (Data Checker): Developed using Zing for compatibility across Linux, Windows, and MacOS.
REST API: Developed using C++ for platform agnostic
Authentication Service: 


### 3.1 Overview  

The system architecture is designed to ensure seamless functionality, high performance, and a user-friendly experience across all supported platforms. It consists of the following key components:   

- **Desktop Application (Data Checker)**  
  - **Technology**: Developed using [Zig][2] for its simplicity and performance in handling data integrity checks.  
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

#### **Key Design Considerations**  

- **Modular Design**: Each component is designed to operate independently, ensuring maintainability and ease of updates.  
- **High Performance**: The architecture prioritizes efficiency to handle large datasets and complex computations within the defined performance constraints.  
- **Cross-Platform Support**: Desktop applications and the REST API are built to function seamlessly across Linux, Windows, and macOS.  
- **Extensibility**: The system is designed to accommodate future enhancements, such as adding new endpoints, improving UI/UX, or integrating with external services.  


























<!-- TODO: Rework this section -->


## Data Checking

## Data Structure

## Quick Path Algorithm

## API Implementation

## 5. Development Approach

<br>

### 5.1 Methodology

The project will follow the Agile methodology, with development broken down into sprints. Each sprint will focus on specific features and improvements, allowing for iterative development and continuous feedback.

### 5.2 Tools and Technologies

| Category                            | Tools/Technologies used                                                                                        |
| ----------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| Data Checking Application           | Zig to keep a fast runtime but using a modern approache of C/C++.                                              |
| REST API<sup>[2](#glossary-2)</sup> | C++ to keep a fest runtime and not using to many unnecessary language keeping the project easily maintainable. |
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
[2]: https://ziglang.org/ "Zig Home Page"
[3]: https://www.youtube.com/watch?v=tas0O586t80 "Program in C"
[4]: https://en.wikipedia.org/wiki/JSON "JSON Wikipedia"
[5]: https://en.wikipedia.org/wiki/XML "XML Wikipedia"