# Codex - Python-based Management Plugin
Welcome to Codex, your go-to solution for managing and executing Python-based scripts within [x64dbg](https://x64dbg.com/)! Codex is an innovative plugin designed to streamline your workflow in x64dbg. It offers a seamless way to store and execute Python-based solutions directly from the disassembler context menu and the x64dbg top plugins menu.

### Key Features
* Effortless Integration: Codex seamlessly integrates with x64dbg, offering a user-friendly interface to manage and execute Python scripts.
* Quick Access Execution: Execute Python-based solutions with just a few clicks, enhancing your debugging efficiency.
* Flexible Configuration: Customize menu items, folder structures, and script names to match your workflow.

### Requirements
To harness the power of Codex, ensure you have the following components:

* Windows Operating System
    * Visual Studio 2015
    * [Visual C++ Redistributable for Visual Studio 2015](https://www.microsoft.com/en-US/download/details.aspx?id=48145)
    * [Microsoft .NET Framework 4](https://www.microsoft.com/en-US/download/details.aspx?id=17718)
* x64dbgpy Plugin
    * Python 2.7 (PyQt4, PyQt5, and PySide)

### Getting Started
0. Install x64dbgpy and ensure PyQt4, PyQt5, and PySide are located within `"...\plugins\x64dbgpy\".`
1. Clone the Codex repository to your local machine using your preferred method, such as Git CLI or a GUI client.
2. Navigate to the cloned repository folder and locate the "x64dbg.plugin.codex.sln" solution file. Double-click it to open it in Visual Studio 2015.
3. Once the solution is open, you might need to configure the build settings to match your environment:
    1. Select your desired build mode (e.g., Debug or Release).
    2. Choose the targeted platform (x86 or x64) based on your system architecture.
4. Build the solution by clicking the "Build" menu at the top and selecting "Build Solution" or by pressing Ctrl + Shift + B. Visual Studio will compile the project and generate the necessary binaries.
5. After the build process completes successfully, navigate to the "build" folder within the repository directory. You should find the built binaries and any associated files generated during the build.
6. Copy the built binaries to your x64dbg plugin directory.
7. Create a directory called `codex`.
8. Create a `settings.json` file in your x64dbg plugin `codex` directory.
9. Edit the settings in `"...\plugins\codex\settings.json"` to customize menu items and organize scripts. Follow the example template below for reference.


### Simplified Context Menus

Codex brings simplicity to your workflow by providing context menus accessible both on the general menu bar and the disassembly window. This enables you to seamlessly manage and execute your Python-based scripts right where you need them.

#### Menu Bar Context

Easily access and execute your favorite scripts through the menu bar. Codex integrates directly into the menu structure, offering a straightforward way to enhance your debugging capabilities.

#### Disassembly Window Context

When deep-diving into disassembly, Codex ensures your scripts are just a click away. The disassembly window context menu gives you quick access to script execution, reducing the time spent switching between tools.

Now you can work more efficiently and focus on what matters most: solving intricate debugging challenges.

### Configuration and Usage
* Edit the settings in `"...\plugins\codex\settings.json"` to customize menu items and organize scripts.
* You can create nested folders, making organization a breeze.
* Simplify script names for a clearer understanding of their purpose.
* Each script can import and use additional files, enhancing versatility.

#### Example
To get an idea of how to apply Codex to best fit your needs, check out my featured demo script's `settings.json` structure:

```json
{
    "settings": {
        "scripts": {
            "menu": [
                {"folder": "Oreans", "name": "OEP Finder (Universal)", "file": "oreans_oep_finder_uni.py"}
            ],
            "disassembly": [
                {"folder": "Deobfuscate", "name": "PUSH/POP -> MOV", "file": "push_pop.py"}
            ]
        }
    }
}
```

### License
This project operates under the [Apache License 2.0 (Apache-2.0)](https://tldrlegal.com/license/apache-license-2.0-(apache-2.0)). Please refer to the [LICENSE.md](./LICENSE.md) file for detailed information.

### Your Feedback Counts

Your insights and feedback, whether positive or constructive, are immensely valuable. Your contributions guide the refinement of the Codex Plugin for future iterations.

Share your thoughts by opening an issue in the [repository's issue section](https://github.com/dovezp/x64dbg.plugin.codex/issues). Be sure to provide context and links when sharing your feedback.

Thank you for being an essential part of the Codex Plugin's growth journey.

<p align="center">
  <p align="center">
    <a href="https://hits.seeyoufarm.com/api/count/graph/dailyhits.svg?url=https://github.com/dovezp/x64dbg.plugin.codex">
      <img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fdovezp%2Fx64dbg.plugin.codex&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=true" alt="repository hits">
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/releases">
      <img src="https://img.shields.io/github/downloads/dovezp/x64dbg.plugin.codex/total?style=flat-square" alt="downloads"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/graphs/contributors">
      <img src="https://img.shields.io/github/contributors/dovezp/x64dbg.plugin.codex?style=flat-square" alt="contributors"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/watchers">
      <img src="https://img.shields.io/github/watchers/dovezp/x64dbg.plugin.codex?style=flat-square" alt="watchers"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/stargazers">
      <img src="https://img.shields.io/github/stars/dovezp/x64dbg.plugin.codex?style=flat-square" alt="stars"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/network/members">
      <img src="https://img.shields.io/github/forks/dovezp/x64dbg.plugin.codex?style=flat-square" alt="forks"/>
    </a>
  </p>
</p>

<p align="center">
  <a href="https://github.com/dovezp">
    <img width="64" heigth="64" src="https://avatars.githubusercontent.com/u/89095890" alt="dovezp"/>
  </a>
</p>
