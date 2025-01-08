#  **Functional Specifications - 2024-2025-project-3-quickest-path-team-5**

---

| Role | Name | Profiles
|---|---|---|
| Project Manager       | Habi CAILLEAU       |
| Program Manager       | Robin GOUMY         |
| Tech Lead             | Mathias GAGNEPAIN   |
| Software Developer    | Rémy CHARLES        |
| Software Developer    | Maxime Caron        |
| Quality Assurance     | Jason GROSSO        |
| Technical Writer      | Alexandre BOPP      |

---

### *Last Update on January 6th, 2025*


<details>

<summary>Table of Contents</summary>

- [**Functional Specifications - 2024-2025-project-3-quickest-path-team-5**](#functional-specifications---2024-2025-project-3-quickest-path-team-5)
    - [*Last Update on January 6th, 2025*](#last-update-on-january-6th-2025)
- [Introduction](#introduction)
  - [Document Purpose](#document-purpose)
  - [Project Goal](#project-goal)
  - [Glossary](#glossary)
- [Requirements](#requirements)
  - [Core Requirements](#core-requirements)
    - [Performance Goals](#performance-goals)
    - [Data Integrity Verification](#data-integrity-verification)
    - [Deliverables](#deliverables)
- [Description](#description)
  - [Interface](#interface)
  - [Input](#input)
  - [Output](#output)
  - [Compatibilty](#compatibilty)
  - [Interface ?](#interface-)
  - [Materials ?](#materials-)
  - [Personas definition](#personas-definition)
  - [Use Cases](#use-cases)


</details>


--- 

# Introduction 



## Document Purpose

The aim of this document is to describe in detail the functionalities and expected behavior of the software, to ensure a common understanding between all stakeholders (all team members, customers, and others).
  

## Project Goal 

The aim of the project is to create an high-performance software solution that calculates the quickest path 
between two landmarks in the United States. 

## Glossary
| Term               | Definition  |
|--------------------|-------------|
| **API**          | |
| **REST**          | |
| **Graph**          | |
| **C++**          | |
| **Localhost**          | |
| **Heuristics**          | |
| **CSV**          | |
| **Algorithm**          | |
| **Frameworks**          | |
| **DAG**          | |

REST API: Representational State Transfer Application Programming Interface.

CSV: Comma-Separated Values file format.

Shortest Path: The minimum distance or cost between two nodes in a graph.

Frameworks: Flask, FastAPI, etc.

Data Structures: Graph representation, adjacency lists.

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
| Functional Specifications Document  | 20/01/2025 | [functionalSpecifications.md](need to be update) |
| Technical Specifications Document  | 27/01/2024 | [technicalSpecifications.md](need to be update) |
| Code | 07/01/2025  | [code](need to be update) |
| Test Plan | 07/01/2025 | [qualityAssurance/Test-Plan.md](need to be update) | 
| User Manual | 07/01/2025 | [User-Manual](need to be update) | 

---

# Description 

## Interface 

## Input 

## Output 

##  Compatibilty



---

## Interface ? 
## Materials ? 


## Personas definition 

<table>
  <thead>
    <tr>
      <th><strong>Picture</strong></th>
      <th><strong>Attribute</strong></th>
      <th><strong>Details</strong></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="7">
        <img src="https://t4.ftcdn.net/jpg/03/96/16/79/360_F_396167959_aAhZiGlJoeXOBHivMvaO0Aloxvhg3eVT.jpg" alt="Traveler Tom" width="350" height="250" style="object-fit: cover;" />
      </td>
      <td><strong>Name</strong></td>
      <td>Tom Smith</td>
    </tr>
    <tr>
      <td><strong>Age</strong></td>
      <td>30 - 40</td>
    </tr>
    <tr>
      <td><strong>Occupation</strong></td>
      <td>Business Traveler</td>
    </tr>
    <tr>
      <td><strong>Skills</strong></td>
      <td>Basic tech skills, regularly uses navigation apps</td>
    </tr>
    <tr>
      <td><strong>Usage Scenario</strong></td>
      <td>Tom opens the app to calculate the quickest route between New York and Los Angeles, seeking the shortest travel time while avoiding delays. He can then report the results to his company to calculate kilometers traveled and receive a gas reimbursement.</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th><strong>Picture</strong></th>
      <th><strong>Attribute</strong></th>
      <th><strong>Details</strong></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="7">
        <img src="https://images.pexels.com/photos/1239291/pexels-photo-1239291.jpeg?cs=srgb&dl=pexels-danxavier-1239291.jpg&fm=jpg" alt="Traveler Sarah" width="400" height="250" style="object-fit: cover;"/>
      </td>
      <td><strong>Name</strong></td>
      <td>Sarah Johnson</td>
    </tr>
    <tr>
      <td><strong>Age</strong></td>
      <td>25 - 35</td>
    </tr>
    <tr>
      <td><strong>Occupation</strong></td>
      <td>Delivery Planning Manager</td>
    </tr>
    <tr>
      <td><strong>Skills</strong></td>
      <td>Project management, logistics coordination, team leadership, data analysis</td>
    </tr>
    <tr>
      <td><strong>Usage Scenario</strong></td>
      <td>Sarah uses the app to plan the most efficient delivery routes for her team's drivers. She needs to calculate the fastest routes, avoid traffic, and ensure that deliveries are made on time. Additionally, Sarah tracks delivery times and distances for reporting to her logistics department and calculating transportation costs.</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th><strong>Picture</strong></th>
      <th><strong>Attribute</strong></th>
      <th><strong>Details</strong></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="7">
        <img src="https://t4.ftcdn.net/jpg/05/99/07/69/360_F_599076934_L4nJ7MWjLgvmLUUXD6Y5VSFvQEFPSv6c.jpg" alt="Vacation Planner Lucy" width="300" height="250" style="object-fit: cover;" />
      </td>
      <td><strong>Name</strong></td>
      <td>Lucy Martinez</td>
    </tr>
    <tr>
      <td><strong>Age</strong></td>
      <td>60 - 80</td>
    </tr>
    <tr>
      <td><strong>Occupation</strong></td>
      <td>Retired</td>
    </tr>
    <tr>
      <td><strong>Skills</strong></td>
      <td>Researching destinations, budgeting, planning activities, travel booking</td>
    </tr>
    <tr>
      <td><strong>Usage Scenario</strong></td>
      <td>Lucy uses the app to plan her upcoming vacation. She is looking for the best path to her destination, avoiding long drives. She also needs to calculate trip costs, including transportation, to stay within her budget.</td>
    </tr>
  </tbody>
</table>




## Use Cases

| **User**             | **Action**                                      | **Expected Result**                       |
|----------------------|-------------------------------------------------|-------------------------------------------|
| Individual Customer  | Find the shortest path between two cities       | A list of steps with estimated time.      |
| Logistics Company    | Plan a route for multiple vehicles              | An optimized schedule per vehicle.        |