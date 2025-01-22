# Test Plan

<details>
<summary>Table of Content</summary>

- [Purpose](#purpose)
- [Testing](#testing)
  - [Strategies](#strategies)
  - [Smoke Testing](#smoke-testing)
  - [Unit Tests](#unit-tests)
  - [Feature Testing](#feature-testing)
    - [Test Cases](#test-cases)
      - [Test Software](#test-software)
    - [Test History](#test-history)
- [External Tools](#external-tools)
  - [Google Test](#google-test)
  - [GitHub Actions / Issues](#github-actions--issues)
    - [GitHub Actions](#github-actions)
    - [Self-Hosted Runner](#self-hosted-runner)
    - [GitHub Issues](#github-issues)
    - [GitHub Issues Labels](#github-issues-labels)
- [Test Criteria](#test-criteria)
  - [Entry Criteria](#entry-criteria)
  - [Suspension Criteria](#suspension-criteria)
  - [Exit Criteria](#exit-criteria)

</details>

## Purpose

This document defines and accounts for the different testing strategies that will be employed throughout the project, as well as links to the results of those strategies.

See the Functional Specifications for a detailed account of the project's functionalities. (insert link)
See the Technical Specifications for a detailed account of the project's technical aspects. (insert link)

---

## Testing

Tests assert the different functionalities of a project as well as the quality of the software.
They provide feedback on the state and quality of the software and can be used to measure the advancement of a project.

### Strategies

Here is a list of the different testing strategies that will be put into place to ensure the quality of the software:

- Smoke Testing
- Unit Tests
- Feature Testing

### Smoke Testing

Smoke Testing, Build Verification Testing, or Confidence Testing, is a software testing method that is used to determine if a new software build is for the next testing phase.
This testing method determines if the most crucial functions of a program work but does not delve into finer details.

The Smoke Testing strategy will be used to verify that:

- The software launches successfully without errors/crashes
- The software outputs a set of instructions to go from point A to point B

### Unit Tests

Unit Tests are blocks of code that verify the accuracy of a smaller, isolated block of application code, typically a function or method.
These tests are written by the Software Engineers and are run regularly. In our case, they are run automatically every time we merge on the main branch.

### Feature Testing

Feature Testing consists of testing the different features detailed in the Functional Specifications.
These tests allow testing of all the functions of the software that are working as intended as well as finding and fixing any edge cases.

#### Test Cases

To measure the advancement of the project we will document the different Tests done during the project as Test Cases (Click on the following link to access all the [Test Cases](/documents/QA/TestCases.md)). Those Tests will be focused on the data verification as well as the REST API.

All the Test Cases will be stored using the following format:

| Test ID | ID |
| --- | --- |
| Description | Goal of the test |
| Steps | series of steps to execute |
| Expected Result | The correct behavior |
| Severity | Importance of the Test |

> The Severity labels mirrors [GitHub Issues](#github-issues) labels: High, Medium and Low

##### Test Software

In order to verify each test case we created a program that generates datasets.
The program generates 800 random unique pairs of landmarks and their distance and writes them in a .csv file.

#### Test History

To see the detailed Test History follow the link to the [spreadsheet](https://docs.google.com/spreadsheets/d/1JB1lV4f822tu6zhfQbtrtQGsYIInJZw8AnJMDjYGYeo/edit?gid=0#gid=0).

The Test History will be presented as follows:

| Date | ID | Expected | Result | Success? |
| --- | --- | --- | --- | --- |

---

## External Tools

During this project, we decided to use several external tools to help us ensure the quality of the software and the different deliverables of the project.

### Google Test

GoogleTest is a testing framework developed by the Testing Technology team with Google’s specific requirements and constraints in mind.

It allows us to write and execute a series of unit tests.

### GitHub Actions / Issues

#### GitHub Actions

GitHub Actions allow it's users to create/implement workflows to automate certain tasks when certain conditions are fulfilled, the workflow is composed of 3 parts:

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

A runner is an application that runs jobs from GitHub Actions, we chose to use a Self-Hosted Runner instead of a GitHub Hosted Runner in order to have control of the hardware, operating system, and software tools.

#### GitHub Issues

GitHub Issues allow users to create/manage issues to find and track problems that arise and their resolution, issues can be applied to:

- Bugs in the code
- Documentation Mistakes
- Missing Features

A GitHub Issue Template is put at the disposition of the team members and must be filled when creating an Issue.
Failure to comply will result in the Issue being deleted.
The Template includes but is not limited to:

- A label that specifies the type of Issue and who the Issue concerns
- An assigned person responsible for fixing the Issue
- A label that specifies the severity of the Issue among: High, Medium, and Low
- A detailed description of the issue and the expected behavior and if necessary a step-by-step description of how to reproduce the issue

##### GitHub Issues Labels

Here are the different labels used to specify the type of Issue:

- bug
- documentation
- duplicate
- enhancement
- good first issue
- help wanted
- invalid
- question

---

## Test Criteria

Test Criteria are crucial to guarantee that the end product is up to the requirements of the client. And also ensure that the testing phase goes as smoothly as possible.

### Entry Criteria

Entry Criteria define conditions under which the testing phase may start, these criteria ensure that the software is ready to be tested before the testing phase can begin.

This project's Entry Criteria:

- The version of the software that is tested passed all the Unit Tests
- The Development team is aware that a test phase is starting

### Suspension Criteria

Suspension Criteria define conditions under which the testing phase may be suspended to avoid working on a failing software.

This project's Suspension criteria:

- When multiple High Severity Test Cases are not passing due to bugs the test phase will be suspended, and the development team as well as the QA team will work together to fix those bugs.

- When multiple testing resources such as testing environments, tools, or staff become unavailable for an extended period, testing may be suspended; testing will resume when said resources are available once again.

### Exit Criteria

Exit Criteria define conditions under which the testing phase may end.

This project's Exit criteria:

- A major part of the Test executed passes
- All of the High Severity Test Cases passes
- All the Issues have been documented
- All the documents were reviewed

---
