# Test Plan

## Purpose

The purpose of this document is to define and account the different testing strategies that will be employed throughout the project, as well as a link to the result of those strategies.

See the Functional Specifications for a detailed account of the project's functionalities.
See the Technical Specifications for a detailed account of the project's technical aspect.

## Testing

Tests assert the different functionalities of a project as well as the quality of the software. They provide feedback on the state and quality of the software, and can be used to measure the advancement of a project.

### Strategies

Here is a list of the different testing strategies that will put into place to ensure the quality of the software:

- Smoke Testing
- Unit Tests

### Smoke Testing

Smoke Testing or Build Verification Testing or Confidence Testing, is a software testing method that is used to determine if a new software build is for the next testing phase. This testing method determines if the most crucial functions of a program work but does not delve into finer details.

The Smoke Testing strategy will be used to verify that:

- the software launches successfully without errors / crashes
- the software output a set of instruction to go from a point A to a point B

### Unit Tests

Unit Tests are blocks of code that verifies the accuracy of a smaller, isolated block of application code, typically a function or method. These tests are written by the Software Engineers and are run regularly. In our case they are run automatically every time we are merging on the main branch

## External Tools

During this project we decided to use several external tools help us ensure the quality of the software and the different deliverables of the project.

### Google Test

GoogleTest is a testing framework developed by the Testing Technology team with Google’s specific requirements and constraints in mind.

It allows us to write and execute a series of unit tests.

### GitHub Actions / Issues

#### GitHub Actions

GitHub Actions allow users to create / implement workflows to automate certain tasks when certain conditions are fulfilled.

A GitHub Action has been set up on pull requests on the main branch that:

- Launch the software
- Run the Units Tests
(WIP)

#### GitHub Issues

GitHub Issues allow users to create / manage issues to find and track problems that rose and their resolution; issues can be applied to:

- Bugs in the code
- Documentation Mistakes
- Missing Features

A GitHub Issue Template is put at the disposition of the team members and must be filled when creating an Issue. Failure to comply will result in the Issue being deleted.
The Template includes but is not limited to:

- A label that specify the type of Issue and who does the Issue concerns
- An assigned person responsible for fixing the Issue
- A label that specify the severity of the Issue among: High, Medium, Low and Critical
- A detailed description of the issue and the expected behaviour and if necessary a step by step description on how to reproduce the issue

## Test Cases

To mesure the advancement of the project we will document the different Tests done during the project as Test Cases (Click on the following link to access all the [Test Cases](/documents/QA/TestCases.md)).

All the Test Cases will be stored using the following format:

| Test ID | 01 |
| --- | --- |
| Description | Compiling the Software |
| Steps | 1. Enter a terminal <br> 2. type ``cmake -S . -B Build -G "MinGW Makefiles"`` <br> 3. Press Enter|
| Expected Result | |
| Severity | Critical |

> The Severity labels mirrors [GitHub Issues](#github-issues) labels: High, Medium, Low and Critical
