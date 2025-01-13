# Test Plan

## Purpose

The purpose of this document is to define and account the different testing strategies that will be employed throughout the project, as well as a link to the result of those strategies.

See the Functional Specifications for a detailed account of the project's functionalities.
See the Technical Specifications for a detailed account of the project's technical aspect.

---

## Testing

Tests assert the different functionalities of a project as well as the quality of the software. They provide feedback on the state and quality of the software, and can be used to measure the advancement of a project.

### Strategies

Here is a list of the different testing strategies that will put into place to ensure the quality of the software:

- Smoke Testing
- Unit Tests
- Feasture Testing

### Smoke Testing

Smoke Testing or Build Verification Testing or Confidence Testing, is a software testing method that is used to determine if a new software build is for the next testing phase. This testing method determines if the most crucial functions of a program work but does not delve into finer details.

The Smoke Testing strategy will be used to verify that:

- The software launches successfully without errors / crashes
- The software output a set of instruction to go from a point A to a point B

### Unit Tests

Unit Tests are blocks of code that verifies the accuracy of a smaller, isolated block of application code, typically a function or method. These tests are written by the Software Engineers and are run regularly. In our case they are run automatically every time we are merging on the main branch

### Feature Testing

Feature Testing consist of testing the different features detailled in the Functional Specifications.
These tests allow testing of all the functions of the software are working as intented as well as find and fix any edge cases.

#### Test Cases

To mesure the advancement of the project we will document the different Tests done during the project as Test Cases (Click on the following link to access all the [Test Cases](/documents/QA/TestCases.md)). Those tests are executed on the app.

All the Test Cases will be stored using the following format:

| Test ID | ID |
| --- | --- |
| Description | Goal of the test |
| Steps | Series of step to execute |
| Expected Result | The correct behavior |
| Severity | Importance of the Test |

> The Severity labels mirrors [GitHub Issues](#github-issues) labels: High, Medium, Low and Critical

#### Test History

To see the detailled Test History follow the link to the [spreadsheet](https://docs.google.com/spreadsheets/d/1JB1lV4f822tu6zhfQbtrtQGsYIInJZw8AnJMDjYGYeo/edit?gid=0#gid=0).

The Test History will be presented as follows:

| Date | ID | Expected | Result | Success? |
| --- | --- | --- | --- | --- |

---

## External Tools

During this project we decided to use several external tools help us ensure the quality of the software and the different deliverables of the project.

### Google Test

GoogleTest is a testing framework developed by the Testing Technology team with Google’s specific requirements and constraints in mind.

It allows us to write and execute a series of unit tests.

### GitHub Actions / Issues

#### GitHub Actions

GitHub Actions allow users to create / implement workflows to automate certain tasks when certain conditions are fulfilled, the workflow is composed of 3 parts:

- It's name
- The activation condition
- Jobs or tasks that the workflow runs

A GitHub Action has been set up on pull requests on the main branch that:

- Install the required programs to run the project
- Checkout the codebase of the pull request
- Clone the test framework
- Build the project
- Run the tests

#### Self-Hosted Runner

A runner is an application that runs jobs from GitHub Actions, we chose to use a Self-Hosted Runner instead of a GitHub Hosted Runner in order to have the control of the hardware, operating system, and software tools.

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

---
