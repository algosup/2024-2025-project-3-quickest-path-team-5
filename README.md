# Welcome to the Quickest Path API project!

---

## What is the Quickest Path API project?

The Quickest Path API project is a student-led project that aims to create a REST API to find the quickest path between two points in a file that contains 24 million nodes using C++.

For further information, please refer to the [functional specifications](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/functional_specifications/FunctionalSpecifications.md).

For further technical information, please refer to the [technical specifications](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/technical_specifications/TechnicalSpecifications.md).

---

# CAP (Cap API Pathfinding)

CAP is a REST API that allows you to find the quickest path between two verticies of a graph that contains 24 million vertices. The API promises a response time below 1 second in every case. This has been achieved by using a custom algorithm that is based on the A* algorithm. The API is written in C++ and uses the [Crow](https://crowcpp.org/master/) library to handle the HTTP requests.

---

## CAP Getting Started

1. Install [CMake 3.30 or higher](https://cmake.org/download/)
2. Install [Clang 12 or higher](https://releases.llvm.org/download.html)
3. Install [Boost 1.87.0 or higher](https://www.boost.org/users/history/version_1_87_0.html)
4. Install [ASIO 1.30.0 or higher](https://think-async.com/Asio/)
5. Install [PKGConfig](https://www.freedesktop.org/wiki/Software/pkg-config/)
6. Install [jsoncpp 1.9.6 or higher](https://github.com/open-source-parsers/jsoncpp)
7. Clone GoogleTest repository
    ```bash
    # From the root folder of the project
    git clone https://github.com/google/googletest.git
    ```
    Make sure to clone the repository to the root of the project and that the folder is named `googletest`.
8. Generate the build files
    ```bash
    # From the root folder of the project
    cd cap
    cmake -S . -B build
    ```
    This command can require some modifications depending on your operating system.
9. Build the project
    ```bash
    # From the root folder of the project
    cd cap
    cmake --build build
    ```
10. Run the project
    ```bash
    # From the root folder of the project
    cd cap
    ./build/cap
    ```
11. Run the tests (optional)
    ```bash
    # From the root folder of the project
    cd cap
    ./build/tests
    ```

---

# DGV (DAG Graph Validator)

DGV is a tool that allows you to validate a graph file. The tool will check if the file is correctly formatted and if the graph is a Directed Acyclic Graph (DAG). The tool is written in C for performace reasons.

---

## DGV Getting Started

1. Install [CMake 3.30 or higher](https://cmake.org/download/)
2. Install [Clang 12 or higher](https://releases.llvm.org/download.html)
3. Clone GoogleTest repository
    ```bash
    # From the root folder of the project
    git clone https://github.com/google/googletest.git
    ```
    Make sure to clone the repository to the root of the project and that the folder is named `googletest`.
4. Generate the build files
    ```bash
    # From the root folder of the project
    cd dag_graph_validator
    cmake -S . -B build
    ```
    This command can require some modifications depending on your operating system.
5. Build the project
    ```bash
    # From the root folder of the project
    cd dag_graph_validator
    cmake --build build
    ```
6. Run the project
    ```bash
    # From the root folder of the project
    cd dag_graph_validator
    ./build/dgv
    ```
7. Run the tests (optional)
    ```bash
    # From the root folder of the project
    cd dag_graph_validator
    ./build/tests
    ```

---

# Contributors

| Photo | Role | Name | Contact |
|---|---|---|---|
| <img src="https://avatars.githubusercontent.com/u/145991425?v=4" width="100" height="100"> | Project Manager | Habi CAILLEAU| [GitHub](https://github.com/habicll) \| [LinkedIn](https://www.linkedin.com/in/habi-cailleau-3b72b5293/) | 
| <img src="https://avatars.githubusercontent.com/u/182214449?v=4" width="100" height="100"> | Program Manager | Robin GOUMY |[GitHub](https://github.com/RobinGOUMY) \| [LinkedIn](https://www.linkedin.com/in/robin-goumy-66452832a/) |
| <img src="https://avatars.githubusercontent.com/u/145995367?v=4" width="100" height="100"> |  Tech Lead | Mathias GAGNEPAIN |[GitHub](https://github.com/MistzSoftware) \| [LinkedIn](https://www.linkedin.com/in/mathias-gagnepain-426a131b0/) |
| <img src="https://avatars.githubusercontent.com/u/100137905?v=4" width="100" height="100">| Software Developer | Rémy CHARLES |[GitHub](https://github.com/RemyCHARLES) \| [LinkedIn](https://www.linkedin.com/in/r%C3%A9my-charles-2a8960232/) |
| <img src="https://avatars.githubusercontent.com/u/145995231?v=4" width="100" height="100">| Software Developer | Maxime CARON |[GitHub](https://github.com/MaximeAlgosup) \| [LinkedIn](https://www.linkedin.com/in/maxime-caron-dev/) |
| <img src="https://avatars.githubusercontent.com/u/114397870?v=4" width="100" height="100"> | Quality Assurance | Jason GROSSO |[GitHub](https://github.com/JasonGROSSO) \| [LinkedIn](https://www.linkedin.com/in/jason-grosso-847b39251/) |
| <img src="https://avatars.githubusercontent.com/u/123485791?v=4" width="100" height="100"> | Technical Writer | Alexandre BOPP |[GitHub](https://github.com/Boppalex) \| [LinkedIn](https://www.linkedin.com/in/alexandre-bopp-682a97250/) |
