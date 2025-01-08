#  **Functional Specifications - 2024-2025-project-3-quickest-path-team-5**

---

| Role | Name |
|---|---|
| Project Manager       | Habi CAILLEAU       |
| Program Manager       | Robin GOUMY         |
| Tech Lead             | Mathias GAGNEPAIN   |
| Software Developer    | Rémy CHARLES        |
| Software Developer    | Maxime Caron        |
| Quality Assurance     | Jason GROSSO        |
| Technical Writer      | Alexandre BOPP      |

---

### *Last Update on January 8th, 2025*


<details>

<summary>Table of Contents</summary>

- [**Functional Specifications - 2024-2025-project-3-quickest-path-team-5**](#functional-specifications---2024-2025-project-3-quickest-path-team-5)
    - [*Last Update on January 8th, 2025*](#last-update-on-january-8th-2025)
- [Introduction](#introduction)
  - [Document Purpose](#document-purpose)
  - [Project Goal](#project-goal)
  - [Project Rules](#project-rules)
  - [Glossary](#glossary)
- [Requirements](#requirements)
  - [Core Requirements](#core-requirements)
    - [Performance Goals](#performance-goals)
    - [Data Integrity Verification](#data-integrity-verification)
    - [Deliverables](#deliverables)
- [Non-Functional Requirements](#non-functional-requirements)
  - [Costs](#costs)
- [Assumptions and Constraints](#assumptions-and-constraints)
- [Product](#product)
- [Description](#description)
  - [Input](#input)
  - [Output](#output)
  - [Algorithm](#algorithm)
  - [Compatibility](#compatibility)
  - [Interface](#interface)
    - [Mandatory features](#mandatory-features)
    - [Optional features](#optional-features)
  - [Acceptance Criteria](#acceptance-criteria)
  - [Personnas](#personnas)
  - [Use Cases](#use-cases)
- [Risk](#risk)
  - [Competitive Landscape](#competitive-landscape)
  - [Product problem](#product-problem)
  - [Data](#data)
  - [Risk Management Plan](#risk-management-plan)


</details>


--- 

# Introduction 

## Document Purpose

The aim of this document is to describe in detail the functionalities and expected behavior of the software, to ensure a common understanding between all stakeholders (all team members, customers, and others).
  

## Project Goal 

The aim of the project is to create an high-performance software solution that calculates the quickest path between two landmarks in the United States. 

## Project Rules 

As defined by the project owner, the team is arranged as follows:

| Role               | Description                                                                                     |
|--------------------|-------------------------------------------------------------------------------------------------|
| **Project Manager**  | Responsible for organization, planning, and budgeting.<br>Keeps the team motivated.            |
| **Program Manager**  | Ensures the project meets expectations.<br>In charge of design.<br>Writes the Functional Specifications. |
| **Tech Lead**        | Makes technical decisions for the project.<br>Translates Functional Specifications into Technical Specifications.<br>Performs code reviews. |
| **Software Engineer**| Writes code.<br>Creates documentation.<br>Participates in technical design.                   |
| **Quality Assurance**| Tests all functionalities to identify bugs and issues.<br>Documents bugs and issues.<br>Writes the test plan.<br>Verifies fixes are implemented correctly. |


## Glossary
| Term               | Definition                                                                                       |
|--------------------|-------------------------------------------------------------------------------------------------|
| **Algorithm**      | A step-by-step procedure for solving a problem or performing a task.                            |
| **API**            | Application Programming Interface: A set of tools and protocols for building and interacting with software. |
| **Big O**          | A notation describing the performance or complexity of an algorithm in terms of input size.     |
| **C++**            | A high-performance programming language used for system/software development.                    |
| **CSV**            | Comma-Separated Values: A simple file format used to store tabular data, like a spreadsheet or database. |
| **DAG**            | Directed Acyclic Graph: A graph structure with directed edges and no cycles, often used in workflows. |
| **Data Structure** | A way to organize, manage, and store data for efficient access and modification.                |
| **Frameworks**     | Predefined structures or libraries that simplify software development by providing reusable code. |
| **Graph**          | A mathematical structure used to model relationships between entities (nodes and edges).         |
| **Heuristics**     | Problem-solving techniques using practical methods to find approximate solutions efficiently.    |
| **Localhost**      | Refers to the computer or server being used, commonly associated with `127.0.0.1`.               |
| **REST**           | Representational State Transfer: An architectural style for designing networked applications using stateless communication. |

--- 


# Requirements
The requirements are the conditions that must be fulfilled to meet the school's objectives. These represent the core functionalities we need to implement before the deadline. Any additional features developed beyond these requirements will be considered a bonus and add extra value to our work.
## Core Requirements
| **Section**               | **Details**                                                                                 |
|---------------------------|---------------------------------------------------------------------------------------------|
| **Programming Language**  | The programming language that we must use is C++ to achieve optimal performance.            |
| **REST API Specification**| The software will expose its functionality through a REST API that must run on an HTTP server (localhost). |
| **Data Source**           | A document has been given by the customer. This file contains approximately 24 million nodes. This is the base of our software to develop the quickest path possible in this node. |
| **C++ Source Code**            | The source code must include comments and clear documentation. The code must be of our own creation and use no libraries besides STL. This is necessary for the web server. |
| **Time and Space Complexity**  | We must use Big O notation for the main algorithms.                                                                     |
| **REST API Implementation**    | Our REST API must be compatible with multiple formats like XML and JSON.                                                |
| **Test Suite**                 | We must test our code to validate correctness, performance, and compliance with the approximation rule of 10%.          |
| **Data Validation Tool**       | We need a utility to check the integrity of the CSV file supplied.                                                      |
### Performance Goals
| **Section**        | **Details**                                                                                                        |
|-------------------------------|--------------------------------------------------------------------------------------------------------------------|
| **Response Time**             | The API must handle all queries within 1 second on a typical laptop.                                               |
| **Approximation Heuristics**  | To prioritize speed over precision, the solution may use heuristics. The returned path should not exceed the shortest path duration by more than 10%. |
### Data Integrity Verification
| **Section** | **Details**                                                                                                       |
|----------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **Graph Validation**             | We need to verify that the file forms a Directed Acyclic Graph (DAG) and is free of loops.                        |
| **Connectivity**                 | We need to ensure that the graph is fully connected, meaning it is possible to navigate between any two landmarks. |
| **Programming Language**         | Another language besides C++ is acceptable if it is more convenient for these parts.                             |
### Deliverables

For this project all the deadlines for the customer are February 7th 2025. But our Project Manager decided to impose his own deadlines. 

| Name | Deadline | Link |
| --  | -- | -- |
| Functional Specifications Document  | 20/01/2025 | [functionalSpecifications.md](needs to be updated) |
| Technical Specifications Document  | 27/01/2024 | [technicalSpecifications.md](needs to be updated) |
| Code | 07/01/2025  | [code](needs to be updated) |
| Test Plan | 07/01/2025 | [qualityAssurance/Test-Plan.md](needs to be updated) | 
| User Manual | 07/01/2025 | [User-Manual](needs to be updated) | 

---

# Non-Functional Requirements

## Costs

| Product | Price | Link |
| --  | -- | -- |
|   |  | |
|   |  | |
|   |  | |


--- 

# Assumptions and Constraints

- Internet connection



---
# Product

# Description 

## Input 

The Client sent us a list of landmarks, tesource and the destination in a CSV file. This one represent 24 million nodes. 

This file is the input of our algorithm. The goal is to classify all this data to finaly find the quickest path.  

The CSV file looks like this : 

![alt text](/documents/functional_specifications/images/CSV_USA.png)


The third information is the time, this is an important data to the algorithm, essential to find the quickest path.

## Output 

The result of our algorithm should be the ordered list of landmarks on the path and the travel time for each of them.

## Algorithm

We plan to use the C++ algorithm for its optimal performance in terms of speed and accuracy.

...............


## Compatibility

The XML and JSON file are two commonly used formats for structuring and exchanging data, each with its own advantages and disadvantages. Here's a comparison of the two formats.




## Interface 


### Mandatory features




### Optional features



## Acceptance Criteria

| **Criterion**           | **Description**                                                    |
|-------------------------|--------------------------------------------------------------------|
| Response time           | The API must respond in less than 1 second for all requests.       |
| Result accuracy         | The calculated path should not exceed a 10% approximation.         |
| Robustness              | The API must continue to function under simultaneous requests.     |


--- 

## Personnas

## Use Cases

| **User**             | **Action**                                      | **Expected Result**                       |
|----------------------|-------------------------------------------------|-------------------------------------------|
| Individual Customer  | Find the shortest path between two cities       | A list of steps with estimated time.      |
| Logistics Company    | Plan a route for multiple vehicles              | An optimized schedule per vehicle.        |


--- 

# Risk

## Competitive Landscape

Today's market is highly competitive, with many powerful and advanced companies : 

- **Google Maps Platform**: Offers precise, real-time route optimization for various transportation modes. Strong integration with Google services but costly for smaller businesses.  
- **Mapbox**: Known for customization and flexibility, popular with developers. Limited advanced features compared to Google.  
- **OpenStreetMap (OSM)**: A free, community-driven option with customizable tools like OSRM. Less precise in certain areas.

## Product problem

In any project, no issue should ever be taken lightly, as even seemingly minor problems can lead to significant time losses and disrupt progress. It is essential to approach every detail with attention and care to minimize risks and ensure a smooth workflow. Proactive problem-solving and vigilance are key to avoiding unnecessary setbacks and maintaining the project's momentum.

## Data 



Compliance with the General Data Protection Regulation (GDPR) is crucial in developing software that interacts with users, ensuring personal data protection and privacy. By adhering to these standards, developers not only ensure legal compliance but also build user trust. The GDPR requires transparent data collection, storage, and processing practices, giving users control over their personal information, which is essential for the acceptance of digital technologies.

To kown more about it : [RGPD License](https://en.wikipedia.org/wiki/General_Data_Protection_Regulation)



## Risk Management Plan

| **Risk**                 | **Impact**        | **Probability** | **Mitigation Plan**                                     |
|--------------------------|-------------------|-----------------|---------------------------------------------------------|
| Insufficient performance | Project failure   | Medium          | Optimize the data structures used.                      |
| Critical bugs            | Delays            | High            | Implement a rigorous test strategy with the team member in charge of Quality Assurance.            |
| Organizational issues    | Delays            | Medium          | Hold weekly meetings to monitor progress.               |

---






