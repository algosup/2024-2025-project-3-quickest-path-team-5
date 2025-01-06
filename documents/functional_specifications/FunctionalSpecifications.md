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
    - [Programming Language](#programming-language)
    - [REST API Specification](#rest-api-specification)
    - [Data Source](#data-source)
  - [Perfomance Goals](#perfomance-goals)
    - [Reponse Time](#reponse-time)
    - [Approximation Heuristics.](#approximation-heuristics)
  - [Data Integrity Verification](#data-integrity-verification)
    - [Graph Validation](#graph-validation)
    - [Connectivity](#connectivity)
  - [Expected Deliverables](#expected-deliverables)
    - [C++ Source Code](#c-source-code)
    - [Time and Space Complexity](#time-and-space-complexity)
    - [REST API Implementation](#rest-api-implementation)
    - [Test Suite](#test-suite)
    - [Data Validation Tool](#data-validation-tool)
- [Description](#description)
  - [Interface](#interface)
  - [Input](#input)
  - [Output](#output)
  - [Compatibilty](#compatibilty)
  - [Interface ?](#interface-)
  - [Materials ?](#materials-)


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

## Core Requirements

### Programming Language

The programming language that we must to use is C++ to achieve optimal performance. 

### REST API Specification

The software will expose its functionality through a REST API that must run on an HTTP server (localhost). 

### Data Source

A document has been gived by the customer. This file contains approximately 24 million nodes. This is the base of our software to develop the quickest path possible in this node.   

## Perfomance Goals

### Reponse Time 

The API must handle all queries within 1 second on a typical laptop.

### Approximation Heuristics. 

To prioritize speed over precision, your solution may use 
heuristics. The returned path should not exceed the shortest path duration by more than 
10%. 

## Data Integrity Verification 

### Graph Validation 

We need to have Verify a the file which forms a Directed Acyclic Graph (DAG) and free of loops. 

### Connectivity 

We need to ensure that the graph is fully connected, meaning it is possible to navigate between any two landmarks.

An other language than C++ is accord if it more convenient for this parts

## Expected Deliverables

### C++ Source Code 

The Source Code need to include comments and clear documentation. The code has to be of our own creation and without any libraries beside STL. This one is necessary for the Web Server. 

### Time and Space Complexity

We must use Big O notation for the main algorithms. 

### REST API Implementation 

Our REST API must be compatible with multiple formats like XML and JSON.

### Test Suite 

We must test our code to validate correctness, perfomance andcompliance to have  the approximation rule of 10%. 


### Data Validation Tool 

We need a utility to check the integrity of the CSV file supplied. 

---

# Description 

## Interface 

## Input 

## Output 

##  Compatibilty



---

## Interface ? 
## Materials ? 


