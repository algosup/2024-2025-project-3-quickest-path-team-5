<div align="center">

---

# Project Charter Team 5 - Quickest Path

## Document Information

| Description    | Information   |
| -------------- | ------------- |
| Document Owner | Habi CAILLEAU |
| Creation Date  | 06/01/2025    |
| Last Update    | 06/01/2025    |

<br>



## Team

| Picture                                                                                    | Name              | Role                |
| ------------------------------------------------------------------------------------------ | ----------------- | ------------------- |
| <img src="https://avatars.githubusercontent.com/u/145991425?v=4" width="100" height="100"> | Habi CAILLEAU     | Project Manager     |
| <img src="https://avatars.githubusercontent.com/u/182214449?v=4" width="100" height="100"> | Robin GOUMY       | Program Manager     |
| <img src="https://avatars.githubusercontent.com/u/145995367?v=4" width="100" height="100"> | Mathias GAGNEPAIN | Technical Leader    |
| <img src="https://avatars.githubusercontent.com/u/100137905?v=4" width="100" height="100"> | Rémy CHARLES      | Software Engineer 1 |
| <img src="https://avatars.githubusercontent.com/u/145995231?v=4" width="100" height="100"> | Maxime CARON      | Software Engineer 2 |
| <img src="https://avatars.githubusercontent.com/u/114397870?v=4" width="100" height="100"> | Jason GROSSO      | Quality Assurance   |
| <img src="https://avatars.githubusercontent.com/u/123485791?v=4" width="100" height="100"> | Alexandre BOPP    | Technical Writer    |

<br>


## Document Approval

| Role                | Date(DD/MM/YYYY) | Approval |
| ------------------- | ---------------- | -------- |
| Project Manager     | 08/01/2025       |    ✅    |
| Program Manager     | 08/01/2025       |          |
| Technical Leader    | 08/01/2025       |          |
| Software Engineer 1 | 08/01/2025       |          |
| Software Engineer 2 | 08/01/2025       |          |
| Technical Writer    | 08/01/2025       |          |
| Quality Assurance   | 08/01/2025       |    ✅    |

--- 

</div>


<details>
<summary><b>Table of contents</b></summary>

- [Project Charter Team 5 - Quickest Path](#project-charter-team-5---quickest-path)
  - [Document Information](#document-information)
  - [Team](#team)
  - [Document Approval](#document-approval)
  - [Overview](#overview)
    - [Project Overview](#project-overview)
  - [Stakeholders](#stakeholders)
  - [Milestones](#milestones)
  - [Scope](#scope)
    - [Project Goals](#project-goals)
    - [Core Requirements](#core-requirements)
  - [Project Limitations](#project-limitations)
    - [Constraints](#constraints)
    - [Risks and Mitigation Strategies](#risks-and-mitigation-strategies)
  - [Budget Allocation](#budget-allocation)
    - [Glossary](#glossary)

</details>



## Overview

### Project Overview

The 2024-2025 Project 3 aims to develop a high-performance software solution for calculating the quickest travel path between two landmarks within the United States. This project focuses on creating an efficient and scalable REST API capable of handling large datasets to deliver near-optimal routing results in minimal time. By leveraging C++ for its performance benefits, the project will balance speed and accuracy to meet real-world constraints.

<br>

## Stakeholders

| Name    | Role        | Represented By | Contact                    | Expectation                                                     |
| ------- | ----------- | -------------- | -------------------------- | --------------------------------------------------------------- |
| ALGOSUP | Third-party | Franck JEANNIN | franck.jeannin@algosup.com | The third-party expect us to develop the Quickest-Path project. |

<br>

## Milestones

Here are the milestones of the project defined by the project manager in order to maintain organization and logic among the team :

| Deliverable              | Description                                                                                                                       | Deadline(DD/MM/YYYY) |
| ------------------------ | --------------------------------------------------------------------------------------------------------------------------------- | -------------------- |
| Functional Specification | A document that explains all the functional requirements of software.                                                             | 20/01/2025           |
| Technical Specification  | A document that explains all the technical requirements of the software.                                                          | 27/01/2025           |
| Test Plan                | A document that explains how and when the software will be tested. All the test cases will be available in this document.         | 07/02/2025           |
| Code                     | The source code of the software.                                                                                                  | 07/02/2025           |
| User Manual              | A document made for the end user that will explains how to use our software and also all the information they need to know about. | 07/02/2025           |


The end of the project is scheduled for 02/14/2025. We will present the final product this day.

<br>

## Scope

### Project Goals

- **Performance and efficiency:** Develop a solution that computes travel paths within 1 second on standard hardware, adhering to strict performance benchmarks.

- **Scalability:** design the software to handle a dataset of 24 million nodes efficiently.

- **Accuracy with heuristics:** Implement approximation algorithms that ensure results are within 10% of the shortest possible path.

- **Robust REST API:** Provide a REST API supporting both JSON and XML response formats to maximize usability and integration flexibility.

- **Data integrity validation:** Implement tools to validate data quality, ensuring a fully connected and loop-free graph.

- **Maintainability:** Deliver well-documented C++ source code following best practices to facilitate future updates and enhancements.
  
<br>

### Core Requirements 

- Use C++ for the main implementation.

- Expose functionality through a REST API with a GET endpoint.

- Ensure data integrity and connectivity of the graph.

- Deliver key performance metrics, test suites, and a validation utility.


<br>

## Project Limitations

### Constraints


- **Programming Language Restriction:** The core implementation must be in C++.

- **Library Usage:** Only STL and necessary libraries for the web server are allowed.

- **Heuristic Approximation Limit:** Pathfinding results must not exceed 10% of the shortest path duration.

- **Performance Limitations:** The solution must handle requests within 1 second on typical hardware.

- **Data Input Format:** The provided data is a CSV file with specific structure (Landmark_A_ID, Landmark_B_ID, Time).

- **Bidirectional Connectivity Assumption:** Each road connection listed implies a reverse connection.

- **Algorithm Flexibility for Validation:** Simpler algorithms are permitted for infrequent data integrity checks, even if less efficient.

<br>

### Risks and Mitigation Strategies

| Risk                                                 | Importance | Mitigation Strategy                                                                                            |
| ---------------------------------------------------- | ---------- | -------------------------------------------------------------------------------------------------------------- |
| **Performance issues leading to slow API responses** | High       | Use efficient data structures and algorithms, profile code regularly, and optimize hotspots to maintain speed. |
| **Data integrity errors in the provided CSV file**   | High       | Implement comprehensive validation tools to check for loops and connectivity before using the data.            |
| **Inaccuracy exceeding the 10% approximation limit** | Medium     | Use advanced heuristics and tune algorithms to balance speed and accuracy effectively.                         |
| **Unhandled API errors or malformed input**          | Medium     | Implement robust error handling and input validation to ensure API stability and correct responses.            |
| **Difficulty in handling large datasets**            | High       | Apply memory-efficient algorithms and techniques to manage resources.                                          |
| **Limited team expertise in C++**                    | Medium     | Provide training resources, share best practices, and conduct regular code reviews to enhance code quality.    |

<br>

## Budget Allocation
There is no budget allocated for this project. All resources, including software licenses and graphic assets, will be obtained for free.

<br>

### Glossary

| Term                                        | Definition                                                                                                                     |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| **API (Application Programming Interface)** | A set of rules that allows different software components to communicate with each other, typically through defined endpoints.  |
| **CSV (Comma-Separated Values)**            | A file format used to store tabular data, where each line represents a data record, and fields are separated by commas.        |
| **Endpoint**                                | A specific URL or path in an API where a certain functionality is exposed for external use.                                    |
| **Heuristic**                               | An approach or method designed to solve a problem more quickly when classic methods are too slow, trading precision for speed. |
| **REST API**                                | An architectural style for creating web services that use HTTP requests to access and manipulate data.                         |
| **STL (Standard Template Library)**         | A collection of C++ template classes and algorithms that provide common data structures like vectors, stacks, and queues.      |
| **XML (eXtensible Markup Language)**        | A markup language used for encoding documents in a format that both humans and machines can read.                              |
| **Data Validation**                         | The process of ensuring that data is accurate, complete, and free from errors before processing.                               |
| **Big O Notation**                          | A mathematical notation used to describe the time or space complexity of an algorithm relative to its input size.              |
| **Test Suite**                              | A collection of tests designed to validate the functionality and performance of software against its requirements.             |