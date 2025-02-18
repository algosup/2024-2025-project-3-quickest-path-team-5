<div align="center">

---

# Management Artifacts Team 5 - Quickest Path

## Document Information

| Description    | Information   |
| -------------- | ------------- |
| Document Owner | Habi CAILLEAU |
| Creation Date  | 06/01/2025    |
| Last Update    | 06/02/2025    |

<br>

</div>


## Tasks & Schedule

The Tasks & Schedule section is divided into three parts. All information is maintained and updated in Notion for real-time tracking and collaboration.

1. **All the Tasks:** [View all tasks](https://spark-vessel-8f5.notion.site/177204fa481680bbb2c8d06169a54f1f?v=177204fa4816808a8327000c91da52ee&pvs=4)  
   This section lists every task with detailed descriptions, assigned roles, and deadlines.

2. **Gantt Chart:** [View the Gantt chart](https://spark-vessel-8f5.notion.site/192204fa481680d89f57f57e6b29fd33?v=192204fa48168178983d000c597d17a7&pvs=4)  
   A visual timeline created in Notion that outlines project milestones and deadlines.

3. **Actual Time Logs:** [View actual time logs](https://spark-vessel-8f5.notion.site/Daily-Task-List-177204fa481680dbae3eddb0873509be?pvs=4)  
   A record of the actual time spent on each task, maintained and updated regularly in Notion.

<br>

## RACI

| **Project Activities**                   | **Program Manager** | **Tech Lead** | **Software Engineers** | **QA Engineer** | **Technical Writer** |
| ---------------------------------------- | ------------------- | ------------- | ---------------------- | --------------- | -------------------- |
| **Project Planning & Management**        | R                   | C             | I                      | I               | I                    |
| **Functional Specification**             | R                   | C             | I                      | C               | A                    |
| **Technical Specification**              | I                   | R             | A                      | C               | I                    |
| **Code Implementation**                  | I                   | R             | A                      | C               | I                    |
| **Data Structure Development**           | I                   | R             | A                      | C               | I                    |
| **Pathfinding Algorithm Implementation** | I                   | R             | A                      | C               | I                    |
| **API Design & Development**             | C                   | R             | A                      | C               | I                    |
| **Testing and Quality Assurance**        | C                   | C             | R                      | A               | I                    |
| **Performance Optimization**             | I                   | R             | A                      | C               | I                    |
| **Data Integrity Verification**          | C                   | R             | A                      | C               | I                    |
| **Documentation (User Manual, etc.)**    | I                   | C             | I                      | C               | A                    |
| **Project Delivery**                     | R                   | C             | A                      | I               | C                    |


Key:
R = Responsible: Person doing the work.
A = Accountable: Ultimately answerable for the task.
C = Consulted: Person whose input is sought.
I = Informed: Person kept up-to-date on progress.

<br>

## MoScoW

| Must Have                      | Should Have           | Could Have              | Won't Have       |
| ------------------------------ | --------------------- | ----------------------- | ---------------- |
| Dijkstra pathfinding algorithm | Authentication system | Web App                 | Complete web app |
| API                            | Auto testing system   | interface specification |                  |
| Data checking                  |                       |                         |                  |
| Data integrity validation tool |                       |                         |                  |

<br>

## Risks and assumptions

The following risks could come accross during the project, here is a detailled way to avoid them :

| **Item**                                               | **Type**      | **Impact** | **Management Response / Approach**                                                                                                                                      |
|--------------------------------------------------------|---------------|------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Incomplete or ambiguous requirements                   | Risk          | High       | Hold regular requirements review meetings and secure early stakeholder sign-off to ensure clarity.                                                                       |
| Resource availability or scheduling delays             | Risk          | High       | Monitor team workload closely, maintain a flexible schedule, and develop contingency plans for resource reallocation.                                                     |
| Changes in technology or unexpected technical issues     | Risk          | High       | Allocate time for research and pilot testing; update the project plan promptly if technology shifts occur.                                                               |
| Communication breakdown among team members             | Risk          | High       | Establish clear communication protocols, schedule regular progress meetings, and utilize collaboration tools to ensure continuous updates.                                |
| External dependencies (e.g., dataset quality, third-party tools) | Risk          | Medium     | Validate critical external inputs early and prepare contingency plans in case of issues with third-party resources.                                                        |
| The provided dataset is accurate and reliable          | Assumption    | High       | Conduct early data validation and plan for adjustments if discrepancies arise.                                                                                          |
| The team possesses the necessary skills for the project | Assumption    | Medium     | Leverage internal expertise, offer targeted training where needed, and consider external support for specialized tasks if required.                                         |
| Required tools and infrastructure will function as expected | Assumption | Medium     | Pilot test key systems before full-scale implementation and have support channels available to address unexpected issues.                                                |
| Market conditions and user expectations remain stable    | Assumption    | Low        | Monitor the external environment periodically and adjust project goals only if significant changes are detected; otherwise, assume a stable baseline for planning.  |


<br>

## Key Performance Indicators (KPIs)  

### Documents  
This section tracks the progress of essential project documents:  
- **Functional Specification**  
- **Technical Specification**  
- **Test Plan**  
- **Test Cases**  
- **User Manual**  

**Formula:**  

<div align="center">

$$\text{Progress (\%)} = \frac{\text{Current Number of Completed Sections}}{\text{Total Predefined Sections}} \times 100$$ 

</div>

Where:  
- **Current Number of Completed Sections** = Fully completed and validated sections  
- **Total Predefined Sections** = Sections outlined at the start, subject to minor adjustments  
<br>

## Development  
Key software development KPIs include:  
- **API Backend & Implementation**  
- **Data Checking & Integrity Validation**  
- **Graph Data Structure Implementation**  
- **Algorithm Design for Pathfinding**  

**Formula:**  

<div align="center">

$$\text{Progress (\%)} = \frac{(\text{Completed Tasks} + \sum \text{Partial Progress on Ongoing Tasks})}{\text{Total Tasks Planned}} \times 100$$  

</div>


Where:  
- **Completed Tasks** = Fully developed and tested components  
- **Partial Progress on Ongoing Tasks** = Estimated completion level of in-progress features  

<br>

## Performance & Quality  
This section includes:  
- **Performance Optimization**  
- **Memory Consumption Optimization**  
- **Bug Fixing**  
- **Test Suite Development**  

### Defect Detection Efficiency (DDE)  
Measures the effectiveness of testing in identifying defects before release.  

**Formula:**

<div align="center">

$$\text{DDE (\%)} = \frac{\text{Defects Detected During Testing}}{\text{Total Number of Defects}} \times 100$$  

</div>

### Bug Fix Rate  
Measures the percentage of reported bugs that have been resolved.  

**Formula:**  

<div align="center">

$$\text{Bug Fix Rate (\%)} = \frac{\text{Fixed Bugs}}{\text{Total Reported Bugs}} \times 100$$  

</div>

<br>

## Human Resources  
To monitor the efficiency and well-being of the team, we track:  
- **Overtime Hours**  
- **Unjustified Absences**  
- **Team Mood**  

### Team Mood Score 
Measures team morale based on weekly self-assessments.  

**Formula:**  

<div align="center">

$$\text{Mood Score} = \frac{\sum \text{Individual Mood Ratings}}{\text{Total Team Members}}$$  

</div>

Mood is measured weekly on a scale of 1 to 10.  

---

By applying these KPIs and their respective formulas, we ensure a structured, data-driven approach to project management, allowing for real-time progress tracking and informed decision-making.  


The complete KPI document can be accessed via this [link](https://spark-vessel-8f5.notion.site/KPIs-177204fa4816806ca08fe59365d99d74?pvs=4).  
Additionally, a comprehensive visual presentation highlighting all project achievements is available [here](https://docs.google.com/spreadsheets/d/1O52cw3Ta-6EVw85Rz4RBrDvwIUuy__FmBcQSuzbgIPo/edit?usp=sharing).

<br>

## Weekly report

Each week, a meeting was held that informed the creation of these weekly reports, giving me a clear overview of our progress and ensuring we remain on track.

you can access to them via these links :

- [Weekly Report 1](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/weekly_report_1.md)
- [Weekly Report 2](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/weekly_report_2.md)
- [Weekly Report 3](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/weekly_report_3.md)
- [Weekly Report 4](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/weekly_report_4.md)
- [Weekly Report 5](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/weekly_report_5.md)
- [Weekly Report 6](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/weekly_report_6.md)


Also a cumulative document to access to all of them in one single page was made to centralize every meeting's results :

[Cumulative document for the 6 weeks](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/blob/main/documents/Management/weeklyReport.md/cumulative.md)