#  **Functional Specifications - 2024-2025-project-3-quickest-path-team-5**

<div align="center">

## **Title:** CAP (Cap Api Pathfinder) 


![alt text](images/logo_quickest_path.png)


</div>



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

### *Last Update on January 17th, 2025*


<details>

<summary>Table of Contents</summary>

- [**Functional Specifications - 2024-2025-project-3-quickest-path-team-5**](#functional-specifications---2024-2025-project-3-quickest-path-team-5)
  - [**Title:** CAP (Cap Api Pathfinder)](#title-cap-cap-api-pathfinder)
    - [*Last Update on January 17th, 2025*](#last-update-on-january-17th-2025)
- [Introduction](#introduction)
  - [Document Purpose](#document-purpose)
  - [Project Goal](#project-goal)
  - [Project Team Roles](#project-team-roles)
  - [Stakeholders](#stakeholders)
- [Glossary](#glossary)
- [Requirements](#requirements)
  - [Performance Goals](#performance-goals)
  - [Data Integrity Verification](#data-integrity-verification)
  - [Deliverables](#deliverables)
- [Functional Requirements](#functional-requirements)
  - [Description](#description)
  - [APIs](#apis)
    - [Quickest Path Retrieval](#quickest-path-retrieval)
      - [Query Parameters:](#query-parameters)
      - [Headers:](#headers)
  - [Example Requests](#example-requests)
    - [Request with Default Format:](#request-with-default-format)
    - [Response Details](#response-details)
  - [4xx Error Responses](#4xx-error-responses)
    - [400 Missing Parameters](#400-missing-parameters)
      - [Example JSON Response:](#example-json-response)
    - [404 Destination Not Found](#404-destination-not-found)
      - [Example JSON Response:](#example-json-response-1)
  - [500 Error Responses (Server Errors)](#500-error-responses-server-errors)
    - [500 Internal Server Error](#500-internal-server-error)
      - [Example JSON Response:](#example-json-response-2)
  - [REST APIs](#rest-apis)
    - [Communication Between Different Systems](#communication-between-different-systems)
    - [Core Operations](#core-operations)
    - [Client-Server Independence](#client-server-independence)
    - [Statelessness](#statelessness)
    - [Resource Access](#resource-access)
    - [Easy Integration](#easy-integration)
    - [Scalable Architecture](#scalable-architecture)
    - [Data Checker](#data-checker)
  - [STL](#stl)
  - [Algorithm](#algorithm)
  - [Heuristic](#heuristic)
    - [Advantages:](#advantages)
    - [Disadvantages:](#disadvantages)
    - [Input](#input)
  - [Output](#output)
  - [Graph](#graph)
  - [Compatibility](#compatibility)
  - [Interface](#interface)
  - [Acceptance Criteria](#acceptance-criteria)
- [Non-Functional Requirements](#non-functional-requirements)
  - [Costs](#costs)
  - [User Side](#user-side)
  - [Maintainability](#maintainability)
- [Context](#context)
  - [Personnas](#personnas)
  - [Use Cases](#use-cases)
- [Risk](#risk)
  - [Competitive Landscape](#competitive-landscape)
  - [Product problem](#product-problem)
  - [Data](#data)
  - [Risk Management Plan](#risk-management-plan)
- [Future Improvements](#future-improvements)
  - [Precision](#precision)
  - [User Interface (UI)](#user-interface-ui)
  - [Efficiency and Optimization](#efficiency-and-optimization)
  - [Additional Features](#additional-features)
- [Conclusion](#conclusion)


</details>


--- 

# Introduction 

## Document Purpose

The aim of this document is to describe in detail the functionalities and expected behavior of the software, to ensure a common understanding between all stakeholders (all team members, customers, and others).
  

## Project Goal 

The aim of the project is to create a high-performance software solution that calculates the quickest path between two landmarks in the United States. 

## Project Team Roles 

As defined by the project owner, the team is arranged as follows:

| Role               | Description                                                                                     |
|--------------------|-------------------------------------------------------------------------------------------------|
| **Project Manager**  | Responsible for organization, planning, and budgeting.<br>Keeps the team motivated.           |
| **Program Manager**  | Ensures the project meets expectations.<br> In charge of design. <br> Writes the Functional Specifications. |
| **Tech Lead**        | Makes technical decisions for the project.<br>Translates Functional Specifications into Technical Specifications.<br>Performs code reviews. |
| **Software Engineer**| Writes code.<br>Creates documentation.<br>Participates in technical design.                   |
| **Quality Assurance**| Tests all functionalities to identify bugs and issues.<br>Documents bugs and issues.<br>Writes the test plan.<br>Verifies fixes are implemented correctly. |


## Stakeholders
| Name           | Occupation                  | Links                          |
|----------------|-----------------------------|--------------------------------|
| Franck JEANNIN | Client (ALGOSUP's director) | [Website](https://algosup.com) |


# Glossary

<br>

| Term | Definition |
|------|------------|
| **Algorithm** | A clear set of steps or instructions designed to solve a specific problem or complete a task. Common examples include sorting methods and search procedures. |
| **API** | Application Programming Interface - A set of rules and tools that allow different software applications to communicate with each other. Think of it as a waiter taking orders between the kitchen (server) and customers (clients). |
| **Approximation** | A practical approach to finding a good-enough answer when exact solutions are too complex or time-consuming. Often used in real-world engineering and scientific calculations. |
| **Big O Notation** | A mathematical way to describe how an algorithm's performance changes as its input size grows. Written like O(n) or O(n²), it helps developers choose the right algorithm for their needs. |
| **Heuristics** | Heuristics are problem-solving techniques or shortcuts that help find quick, approximate solutions instead of perfect ones. They're often used when time or resources are limited, like guessing a route on a map by following major roads. | 
| **C++** | A powerful programming language that builds upon C, offering both high-level and low-level programming features. Popular in game development, system software, and performance-critical applications. |
| **CSV** | Comma-Separated Values - A simple file format that stores tabular data as plain text, with values separated by commas. Widely used for data exchange between spreadsheets and databases. |
| **DAG** | Directed Acyclic Graph - A graph structure where connections flow in one direction and never form loops. Essential in task scheduling, build systems, and data processing pipelines. |
| **Data Structure** | A way to organize, manage, and store data to allow efficient access and modification. Common examples include arrays, lists, and trees. |
| **Directed Edge** | In graph theory, a connection between two points that flows in one specific direction, like a one-way street between locations. |
| **Frameworks** | Ready-to-use software packages that provide standard functionality for faster development. Examples include React for web development or Django for Python. |
| **GDPR** | General Data Protection Regulation - A comprehensive European law that sets strict standards for personal data protection and privacy rights. |
| **Graph** | A collection of points (nodes) connected by lines (edges), used to represent relationships between items. Think of a social network or road map. |
| **Heuristics** | Problem-solving methods that favor quick, practical solutions over perfect answers. Like taking shortcuts based on experience. |
| **Interface** | The meeting point between different systems or between users and machines. Like a car's dashboard connecting driver and engine. |
| **JSON** | JavaScript Object Notation - A human-readable format for sending data between servers and web applications. Simpler than XML. |
| **Localhost** | A reference to your own computer when it's acting as a server, typically accessed at address 127.0.0.1. Useful for testing. |
| **Machine Learning** | Technology that enables computers to learn from experience and improve their performance without explicit programming. |
| **Parallel Computing** | Running multiple calculations at the same time by splitting tasks across different processors or computers. |
| **REST** | Representational State Transfer - A set of principles for building web services that are simple, scalable, and reliable. |
| **STL** | Standard Template Library - A powerful C++ toolkit providing common programming tools like containers and algorithms. |
| **Test Plan** | A detailed document mapping out how software will be tested, including what to test, when to test, and how to test it. |
| **UI** | User Interface - All the elements users see and interact with in a software application, from buttons to menus. |
| **XML** | Extensible Markup Language - A versatile way to structure data using custom tags, often used in configuration files and data exchange. |



**SQL Dataset** 

--- 


# Requirements

<br>

The requirements are the conditions that must be fulfilled to meet the school's objectives. These represent the core functionalities we need to implement before the deadline. Any additional features developed beyond these requirements will be considered a bonus and add extra value to our work.

<br>


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


## Performance Goals

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


## Data Integrity Verification                           

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

## Deliverables

For this project all the deadlines for the customer are February 7th 2025. But our Project Manager decided to impose his own deadlines. 

| Name | Deadline | Link |
| --  | -- | -- |
| Functional Specifications Document  | 20/01/2025 | [functionalSpecifications.md](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/functional_specifications/FunctionalSpecifications.md) |
| Technical Specifications Document  | 27/01/2024 | [technicalSpecifications.md](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/technical_specifications/TechnicalSpecifications.md) |
| Code | 07/01/2025  | [code](needs to be updated) |
| Test Plan | 07/01/2025 | [qualityAssurance/Test-Plan.md](needs to be updated) | 
| User Manual | 07/01/2025 | [User-Manual](needs to be updated) | 




---

# Functional Requirements

## Description

This project involves developing a software solution in C++ to determine the quickest path between two landmarks in the United States, such as Los Angeles and New York. The goal is to design an algorithm capable of calculating the optimal route efficiently, ensuring results are delivered in under one second.

Users simply provide the IDs of two landmarks as input, and the software calculates and returns the quickest path, including travel time and an ordered list of landmarks along the route. Unlike a GPS, this software does not track real-time location but focuses on providing pre-calculated routes between fixed landmarks.



![alt text](/documents/functional_specifications/images/logic_quickest_path.png)





## APIs

###  Quickest Path Retrieval

| **Endpoint** | `/quickest-path`                                                                 |
|--------------|----------------------------------------------------------------------------------|
| **Method**   | `GET`                                                                            |
| **Purpose**  | Calculates the quickest path between two specified landmarks in the USA, including step-by-step segments and the total time. |


#### Query Parameters:

| Parameter   | Description                                                                         | Required |
|-------------|-------------------------------------------------------------------------------------|----------|
| `source`    | The starting point                                                  | Yes      |
| `destination` | The finish point                                             | Yes      |
| `format`    | Specifies the response format. Supported values: `json` (default), `xml`            | No       |

#### Headers:

| Header     | Description                                                                            |
|------------|----------------------------------------------------------------------------------------|
| `Accept`   | Indicates the desired response format. Defaults to `application/json`.                |

---

## Example Requests

### Request with Default Format:  

<details>
  <summary>Click to view request</summary>
  
  ```http
  GET /quickest-path?source=1543&destination=7845 HTTP/1.1  
  Host: api.example.com  
  Accept: application/json
  ```
  
</details>

### Response Details

|Status Code |	Description |
|------------|--------------|
|200 |	The request was successfully processed, and the response contains the data related to the quickest path calculation between the specified source and destination. |

<details> 
  <summary>Click to view example JSON response</summary>
  <pre><code>
  {
        {
            "distance": 1234,
            "steps": [
                {
                    "segmentA": 12,
                    "segmentB": 65,
                    "distance": 1234
                },
                {
                    "segmentA": 12,
                    "segmentB": 65,
                    "distance": 1234
                },
                {
                    "segmentA": 12,
                    "segmentB": 65,
                    "distance": 1234
                },
                {
                    "segmentA": 12,
                    "segmentB": 65,
                    "distance": 1234
                }
            ]
        }
  }

  </code></pre>
</details>


<details> 
<summary>Click to view example XML response</summary>
<pre><code>
&lt;response&gt;
  &lt;distance&gt;1234&lt;/distance&gt;
    &lt;steps&gt;
        &lt;step&gt;
            &lt;segmentA&gt;12&lt;/segmentA&gt;
            &lt;segmentB&gt;65&lt;/segmentB&gt;
            &lt;distance&gt;1234&lt;/distance&gt;
        &lt;/step&gt;...       
    &lt;/steps&gt;
&lt;/response&gt;
</code></pre>
</details>


`These are examples, the values do not correspond to actual values. ` 

## 4xx Error Responses

### 400 Missing Parameters
| **Property**   | **Details**                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| **Status Code** | `400 Bad Request`                                                          |
| **Description** | Required query parameters are missing.                                     |

#### Example JSON Response:
```json
{
    "status": "error",
    "code": "ERR400",
    "message": "Missing required parameters: source, destination."
}
```

### 404 Destination Not Found

| **Property**   | **Details**                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| **Status Code** | `404 Not Found`                                                            |
| **Description** | One or both poitns are invalid or not present in the dataset.           |

#### Example JSON Response:
```json
{
    "status": "error",
    "code": "ERR404",
    "message": "Landmark not found in the dataset.",
}
```

## 500 Error Responses (Server Errors)

### 500 Internal Server Error

| **Property**   | **Details**                                                                                       |
|-----------------|---------------------------------------------------------------------------------------------------|
| **Status Code** | `500 Internal Server Error`                                                                       |
| **Description** | An unexpected error occurred on the server while processing the request. This could be due to a system failure, database issues, or other unforeseen errors. |

#### Example JSON Response:
```json
{
    "status": "error",
    "code": "ERR500",
    "message": "An internal server error occurred. Please try again later."
}

```


## REST APIs

A REST API enables data exchange between different systems using HTTP protocol. This approach, based on REST principles, has become widespread due to its simplicity and effectiveness.

### Communication Between Different Systems

REST APIs bridge various technologies. For instance, a JavaScript web app can easily communicate with a Python backend and SQL database.

### Core Operations

REST APIs leverage standard HTTP methods:

- GET to read data
- POST to create
- PUT to update
- DELETE to remove

### Client-Server Independence

The client (browser, mobile app...) and server can evolve separately, as long as they follow the API conventions.

### Statelessness

Each request contains everything needed for processing. No need to remember previous requests, which greatly simplifies things.

### Resource Access

REST APIs provide access to data and functionality without diving into source code.

### Easy Integration

With standard formats like JSON or XML, connecting a REST API to other services becomes straightforward.

### Scalable Architecture

REST APIs scale easily thanks to their clean architecture and smart use of HTTP protocol.
This streamlined approach makes REST APIs the backbone of modern web development, enabling robust and flexible system interactions while maintaining simplicity in implementation.

### Data Checker

The goal is to ensure that each node is linked at least to another node, meaning that there is no node that is "alone or lost". It deserves to verify the integrity of data to be sure that we can have a solution for nodes. After this we can is the REST APi to classify data.

## STL

STL is a powerful collection of C++ template classes and functions that provide programming fundamentals like data structures, algorithms, and iterators. It's a core part of the C++ Standard Library that makes programming easier and more efficient.


## Algorithm


![alt text](/documents/functional_specifications/images/Input_output_system.png)

## Heuristic 

To prioritize speed over precision, we will use heuristics. 

In pathfinding, a heuristic function estimates the cost to reach the goal from a given node. For instance, the straight-line distance (Euclidean distance) between two points is often used as a heuristic.

### Advantages:

- Reduces computation time.
- Makes decision-making feasible in large or complex spaces.
- Often provides "good enough" solutions for practical purposes.

### Disadvantages:

- Does not guarantee the optimal solution.
- May lead to errors or biases (e.g., in human reasoning or non-optimal algorithm performance).

### Input 

The Client sent us a list of landmarks, tesource and the destination in a CSV file. This one represent 24 million nodes. 

This file is the input of our algorithm. The goal is to classify all this data to finaly find the quickest path.  

The CSV file is a excel looks like this : 


| Point A   | Point B   | Travel Time |
|-----------|-----------|-------------|
| 6         | 5         | 359         |
| 7         | 8         | 5822        |
| 10        | 9         | 7211        |
| 11        | 12        | 6217        |
| 14        | 13        | 20          |
| 14        | 15        | 2194        |
| 12        | 16        | 34871       |
| 14        | 17        | 3782        |
| 2         | 18        | 1639        |
| 19        | 16        | 40717       |
| 20        | 21        | 1022        |

`This is an example, the values do not correspond to the actual values.  `  


![alt text](/documents/functional_specifications/images/example_path.png)

The third information is the time, this is an important data to the algorithm, essential to find the quickest path.

## Output 

The result of our algorithm should be the ordered list of landmarks on the path and the travel time for each of them.


## Graph

We can represent the CSV file as a graph in mathematics. There are nodes, which represent landmarks, edges, which are the connections between nodes, and weights, which represent the distances between the nodes.

Here an example of a graph in mathematics : 

<br>

<img src="https://imgs.search.brave.com/ZFe7uZ2kdFa_0_6VMQVId4dmkqiexWxnulfp402f_Hk/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly9pMC53/cC5jb20vd3d3Lm1l/dGhvZGVtYXRocy5m/ci9ncmFwaGVfZGlq/a3N0cmEyLmpwZz93/PTQ3NCZzc2w9MQ" width="600" height="300"> 


## Compatibility

The XML and JSON file are two commonly used formats for structuring and exchanging data, each with its own advantages and disadvantages. Here's a comparison of the two formats.

## Interface 


The interface ins't  a requirement, but for a better user expérience it always greatful to have one. We will develop this one in HTML, and tailwind CSS to create somethigs simple but more attractive as a simple termninal interface. 

Just here a figma mockup of the web page : 

In this first page the goal is simple, enter our two landmarks to execute our research. 


After this, you only need to submit. On another page, you get the result: a simple design displaying the time needed to move between these two landmarks.





## Acceptance Criteria

| **Criterion**           | **Description**                                                    |
|-------------------------|--------------------------------------------------------------------|
| Response time           | The API must respond in less than 1 second for all requests.       |
| Result accuracy         | The calculated path should not exceed a 10% approximation.         |
| Robustness              | The API must continue to function under simultaneous requests.     |


--- 

# Non-Functional Requirements

## Costs

| Product | Price | Link |
| --  | -- | -- |
|  Design  | 0 | Made by us |



## User Side

 - Accessible via smartphones, tablets, and desktops.
 - Requires an internet connection.

## Maintainability

 - Clearly commented and documented code.
 - Comprehensive testing and version control.

---

# Context

## Personnas


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
        <img src="https://t4.ftcdn.net/jpg/03/96/16/79/360_F_396167959_aAhZiGlJoeXOBHivMvaO0Aloxvhg3eVT.jpg" alt="Traveler Tom" width="1000" height="200" style="object-fit: cover;" />
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
        <img src="https://images.pexels.com/photos/1239291/pexels-photo-1239291.jpeg?cs=srgb&dl=pexels-danxavier-1239291.jpg&fm=jpg" alt="Traveler Sarah" width="1000" height="200" style="object-fit: cover;"/>
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
        <img src="https://t4.ftcdn.net/jpg/05/99/07/69/360_F_599076934_L4nJ7MWjLgvmLUUXD6Y5VSFvQEFPSv6c.jpg" alt="Vacation Planner Lucy" width="1000" height="250" style="object-fit: cover;" />
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

| **Risk**                 | **Impact**        | **Probability** | **Mitigation Plan**                                                                    |
|--------------------------|-------------------|-----------------|----------------------------------------------------------------------------------------|  
| Insufficient performance | Project failure   | Medium          | Optimize the data structures used.                                                     |
| Critical bugs            | Delays            | High            | Implement a rigorous test strategy with the team member in charge of Quality Assurance.|
| Organizational issues    | Delays            | Medium          | Hold weekly meetings to monitor progress.                                              |

---

# Future Improvements

## Precision

Over the past months, our team has found that adding more landmarks and routes makes a big difference in accuracy. When we include live traffic data, our system can calculate much better routes. We're also excited about improving our maps with detailed information about road quality, speed zones, and current weather conditions - exactly what drivers need.

## User Interface (UI)

Feedback from users has shown the need for a more user-friendly interface. Here's what we're working on:

- Maps you can actually interact with: zoom in close to street level or zoom out for the big picture view
- Smart settings that remember how you like to travel - whether you're a toll-avoider or a highway enthusiast
- A proper mobile experience that works as smoothly as the desktop version
- Built-in features that make the app work well for everyone, including users who rely on screen readers

## Efficiency and Optimization

Our engineering team is exploring some fascinating applications of machine learning:

- Learning from travel patterns to suggest better routes before you even ask
- Smart rerouting that kicks in automatically when traffic gets bad
- Clever ways to group location data that make everything run faster
- Using advanced computing systems to handle complex calculations more quickly

## Additional Features

Beyond the core improvements, we're also developing:

- Full offline support, because you can't always count on having a signal
- Language options that make sense for our global user base
- Smart integration with your calendar and other apps you use daily

We believe these changes will make a real difference in how people use our software, whether they're daily commuters or occasional travelers.

--- 

# Conclusion

This project is primarily focused on technical implementation, with design as a secondary element aimed at enhancing the user experience. The customer's requirements are diverse and extensive, requiring thorough validation at every stage of development.
Undertaking a project of this scale is ambitious, so we have to approach each phase carefully, following our established organization and development protocols. Our main priority is to deliver a functional system that integrates both the data verifier and the REST API. We also aim to create a user interface to enhance the overall experience, but this is a complementary objective rather than a fundamental requirement.
By maintaining this methodical approach and responding to specific customer needs, we aim to guarantee the quality and reliability of the final system.

---




