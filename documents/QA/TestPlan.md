# Test Plan

<details>
<summary>Table of Contents</summary>

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
    - [Pull Request](#pull-request)
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

Refer to the following for more detailed information:

- [Functional Specifications](/documents/functional_specifications/FunctionalSpecifications.md)
- [Technical Specifications](/documents/technical_specifications/TechnicalSpecifications.md)

---

## Testing

Testing ensures that the project's functionalities are correctly implemented and meet quality standards.
It provides feedback on the state and quality of the software and measures the project's progress.

### Strategies

The following testing strategies will ensure software quality:

- Smoke Testing
- Unit Tests
- Feature Testing

### Smoke Testing

Smoke Testing, also known as Build Verification Testing or Confidence Testing, determines whether a new software build is stable enough for the next testing phase.
This strategy verifies crucial functionalities without diving into finer details.

Smoke Testing will confirm:

- The software launches successfully without errors or crashes.
- The software outputs a set of instructions to go from point A to point B.

### Unit Tests

Unit Tests verify the accuracy of small, isolated blocks of code, typically functions or methods.
These tests, written by Software Engineers, run automatically whenever changes are merged into the main branch.

### Feature Testing

Feature Testing validates the functionalities outlined in the Functional Specifications.
This testing identifies edge cases and ensures features perform as intended.

#### Test Cases

Test Cases document testing activities and measure project progress.
Tests will focus on data verification and the REST API.

Access all [Test Cases](/documents/QA/TestCases.md).

Test Case format:

| Test ID          | ID |
|-------------------|----|
| Description       | Goal of the test |
| Steps             | Series of steps to execute |
| Expected Result   | The correct behavior |
| Severity          | Importance of the Test |

> Severity levels mirror [GitHub Issues](#github-issues) labels: High, Medium, Low.

##### Test Software

A program generates datasets for verifying test cases.
It creates 800 unique random pairs of landmarks and their distances, outputting them to a .csv file.

#### Test History

View the detailed [Test History](https://docs.google.com/spreadsheets/d/1JB1lV4f822tu6zhfQbtrtQGsYIInJZw8AnJMDjYGYeo/edit?gid=0#gid=0).

Test History format:

| Date       | ID  | Expected | Result | Success? |
|------------|------|----------|--------|----------|

---

## External Tools

Several external tools are employed to ensure software and deliverable quality.

### Google Test

GoogleTest is a testing framework tailored to Google's requirements.
It supports writing and executing unit tests.

> A framework is a conceptual structure serving as a support or guide for building systems.

### GitHub Actions / Issues

#### GitHub Actions

GitHub Actions automate tasks based on defined conditions.
A workflow comprises:

- Name
- Activation condition
- Jobs or tasks to execute

A workflow triggers on pull requests to the main branch and performs the following:

1. Install required programs.
2. Check out the pull request codebase.
3. Clone the test framework.
4. Build the project.
5. Run the tests.

#### Pull Request

A pull request is a request to merge code changes into the main branch.
A template to ensure all pull requests are well-documented, it includes:

- Description of changes
- Prerequisites
- Type of change
- Tested / Reviewed ?
- Checklist of tasks to complete before merging
- Remarks

Failure to follow the template results in pull request rejection.

> Types of change: Issue fix, New feature, Breaking change, Documentation update

#### Self-Hosted Runner

A runner executes GitHub Actions jobs.
A Self-Hosted Runner is used for greater control over hardware, OS, and tools.

#### GitHub Issues

GitHub Issues manage bugs, documentation mistakes, and missing features.
A template ensures issues are well-documented, it includes:

- Type and assigned responsibility
- Severity label (High, Medium, Low)
- Detailed description and reproduction steps

Failure to follow the template results in issue deletion.

##### GitHub Issues Labels

Labels used to classify issues:

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

Test Criteria ensure the final product meets client requirements and the testing phase proceeds smoothly.

### Entry Criteria

Conditions to start the testing phase:

- The software version passes all Unit Tests.
- The Development team is informed of the testing phase.

### Suspension Criteria

Conditions to suspend the testing phase:

- Multiple High Severity Test Cases fail due to bugs.
- Testing resources (environments, tools, staff) are unavailable for extended periods.

Testing resumes when these issues are resolved.

### Exit Criteria

Conditions to conclude the testing phase:

- Most Test Cases pass.
- All High Severity Test Cases pass.
- All Issues are documented.
- All documents are reviewed.

---
