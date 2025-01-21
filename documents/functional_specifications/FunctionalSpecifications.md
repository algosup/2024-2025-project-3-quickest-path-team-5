<div align="center">

# Functional Specifications - Project Quickest Path

## **Title:** CAP (Cap Api Pathfinder)

**Author:** Robin GOUMY

**Team:**  5

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

### *Last Update on January 20th, 2025*

<details>

<summary>Table of Contents</summary>

- [Functional Specifications - Project Quickest Path](#functional-specifications---project-quickest-path)
  - [**Title:** CAP (Cap Api Pathfinder)](#title-cap-cap-api-pathfinder)
    - [*Last Update on January 20th, 2025*](#last-update-on-january-20th-2025)
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
  - [Context](#context)
    - [Personnas](#personnas)
    - [Use Cases](#use-cases)
  - [Functional Requirements](#functional-requirements)
    - [Description](#description)
    - [Data Checker](#data-checker)
    - [APIs](#apis)
      - [Quickest Path Retrieval](#quickest-path-retrieval)
        - [Query Parameters](#query-parameters)
        - [Headers](#headers)
    - [Example Requests](#example-requests)
      - [Request with Default Format:](#request-with-default-format)
      - [Response Details](#response-details)
    - [4xx Error Responses](#4xx-error-responses)
      - [400 Missing Parameters](#400-missing-parameters)
        - [Example 1 JSON Response](#example-1-json-response)
      - [404 Destination Not Found](#404-destination-not-found)
        - [Example 2 JSON Response](#example-2-json-response)
    - [500 Error Responses (Server Errors)](#500-error-responses-server-errors)
      - [500 Internal Server Error](#500-internal-server-error)
        - [Example 3 JSON Response](#example-3-json-response)
    - [Algorithm and Data Processing](#algorithm-and-data-processing)
      - [Heuristic Approach](#heuristic-approach)
      - [Advantages](#advantages)
      - [Disadvantages](#disadvantages)
      - [Input Data](#input-data)
      - [Output](#output)
    - [User Interface](#user-interface)
    - [Acceptance Criteria](#acceptance-criteria)
  - [Non-Functional Requirements](#non-functional-requirements)
    - [Costs](#costs)
    - [User Side](#user-side)
    - [Maintainability](#maintainability)
  - [Risk](#risk)
    - [Competitive Landscape](#competitive-landscape)
    - [Product problem](#product-problem)
    - [Data Security](#data-security)
    - [Risk Management Plan](#risk-management-plan)
  - [Future Improvements](#future-improvements)

</details>

---

## Introduction

### Document Purpose

The aim of this document is to describe in detail the functionalities and expected behavior of the software, to ensure a common understanding between all stakeholders (all team members, customers, and others).
  
### Project Goal

The aim of the project is to create a high-performance software solution that calculates the quickest path between two landmarks in the United States.

### Project Team Roles

As defined by the project owner, the team is arranged as follows:

| Role                 | Description                                                                                       |
|----------------------|---------------------------------------------------------------------------------------------------|
| **Project Manager**   | Responsible for organization, planning, and budgeting.<br>Keeps the team motivated.               |
| **Program Manager**   | Ensures the project meets expectations.<br>In charge of design.<br>Writes the Functional Specifications. |
| **Tech Lead**         | Makes technical decisions for the project.<br>Translates Functional Specifications into Technical Specifications.<br>Performs code reviews. |
| **Software Engineer** | Writes code.<br>Creates documentation.<br>Participates in technical design.                       |
| **Quality Assurance** | Tests all functionalities to identify bugs and issues.<br>Documents bugs and issues.<br>Writes the test plan.<br>Verifies fixes are implemented correctly. |
| **Technical Writer**  | Creates and maintains user manuals, technical documentation, and guides.<br>Works with engineers to understand and document features.<br>Ensures documentation is clear, concise, and user-friendly. |

### Stakeholders

| Name           | Occupation                  | Links                          |
|----------------|-----------------------------|--------------------------------|
| Franck JEANNIN | Client (ALGOSUP's director) | [Website](https://algosup.com) |

### Glossary

| Term              | Definition                                                                                                             |
|-------------------|------------------------------------------------------------------------------------------------------------------------|
| **Algorithm**     | A set of clear steps to solve a problem or complete a task, like sorting or searching.                                 |
| **API**           | Application Programming Interface - Rules allowing software to communicate with each other.                            |
| **Approximation** | A method to find a good-enough answer when exact solutions are too hard or slow.                                       |
| **Big O Notation**| Describes how an algorithm's speed changes with input size, like O(n) or O(n²).                                        |
| **C++**           | A powerful programming language used for games, system software, and fast applications.                                |
| **CSV**           | Comma-Separated Values - A simple text format for storing data in tables.                                              |
| **DAG**           | Directed Acyclic Graph - A graph with one-way links and no loops, useful in many systems.                              |
| **Data Structure**| A way to organize and store data for quick access, like arrays or trees.                                               |
| **Directed Edge** | A one-way connection between two points in a graph.                                                                    |
| **Frameworks**    | Pre-built tools or libraries to speed up development, like React or Django.                                            |
| **GDPR**          | General Data Protection Regulation - EU law for protecting personal data and privacy.                                  |
| **Graph**         | A collection of points (nodes) connected by lines (edges), like social networks.                                       |
| **Graph Connectivity** | The degree to which nodes in a graph are linked to each other.                                                    |
| **Heuristics**    | Quick methods for solving problems, often based on experience.                                                         |
| **JSON**          | JavaScript Object Notation - A simple format for exchanging data, easier than XML.                                     |
| **Localhost**     | Refers to your own computer acting as a server, usually at 127.0.0.1.                                                  |
| **Machine Learning** | Tech that helps computers learn and improve without being explicitly programmed.                                    |
| **OSRM**          | Open Source Routing Machine - An open-source, high-performance routing engine for calculating routes on road networks. |
| **REST**          | Representational State Transfer - A way to build scalable, reliable web services.                                      |
| **SQL Dataset**   | Data organized in tables, often managed with Structured Query Language (SQL).                                          |
| **STL**           | Standard Template Library - C++ tools for containers and algorithms.                                                   |
| **Test Plan**     | A document describing what, when, and how to test in software.                                                         |
| **UI**            | User Interface - What users see and interact with in software, like buttons and menus.                                 |
| **XML**           | Extensible Markup Language - A flexible format for structuring and exchanging data.                                    |

---

## Requirements

<br>

The requirements are the conditions that must be fulfilled to meet the school's objectives.
These represent the core functionalities we need to implement before the deadline.
Any additional features developed beyond these requirements will be considered a bonus and add extra value to our work.

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
| Functional Specifications Document  | 20/01/2025 | [functionalSpecifications.md](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/functional_specifications/FunctionalSpecifications.md) |
| Technical Specifications Document  | 27/01/2024 | [technicalSpecifications.md](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/technical_specifications/TechnicalSpecifications.md) |
| Code | 07/01/2025  | [code](needs to be updated) |
| Test Plan | 07/01/2025 | [TestPlan.md](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/QA/TestPlan.md) |
| Test Cases | 07/01/2025 | [TestPlan.md](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/QA/TestCases.md) |
| User Manual | 07/01/2025 | [User-Manual]([needs to be updated](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Manual/usermanuel.md)) |

---

## Context

### Personnas

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
      <td rowspan="5">
        <img src="https://t4.ftcdn.net/jpg/03/96/16/79/360_F_396167959_aAhZiGlJoeXOBHivMvaO0Aloxvhg3eVT.jpg" alt="Business Traveler Tom" width="200" style="object-fit: cover;" />
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
      <td>Logistics Planning Manager</td>
    </tr>
    <tr>
      <td><strong>Skills</strong></td>
      <td>Project management, logistics coordination, team leadership, data analysis</td>
    </tr>
    <tr>
      <td><strong>Usage Scenario</strong></td>
      <td>Tom uses the API to calculate real-time optimal delivery routes for his drivers. he tracks distances and travel times to optimize costs and team performance.</td>
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
      <td rowspan="5">
        <img src="https://t4.ftcdn.net/jpg/05/99/07/69/360_F_599076934_L4nJ7MWjLgvmLUUXD6Y5VSFvQEFPSv6c.jpg" alt="Retiree Lucy" width="200" style="object-fit: cover;" />
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
      <td>Retiree</td>
    </tr>
    <tr>
      <td><strong>Skills</strong></td>
      <td>Destination research, budgeting, travel planning</td>
    </tr>
    <tr>
      <td><strong>Usage Scenario</strong></td>
      <td>Lucy uses an application powered by the API to plan her vacations. She finds the fastest routes, calculates transportation costs, and adjusts her budget accordingly.</td>
    </tr>
  </tbody>
</table>


### Use Cases

The API is designed to be implemented into existing software solutions rather than functioning as a standalone application. It provides seamless integration capabilities to enhance the functionality of third-party platforms.

| **User**             | **Action**                                      | **Expected Result**                       |
|----------------------|-------------------------------------------------|-------------------------------------------|
| Supply Chain Manager | Coordinate deliveries across multiple regions using logistics software | A comprehensive route map segmented by region and time, available within their current logistics tool. |
| Travel Enthusiast    | Plan an efficient multi-stop journey using a travel planning app | A detailed itinerary with travel times and distances for each stop, accessible in their preferred travel app. |

---

## Functional Requirements

### Description

This project involves developing a software solution in C++ to determine the quickest path between two landmarks in the United States, such as Los Angeles and New York.
The goal is to design an algorithm capable of calculating the optimal route efficiently, ensuring results are delivered in under one second.

<br>

Users simply provide the IDs of two landmarks as input, and the software calculates and returns the quickest path, including travel time and an ordered list of landmarks along the route. Unlike a GPS, this software does not track real-time location but focuses on providing pre-calculated routes between fixed landmarks.

### Data Checker

<br>

The data checker is a crucial tool for ensuring that the data is correct, reliable and adapted to the algorithm used, thus avoiding errors later on in the program.
For example, it checks that there are no infinite loops or duplicate nodes.
It also checks that all nodes are present, that there is a possible route for all of them, i.e. that they are related, that the data type is usable and complete for each node, stop and time.

<br>

This algorithm will be implemented in C, as it is a high-performance language at this level, enabling a certain level of precision and efficiency to be achieved.

<br>

![alt text](/documents/functional_specifications/images/logic_quickest_path.png)  


<br>

### APIs

An API is a set of rules and protocols that allows different software applications to communicate and share data with each other.
It defines how requests and responses should be formatted, enabling developers to interact with external services or integrate functionalities without needing to understand their internal workings.

<br>

![alt text](images/Input_output_system.png)

<br>

#### Quickest Path Retrieval

| **Endpoint** | `/quickest-path`                                                                 |
|--------------|----------------------------------------------------------------------------------|
| **Method**   | `GET`                                                                            |
| **Purpose**  | Calculates the quickest path between two specified landmarks in the USA, including step-by-step segments and the total time. |


##### Query Parameters

| Parameter   | Description                                                                         | Required |
|-------------|-------------------------------------------------------------------------------------|----------|
| `source`    | The starting point                                                                  | Yes      |
| `destination` | The finish point                                                                  | Yes      |
| `format`    | Specifies the response format. Supported values: `json`, `xml`                      | No       |

##### Headers

| Header     | Description                                                                            |
|------------|----------------------------------------------------------------------------------------|
| `Accept`   | Indicates the desired response format. Defaults to `application/json`.                |

---

### Example Requests

#### Request with Default Format:  

<details>
  <summary>Click to view request</summary>
  
  ```http
  GET /quickest-path?source=1543&destination=7845 HTTP/1.1  
  Host: api.example.com  
  Accept: application/json
  ```
  
</details>

#### Response Details

|Status Code |Description |
|------------|--------------|
|200 |The request was successfully processed, and the response contains the data related to the quickest path calculation between the specified source and destination. |

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
                }...
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

>These are examples, the values do not correspond to actual values.

### 4xx Error Responses

#### 400 Missing Parameters

| **Property**   | **Details**                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| **Status Code** | `400 Bad Request`                                                          |
| **Description** | Required query parameters are missing.                                     |

##### Example 1 JSON Response

```json
{
    "status": "error",
    "code": "ERR400",
    "message": "Missing required parameters: source, destination."
}
```

#### 404 Destination Not Found

| **Property**   | **Details**                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| **Status Code** | `404 Not Found`                                                            |
| **Description** | One or both points are invalid or not present in the dataset.           |

##### Example 2 JSON Response

```json
{
    "status": "error",
    "code": "ERR404",
    "message": "Landmark not found in the dataset.",
}
```

### 500 Error Responses (Server Errors)

#### 500 Internal Server Error

| **Property**   | **Details**                                                                                       |
|-----------------|---------------------------------------------------------------------------------------------------|
| **Status Code** | `500 Internal Server Error`                                                                       |
| **Description** | An unexpected error has occurred on the server while processing the request. This may be due to system failure, database problems or other unforeseen errors. |

##### Example 3 JSON Response

```json
{
    "status": "error",
    "code": "ERR500",
    "message": "An internal server error occurred. Please try again later."
}

```

### Algorithm and Data Processing

#### Heuristic Approach

To ensure fast computations, a heuristic (e.g., Euclidean distance) is used to estimate travel costs between two points.

#### Advantages

- Reduces computation time.
  
- Useful for complex or large spaces.

#### Disadvantages

- May not guarantee an optimal solution.

#### Input Data

Input data is provided in a CSV file containing 24 million nodes with the following structure:

| Point A | Point B | Travel Time |
| --  | -- | -- |
|  6  | 5 | 359 |
|  7  | 8 | 5822 |
|  10  | 9 | 7211 |

>This is an example, the values do not correspond to the actual values.  

![alt text](/documents/functional_specifications/images/example_path.png)

<img src="https://imgs.search.brave.com/ZFe7uZ2kdFa_0_6VMQVId4dmkqiexWxnulfp402f_Hk/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly9pMC53/cC5jb20vd3d3Lm1l/dGhvZGVtYXRocy5m/ci9ncmFwaGVfZGlq/a3N0cmEyLmpwZz93/PTQ3NCZzc2w9MQ" width="400" height="200">

The preceding images represent a mathematical graph where:

- Nodes represent landmarks.
- Edges represent connections between landmarks.
- Weights represent travel times between nodes.
  
#### Output

The algorithm returns:

- Total travel time.
  
- An ordered list of landmarks on the optimal path.

### User Interface

Although optional, a simple web interface will be developed using HTML and Tailwind CSS to improve user experience.

Home Page: Allows the user to input two landmarks.

![alt text](images/figma_cap_main_page.png)

Result Page: Displays the total travel time and the landmarks along the route.

You can also download the complete file with all directions from Landmark A to Landmark B in XML or JSON format.

![alt text](<images/figma_cap_ next_page.png>)

### Acceptance Criteria

| **Criterion**           | **Description**                                                    |
|-------------------------|--------------------------------------------------------------------|
| Response time           | The API must respond in less than 1 second for all requests.       |
| Result accuracy         | The calculated path should not exceed a 10% approximation.         |
| Scalability             | The API must continue to function under simultaneous requests.     |

---

## Non-Functional Requirements

### Costs

There is no cost for this project.

### User Side

- Accessible via smartphones, tablets, and desktops.
- Requires an internet connection.

### Maintainability

- Clearly commented and documented code.
- Comprehensive testing and version control.

---

## Risk

### Competitive Landscape

Today's market is highly competitive, with many powerful and advanced companies.

- **Google Maps Platform**: Offers precise, real-time route optimization for various transportation modes. Strong integration with Google services but costly for smaller businesses.  
- **Mapbox**: Known for customization and flexibility, popular with developers. Limited advanced features compared to Google.  
- **OpenStreetMap (OSM)**: A free, community-driven option with customizable tools like OSRM. Less precise in certain areas. OSRM is widely used in mapping, navigation, and logistics applications.

### Product problem

In any project, no issue should ever be taken lightly, as even seemingly minor problems can lead to significant time losses and disrupt progress.
It is essential to approach every detail with attention and care to minimize risks and ensure a smooth workflow. Proactive problem-solving and vigilance are key to avoiding unnecessary setbacks and maintaining the project's momentum.

### Data Security

Compliance with the General Data Protection Regulation (GDPR) is crucial in developing software that interacts with users, ensuring personal data protection and privacy.
By adhering to these standards, developers not only ensure legal compliance but also build user trust.
The GDPR requires transparent data collection, storage, and processing practices, giving users control over their personal information, which is essential for the acceptance of digital technologies.

To kown more about it : [RGPD License](https://en.wikipedia.org/wiki/General_Data_Protection_Regulation)

### Risk Management Plan

| **Risk**                 | **Impact**        | **Probability** | **Mitigation Plan**                                                                    |
|--------------------------|-------------------|-----------------|----------------------------------------------------------------------------------------|  
| Insufficient performance | Project failure   | Medium          | Optimize the data structures used.                                                     |
| Critical bugs            | Delays            | High            | Implement a rigorous test strategy with the team member in charge of Quality Assurance.|
| Organizational issues    | Delays            | Medium          | Hold weekly meetings to monitor progress.                                              |

---

## Future Improvements

- Precision
  - Enhanced routes: More landmarks and live traffic data for better route accuracy.
  - Detailed map info: Road quality, speed zones, and weather conditions.
  
- User Interface
  - Interactive maps: Zoom in/out for street-level or overview view.
  - Smart settings: Remembers travel preferences (e.g., toll-avoider, highway enthusiast).
  - Mobile optimization: Seamless mobile experience like the desktop version.
  - Accessibility: Features supporting screen readers.
  
- Efficiency and Optimization
  - Machine learning: Predict and suggest better routes based on travel patterns.
  - Smart rerouting: Automatic updates when traffic worsens.
  - Optimized data: Faster performance with efficient data grouping.
  - Advanced computing: Speeding up complex calculations.
  
- Additional Features
  - Offline support: Full functionality without a signal.
  - Global language options: Tailored for international users.
  
We believe these changes will make a real difference in how people use our software, whether they're daily commuters or occasional travelers.