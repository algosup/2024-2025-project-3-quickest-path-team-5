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
- [New version](#new-version)
  - [Glossary](#glossary-1)
    - [Additional Terms](#additional-terms)
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

# New version 

## Glossary  
| **Term**           | **Definition**                                                                                   |  
|--------------------|--------------------------------------------------------------------------------------------------|  
| **API**            | **Application Programming Interface**: APIs are a set of functions and procedures that allow for the creation of applications. |  
| **REST**           | **Representational State Transfer**: A software architecture style, where communication is stateless and resources are accessible via standard HTTP methods like GET, POST, etc. |  
| **Graph**          | A collection of nodes (landmarks) connected by edges (paths), used to represent relationships or routes. |  
| **C++**            | High-performance **programming language**, a generic programming language for building software . |  
| **Localhost**      | Refers to the computer running the software; typically used to test web servers or applications locally. |  
| **Heuristics**     | **Problem-solving techniques** that prioritize speed over precision by using approximations. Commonly used to make algorithms faster. |  
| **CSV**            | **Comma-Separated Values**: A file format where data is stored in a plain text file with values separated by commas. |  
| **Algorithm**      | A step-by-step procedure or formula for solving a problem, such as finding the shortest path in a graph. |  
| **Frameworks**     | **Prebuilt tools** or libraries, like Flask or FastAPI, that simplify application development. Not allowed for the REST API in this project. |  
| **DAG**            | **Directed Acyclic Graph**: A graph with directed edges (one-way paths) and no cycles (no path loops back to its start). |  

### Additional Terms
| **Term**           | **Definition**                                                                                   |  
|--------------------|--------------------------------------------------------------------------------------------------|  
| **Shortest Path**  | The minimum travel time or cost between two nodes in a graph.                                     |  
| **Data Structures**| Ways to organize and store data, such as adjacency lists, which are often used to represent graphs. |  


--- 

# Requirements 

The requirements are the conditions that must be fulfilled to meet the school's objectives. These represent the core functionalities we need to implement before the deadline. Any additional features developed beyond these requirements will be considered a bonus and add extra value to our work.

## Core Requirements

<table> 
  <thead> 
    <tr> 
      <th>Category</th> 
      <th>Details</th> 
    </tr> 
  </thead> 
  <tbody> 
    <tr> 
      <td><strong>Programming Language</strong></td> 
      <td>The project must be implemented in <strong>C++</strong> to achieve optimal performance.</td>
    </tr> 
    <tr> 
      <td rowspan="4"><strong>REST API</strong></td>
      <td>A REST API must be developed to expose the software's functionality via an HTTP server (localhost).</td>
    </tr> 
    <tr> 
      <td><strong>Endpoint:</strong> A single GET request to calculate the quickest path.</td>
    </tr> 
    <tr> 
      <td><strong>Input:</strong> Source and destination landmark IDs.</td>
    </tr>
    <tr> 
      <td><strong>Output:</strong> Ordered list of landmarks in the path and total travel time. <br> <strong>Response Formats:</strong> Support both <strong>JSON</strong> and <strong>XML</strong>.</td>
    </tr>
    <tr>
      <td><strong>Data Source</strong></td>
      <td> The provided dataset (<code>USA-roads.csv</code>) contains ~24 million nodes. This serves as the foundation for computing paths.<br> <ul> <li><strong>Format:</strong> Each line represents a connection: <code>Landmark_A_ID, Landmark_B_ID, Time</code>.</li> <li>Connections are <strong>bidirectional</strong> even if not explicitly listed in the file.</li> </ul> </td>
    </tr>
    <tr>
      <td><strong>Source Code</strong></td>
      <td>The C++ source code must include <strong>comments</strong> and <strong>clear documentation</strong>. Only <strong>STL libraries</strong> and those required for the web server may be used.</td>
    </tr>
    <tr>
      <td><strong>Algorithm Complexity</strong></td> 
      <td>Use <strong>Big O notation</strong> to document the time and space complexity of key algorithms.</td>
    </tr>
    <tr> 
      <td><strong>Test Suite</strong></td>
      <td> A comprehensive test suite is required to validate: <ul> <li>Correctness of outputs.</li> <li>Compliance with the <strong>10% approximation rule</strong>.</li> <li>General performance goals.</li> </ul> </td>
    </tr>
    <tr> 
      <td><strong>Data Validation Tool</strong></td> 
      <td>A utility must verify the integrity of the dataset before use, ensuring its structure and validity.</td>
    </tr>
  </tbody>
</table>


### Performance Goals

<table> 
  <thead> 
    <tr> 
      <th>Category</th>
      <th>Details</th> 
    </tr> 
  </thead> 
  <tbody> 
    <tr> 
      <td><strong>Response Time</strong></td> 
      <td>The API must respond to all queries within <strong>1 second</strong> on a typical laptop.</td> 
    </tr> 
    <tr> 
      <td><strong>Accuracy</strong></td> 
      <td> The algorithm may prioritize <strong>speed over precision</strong> by using heuristics. <br> <strong>Rule:</strong> The returned path should not exceed the shortest path duration by more than <strong>10%</strong>. 
      </td>
    </tr> 
  </tbody> 
</table>


### Data Integrity Verification                           

<table> 
  <thead> 
    <tr> 
      <th>Category</th> 
      <th>Details</th> 
    </tr> 
  </thead> 
  <tbody> 
    <tr> 
      <td><strong>Graph Validation</strong></td> 
      <td>Validate that the dataset forms a <strong>Directed Acyclic Graph (DAG)</strong> and is free of loops.</td> 
    </tr> 
    <tr> 
      <td><strong>Connectivity Check</strong></td> 
      <td>Ensure the graph is <strong>fully connected</strong>, allowing navigation between any two landmarks.</td>
    </tr> 
    <tr>
      <td><strong>Programming Language Flexibility</strong></td> 
      <td>A language other than C++ may be used for this validation, as performance is not critical in these tasks.</td> 
    </tr>
  </tbody> 
</table>


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

This project involves developing a software solution in C++ to determine the quickest path between two landmarks in the United States, such as Los Angeles and New York. The goal is to design an algorithm capable of calculating the optimal route efficiently, ensuring results are delivered in under one second.

Users simply provide the IDs of two landmarks as input, and the software calculates and returns the quickest path, including travel time and an ordered list of landmarks along the route. Unlike a GPS, this software does not track real-time location but focuses on providing pre-calculated routes between fixed landmarks.



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