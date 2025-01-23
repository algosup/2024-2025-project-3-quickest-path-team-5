
### 2. Setting up the Environment:

To run the software, you need a C++ compiler installed on your system. Follow these steps:

1. **Windows (Install MinGW)**  
   MinGW is a lightweight tool to compile C++ code.  
   - Download it from this link: [MinGW Download](https://ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html).  

2. **Mac (Install GCC)**  
   Use Homebrew, a package manager for Mac, to install the compiler.  
   - Open Terminal.  
   - Run this command to install GCC:  

     ```bash
     brew install gcc
     ```

   *(If Homebrew isn’t installed, follow the instructions here: [Homebrew](https://brew.sh/))*

3. **Install CMake (Recommended)**:

    CMake is a tool that simplifies the compilation of complex projects.

      - **Download CMake:**  
      Visit the official website: [cmake.org/download](https://cmake.org/download)  
      Download and install the version suitable for your system (Windows, Mac, Linux).

### 3. Compile the Software

- **Step 1: Navigate to the Project Folder**
  
    Use the `cd` command to go to the folder where you downloaded the software.
  
    ```bash
      cd /path/to/your/folder/2024-2025-project-3-quickest-path-team-5
    ```

    ![Navigate to Project Folder](images/path-folder.png)

- **Step 2: Create a Build Directory**
  
    Create a separate folder for the build process.

    ```bash
      mkdir build && cd build
    ```

    ![Create Build Directory](images/build-directory.png)

- **Step 3: Generate Makefiles and Build the Software**
  
    Use CMake to generate the necessary build files and then compile the software using `make`.

    ```bash
      cmake .. && make
    ```

    ![Generate Makefiles and Build](images/cmake-makefiles.png)

- **Step 4: Run the Program**
  
    Once compiled, you can run the program.

    ```bash
      ./dgv
    ```

    ![Run Program](images/run-program.png)

- **Tip:**
    If you prefer not to use CMake, ensure the project includes a Makefile or other build instructions.
