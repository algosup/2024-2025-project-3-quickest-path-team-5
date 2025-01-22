# Test Cases

## Purpose

The purpose of this document is to regroup all of the different Test Cases created for the project.

## Severity

| Low | Can be tested at a later date than specified |
| Medium | Important but not critical |
| High | Critical, is to be tested ASAP |

## History

You can find the detailed history of our tests on the [linked spreadsheet](https://docs.google.com/spreadsheets/d/1JB1lV4f822tu6zhfQbtrtQGsYIInJZw8AnJMDjYGYeo/edit?gid=0#gid=0).

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

### Data Verification

| Test ID | 001 |
| --- | --- |
| Description | Test Correct dataset |
| Steps | 1. Using a correct dataset start the data verification process |
| Expected Result | No errors |
| Severity | High |

| Test ID | 002 |
| --- | --- |
| Description | Test Connectivity problem |
| Steps | 1. Using a dataset with two blocks starts the data verification process |
| Expected Result | Error: Navigation Between Any Two Landmarks Impossible |
| Severity | High |

| Test ID | 003 |
| --- | --- |
| Description | Test Dataset with loops |
| Steps | 1. Using a data set with loops to start the verification process |
| Expected Result | Error: The Dataset Loops |
| Severity | High |

### API

| Test ID | 101 |
| --- | --- |
| Description | Test a simple path |
| Steps | 1. For the first Landmark enter: **1** <br> 2. For the second Landmark enter: **28** |
| Expected Result | - 1 <br> - 2 <br> - 18 <br> - 28 <br> - Time: 7971 |
| Severity | Medium |

> Paths 1 to 28 will be referenced henceforth as *small test path*

| Test ID | 102 |
| --- | --- |
| Description | Test a complex path |
| Steps | 1. For the first Landmark enter: **22,320,316** <br> For the second Landmark enter: **4,890,697** |
| Expected Result | insert picture |
| Severity | Medium |

> The path 22,320,316 to 4,890,697 wil be referenced enceforth as *large test path*

| Test ID | 103 |
| --- | --- |
| Description | Test response time with small test path |
| Steps | 1. Prepare a stopwatch <br> 2. Enter the small test path and start the stopwatch when starting the program <br> 3. Stop the stopwatch when the program stops |
| Expected Result | Less than a second |
| Severity | Medium |

| Test ID | 104 |
| --- | --- |
| Description | Test response time with large test path |
| Steps |1. Prepare a stopwatch <br> 2. Enter the large test path and start the stopwatch when starting the program <br> 3. Stop the stopwatch when the program stops  |
| Expected Result | Less than a second |
| Severity | Medium |

| Test ID | 105 |
| --- | --- |
| Description | Test path exist |
| Steps | 1. Generate a path using two random numbers <br> 2. Follow the path in the CSV file and compare with the result |
| Expected Result | The path exist |
| Severity | Low |

| Test ID | 106 |
| --- | --- |
| Description | Test time is correct |
| Steps | 1. Use the path from 05 <br> 2. Follow the path in the CSV file and compare with the result |
| Expected Result | The time is correct |
| Severity | Low |

| Test ID | 107 |
| --- | --- |
| Description | Test non-existing path |
| Steps | 1. For the first Landmark enter: **0** <br> 2. For the second Landmark enter: **387462**|
| Expected Result | Error: Invalid Landmark |
| Severity | Low |

| Test ID | 108 |
| --- | --- |
| Description | Test missing one Landmark |
| Steps | 1. For the first Landmark enter: **1** <br> 2. For the second Landmark enter nothing |
| Expected Result | Error: Missing One Landmark |
| Severity | Low |

| Test ID | 109 |
| --- | --- |
| Description | Test missing all Landmark |
| Steps | 1. Try starting the software without entering any Landmarks |
| Expected Result | Error: No Landmarks |
| Severity | Low |

| Test ID | 110 |
| --- | --- |
| Description | Test identical Landmark |
| Steps | 1. For the first Landmark enter: **1** <br> 2. For the second Landmark enter: **1** |
| Expected Result | Error: Identical Landmark |
| Severity | Low |

| Test ID | 111 |
| --- | --- |
| Description | Test strings as Landmark |
| Steps | 1. For the first Landmark enter **1** <br> 2. For the second Landmark enter: **New York** |
| Expected Result | Error: Invalid Landmark |
| Severity | Low |

| Test ID | 112 |
| --- | --- |
| Description | Test symbols as Landmark |
| Steps | 1. For the first Landmark enter **1** <br> 2. For the second Landmark enter: **#%$$¤** |
| Expected Result | Error: Invalid Landmark |
| Severity | Low |

| Test ID | 113 |
| --- | --- |
| Description | Test Download JSON |
| Steps | 1. Run the large test path 2. Click on the Download button |
| Expected Result | A JSON file with all the steps has been downloaded |
| Severity | Medium |

| Test ID | 114 |
| --- | --- |
| Description | Test Download XML |
| Steps | 1. Run the large test path 2. Click on the Download button  |
| Expected Result | A XML file with all the steps has been downloaded |
| Severity | Medium |
