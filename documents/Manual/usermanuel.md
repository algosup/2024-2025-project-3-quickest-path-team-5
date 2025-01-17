# User manual
---

| Name | date |
|------|------|
|Alexandre Bopp| 1/13/2025 |

<img src="https://img.freepik.com/vecteurs-premium/concept-systeme-gps-mobile-interface-application-gps-mobile-carte-ecran-du-telephone-marqueurs-itineraire_257312-619.jpg" alt="GPS Navigation" height="400" width="100%" style="display: block; margin: auto; object-fit:cover;">

---

## Overview
This user manual provides guidance on how to operate and interact with the Quickest Path Calculator software. Designed for users across various domains, this software calculates the fastest road between two landmarks in the United States using a large dataset of connected nodes. Its primary application is for planning trips, optimizing travel, and reporting travel times.

### Purpose of the Software
The purpose of the Quickest Path Calculator is to simplify road optimization by providing:
- Accurate Travel Times: Calculating the fastest road between two points using efficient algorithms.
- User-Friendly Operation: A straightforward interface requiring only the input of source and destination landmarks.
- Versatile Application: Suitable for business, logistics, personal travel planning, and research purposes.
- The focus is on pre-trip planning rather than live navigation, ensuring a highly performant, offline-first solution.

### Intended Users
This software is built for a variety of users, including:

- Business Travelers: Professionals who need to calculate optimal roads for reporting mileage and saving time.
- Planners: Individuals or teams managing logistics and delivery schedules across the United States.
- Vacationers: People planning leisure trips who want to ensure they take the quickest road between destinations.
- Developers and Researchers: Those exploring pathfinding algorithms or using the software as a base for similar  applications.
- This tool is not a real-time GPS and is not designed for tracking live locations but serves as a pre-trip planning solution to determine roads efficiently.

## Requirements
To use the Quickest Path Calculator, your device and setup must meet the following basic and system requirements:

### Basic Requirements
To interact with the software, you will need:
- Keyboard: For inputting source and destination landmarks.
- Mouse: To navigate through the software interface.
- PC or Laptop: A device capable of running the software. Both desktop and laptop configurations are supported.
- Access to electricity/battery.
- Network: Required only for initial setup if the dataset is downloaded online.

### Minimum System Configuration
The following minimum specifications are required to ensure smooth operation of the software:

#### Windows Configuration
- Operating System: Windows 10 or later.
- Processor: Intel Core i3(8th Gen) or AMD equivalent.
- RAM: 4 GB minimum.
- Storage: 100 MB of free space for software installation and dataset.
- Graphics: Integrated graphics card (no high-end GPU required).

#### Mac Configuration
- Operating System: macOS Mojave (10.14) or later.
- Processor: Apple M1 or Intel Core i5.
- RAM: 4 GB minimum.
- Storage: 100 MB of free space for software installation and dataset.
- Graphics: Integrated graphics card.

## Installation 

<img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAASIAAACuCAMAAAClZfCTAAAAdVBMVEX///8AAAD19fX7+/vq6upAQEAtLS0mJiYaGhr39/e+vr7CwsLy8vJJSUne3t75+flMTEzIyMhwcHC2trYhISGKioqQkJDW1tY9PT02Njbm5uZERETPz89ra2uEhIQWFhZ9fX1bW1uhoaFSUlJjY2OkpKQODg7TouAaAAAELElEQVR4nO2d6WKqMBBGjYgVr2gVd621te37P+KtkkBYB2wChHznL+JMDsskIehgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACG4DhtZ9BxRtfT6XpsO4sucxyzX17gqJgVe/DWdh7dxTuEisZe25l0luE4VPQybDuTzgJFJFBEAkUkUEQCRSRQRAJFJFBEAkUkUEQCRSRQRAJFJFBEAkUkUEQCRSRQRAJFJFBEAkUkUEQCRSRQRAJFJFBEAkUkUEQCRSRQRAJFJFBEAkUkUEQCRSRQRAJFJFBEAkWcxTI452+hFJ2DpRUv0czvS/Q/ctfnlyvyPn437ed6s+sCzvphwc07HUoVOafHtp/+v/wQhBaYu8huK1O0OPEdP/Xn2DIb3lJ2ynooUTQUhtiliSxb5VM0lfmz9LZiRbPXaLf+n0WjqK3sNe2oUJFkiI2ayrQ9/sWt9VMqihR5frzPv+YybQ/JUaquFShyTvEe0yYzbY9CR/mKLDSUdCTbyFU0dC27ykLk+5F0z85TJN+prTmH7kiOpLqWo8haQ0lHkZCsoqG9hhKOTmIsklG06Ped+rzdLsu259S1tKLKtWy53RbMr3SZt8e9uGx6R3YUDt9TijzJUGktu90/8aUs9Yb4DltWOubM1LWkopnUpy49h/jI2LTBG/9pC1b6oal0z747SiiqXsv4h8bqsm+Ed553+Sx0qvbLiqob8vin3g2btJ1UUpSoa56syKt6lcWKJv1UlKxrC6HIG7iVDfVeUeI8mokf5xnV6Q/1XpHsaB9O/bP1oYYhCxTJdS1LhT61BYrk8+gJQ1YoKnZUaVxmhaIiR9VGrnYoyndUcWxviaI8R1VnP2xRlK1rleeHrFGUdlR9Bs0eRclrrcYco0WKZEd1ZmFtUhQ7qjVPbZUi4ajeTL5digbL3wHsoeYzV8sUDZz5PGf5Wim2KXqChaGKxNx1AwumZjzUu/5QShGTYg2sAT7yUGv9oZTy8Uz5fg7RVbjpD6WUC897oz/Uloe66g+lFP40lrn6Q4lHAd/6QyllLjrK2m9GzUVSzQ9PXPtK8mitu+5AyrmKUqy57I9ED2ylN44GduLgXvXGEYeCGbjAaC9y17rMdSmiHHRG0YR4ZYj9aPyLoaPoxbNAXxBtONFpdMi8D6OKWRzDsAFaSHQNsIOm82gUP/s3dNH6KmoAK10Y+izxMTD2v7CG67gNK+W1fyYdgYm2S1k3OyZxUdr7nV/k796p/OpmST4b8zfT3XH0Z4676cZPfLGJ1SwiYA1g2vg1Ren6KjUY/+bDbk038i9MDL4PCbwV3c7neevHz4ss93RTn2Ovpb/VCoFPN7c+vtGVLMP54tJtrsP+YuDsB4EzDzZfN9/9M/7taxPUfmZrDo4C2m4DAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHD+A0lvKViFAVBXAAAAAElFTkSuQmCC" alt="GPS Navigation" width="200" style="display: block; margin: auto;">

Need to be completed more in detail ( example : go by the link here)

### Step 1: Download the Software
Visit the official software download page (e.g., [Insert URL or specify source]).
Download the installer file for your operating system:
For Windows: QuickestPathInstaller.exe
For macOS: QuickestPathInstaller.dmg

### Step 2: Install the Software
Windows Installation
Locate the downloaded installer file (QuickestPathInstaller.exe) and double-click it to run.
Follow the on-screen instructions:
Accept the license agreement.
Choose an installation directory or proceed with the default directory.
Click "Install" and wait for the installation to complete.
Once finished, click "Finish" to close the installer.
Mac Installation
Locate the downloaded file (QuickestPathInstaller.dmg) and double-click it to open.
Drag and drop the software icon into the Applications folder.
Navigate to the Applications folder and double-click the software icon to launch it.
If prompted with a security warning, go to System Preferences > Security & Privacy and click "Open Anyway."

### Step 3: Initial Setup
Launch the software by clicking on its icon.
On the first run, the software will prompt you to load the dataset (USA-roads.csv):
Click Browse to locate the dataset file.
Select the file and click Load.
Once the dataset is loaded, you will see a confirmation message.

### Step 4: Verify Installation
To ensure the installation was successful, input two test landmarks (e.g., IDs for "New York" and "Los Angeles") and verify that the software calculates the quickest path within one second.
If any issues arise, refer to the troubleshooting section.