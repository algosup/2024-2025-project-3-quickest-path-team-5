# Test Cases

## Purpose

The purpose of this document is to regroup all of the different Test Cases created for the project.

## Severity

| Low | Can be tested at a latter date than specified |
| Medium | Important but not critical |
| High | Critical, is to be tested ASAP |

## History

You can find the detailled history of our tests on the [linked spreadsheet](https://docs.google.com/spreadsheets/d/1JB1lV4f822tu6zhfQbtrtQGsYIInJZw8AnJMDjYGYeo/edit?gid=0#gid=0).

## Tests

<!--

Test Template

| Test ID |  |
| --- | --- |
| Description |  |
| Steps |  |
| Expected Result |  |
| Severity |  |

 -->

| Test ID | 01 |
| --- | --- |
| Description | Test a simple path |
| Steps | 1. For the first Landmark enter: **1** <br> 2. For the second Landmark enter: **28** |
| Expected Result | - 1 <br> - 2 <br> - 18 <br> - 28 <br> - Time: 7971 |
| Severity | Medium |

> the path 1 to 28 we be referenced enceforth as *small test path*

| Test ID | 02 |
| --- | --- |
| Description | Test a complex path |
| Steps | 1. For the first Landmark enter: **22,320,316** <br> For the second Landmark enter: **4,890,697** |
| Expected Result | insert picture |
| Severity | Medium |

> The path 22,320,316 to 4,890,697 we be referenced enceforth as *large test path*

| Test ID | 03 |
| --- | --- |
| Description | Test response time with small test path |
| Steps |  |
| Expected Result | Less than a second |
| Severity | Medium |

| Test ID | 04 |
| --- | --- |
| Description | Test response time with large test path |
| Steps |  |
| Expected Result | Less than a second |
| Severity | Medium |

| Test ID | 05 |
| --- | --- |
| Description | Test path exist |
| Steps | 1. Generate a path using two random numbers <br> Compare the result with the csv file |
| Expected Result | The path exist |
| Severity | Medium |

| Test ID | 06 |
| --- | --- |
| Description | Test time is correct |
| Steps | 1. Use the path from 05 <br> Compare the result with the csv file |
| Expected Result | The time is correct |
| Severity | Medium |
